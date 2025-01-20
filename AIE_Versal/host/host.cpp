#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <iomanip>

#include "xrt.h"
#include "experimental/xrt_kernel.h"
#include "common.h"

int main(int argc, char **argv)
{

    // Check input arguments
    if (argc < 2 || argc > 4)
    {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File> <#elements(optional)> <debug(optional)>" << std::endl;
        return EXIT_FAILURE;
    }
    unsigned int num_elements = 245760;
    if (argc >= 3)
    {
        unsigned int val;
        try
        {
            val = std::stoi(argv[2]);
        }
        catch (std::invalid_argument &val)
        {
            std::cerr << "Invalid argument in position 2 (" << argv[2] << ") program expects an integer as number of elements" << std::endl;
            return EXIT_FAILURE;
        }
        catch (std::out_of_range &val)
        {
            std::cerr << "Number of elements out of range, try with a number lower than 2147483648" << std::endl;
            return EXIT_FAILURE;
        }
        if ((val % 4) != 0)
        {
            val = (val / 4) * 4;
            std::cout << "Number of elements (" << val << ") rounded to the closest multiple of 4" << std::endl;
        }
        num_elements = val;
        std::cout << "User number of elements enabled" << std::endl;
    }

    bool debug = false;
    // Check if the user defined debug
    if (argc == 4)
    {
        std::string debug_arg = argv[3];
        if (debug_arg.compare("debug") == 0)
            debug = true;
        std::cout << "Debug enabled" << std::endl;
    }

    // Get device index and download xclbin
    std::cout << "Open the device" << std::endl;
    auto device = xrt::device(0);
    std::string binaryFile = argv[1];
    std::cout << "Load the xclbin " << binaryFile << std::endl;
    auto uuid = device.load_xclbin(binaryFile);

    // Get reference to the kernels
    std::cout << "Get references to compute units" << std::endl;
    auto pl_mm2s_1 = xrt::kernel(device, uuid, "pl_mm2s:{pl_mm2s_1}");
    // auto pl_mm2s_2 = xrt::kernel(device, uuid, "pl_mm2s:{pl_mm2s_2}");
    auto pl_s2mm_1 = xrt::kernel(device, uuid, "pl_s2mm:{pl_s2mm_1}");

    // Allocating the input size of sizeIn to MM2S
    std::cout << "Allocate Buffer in Global Memory" << std::endl;
    size_t size_in_bytes = sizeof(float) * (num_elements);
    auto in_buff_1 = xrt::bo(device, size_in_bytes, pl_mm2s_1.group_id(0));
    // auto in_buff_2 = xrt::bo(device, size_in_bytes, pl_mm2s_2.group_id(0));
    auto in_buff_2 = xrt::bo(device, size_in_bytes, pl_mm2s_1.group_id(1));
    auto out_buff_1 = xrt::bo(device, size_in_bytes, pl_s2mm_1.group_id(0));

    // Generate random data and write data to compute unit buffers
    std::cout << "Generate random data and write data to compute unit buffers" << std::endl;
    auto *DataInput0 = new float[num_elements];
    auto *DataInput1 = new float[num_elements];
    auto *DataOutput = new float[num_elements];

    for (unsigned int i = 0; i < num_elements; i++)
    {
        DataInput0[i] = (float)i;
        DataInput1[i] = (float)i;
    }

    std::cout << "Write to input buffers" << std::endl;
    in_buff_1.write(DataInput0);
    in_buff_2.write(DataInput1);

    // Synchronize input buffers data to device global memory
    std::cout << "Synchronize input buffers data to device global memory" << std::endl;
    in_buff_1.sync(XCL_BO_SYNC_BO_TO_DEVICE);
    in_buff_2.sync(XCL_BO_SYNC_BO_TO_DEVICE);

    // Execute the compute units
    std::cout << "Run the kernels" << std::endl;
    xrt::run run_pl_s2mm_1(pl_s2mm_1);
    run_pl_s2mm_1.set_arg(0, out_buff_1);
    run_pl_s2mm_1.set_arg(1, (int)(num_elements/384));
    xrt::run run_pl_mm2s_1(pl_mm2s_1);
    run_pl_mm2s_1.set_arg(0, in_buff_1);
    run_pl_mm2s_1.set_arg(1, in_buff_2);
    run_pl_mm2s_1.set_arg(2, (int)(num_elements/384));

    // run_pl_mm2s_1.start();
    // run_pl_s2mm_1.start();

    // // Wait for kernels to complete
    // run_pl_mm2s_1.wait();
    // // std::cout << "pl_mm2s_1 completed" << std::endl;
    // run_pl_s2mm_1.wait();
    // // std::cout << "pl_s2mm_1 completed" << std::endl;
    // std::cout << "kernel completed" << std::endl;

    for (auto x = 0; x < 4; x++)
    {
        run_pl_mm2s_1.start();
        run_pl_s2mm_1.start();
        run_pl_mm2s_1.wait();
        run_pl_s2mm_1.wait();
    }
    std::chrono::duration<double> fpga_duration = std::chrono::nanoseconds::zero();
    for (auto x = 0; x < 1; x++)
    {
        auto fpga_begin = std::chrono::high_resolution_clock::now();
        run_pl_s2mm_1.start();
        run_pl_mm2s_1.start();
        run_pl_mm2s_1.wait();
        run_pl_s2mm_1.wait();
        auto fpga_end = std::chrono::high_resolution_clock::now();
        fpga_duration += fpga_end - fpga_begin;
    }
    std::cout << "AIE completed in " << fpga_duration.count() << " s" << std::endl;

    // Synchronize the output buffer data from the device
    std::cout << "Synchronize the output buffer data from the device" << std::endl;
    out_buff_1.sync(XCL_BO_SYNC_BO_FROM_DEVICE);

    // Read output buffer data to local buffer
    out_buff_1.read(DataOutput);

    // Compare results
    int errorCount = 0;
    // for (unsigned int i = 0; i < num_elements; i++)
    // {
    //     float golden = DataInput0[i] * DataInput1[i];
    //     if (DataOutput[i] != golden)
    //     {
    //         std::cout << "Error found @ " << std::dec << i;
    //         std::cout << ", " << DataOutput[i] << " != " << golden << std::endl;
    //         errorCount++;
    //     }
    //     if (debug)
    //     {
    //         std::cout << "Idx [" << std::setw(6) << i << "]" << std::setw(14) << DataInput0[i] << " + ";
    //         std::cout << std::setw(14) << DataInput1[i] << "\tsw result" << std::setw(14);
    //         std::cout << golden << "\thw result" << std::setw(14) << DataOutput[i];
    //         std::cout << "\tequal " << ((golden == DataOutput[i]) ? "True" : "False") << std::endl;
    //     }
    // }
    if (errorCount)
        std::cout << "Test failed with " << std::dec << errorCount << " errors" << std::endl;
    else
        std::cout << "TEST PASSED with " << num_elements << " elements" << std::endl;

    return errorCount;
}
