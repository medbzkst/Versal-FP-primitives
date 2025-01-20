#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <iomanip>
#include "../common/common.h"

#include "xrt.h"
#include "experimental/xrt_kernel.h"

#include <iostream>
#include <string>
#include <filesystem>
#include <regex>

#if defined(_WIN32)
#include <windows.h>
#else
#include <unistd.h>
#include <limits.h>
#endif

namespace fs = std::filesystem;

std::string getExecutablePath()
{
    char result[PATH_MAX];
#if defined(_WIN32)
    GetModuleFileName(NULL, result, MAX_PATH);
#else
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    if (count == -1)
    {
        throw std::runtime_error("Failed to read the executable path");
    }
#endif
    return std::string(result);
}

std::string getParentDirectoryName(const std::string &path, int levels_up)
{
    fs::path p = path;
    for (int i = 0; i < levels_up; ++i)
    {
        p = p.parent_path();
    }
    return p.filename().string();
}

void appendToCSV(const std::string &filePath, const std::string &num1, const std::string &num2, double value)
{
    std::ofstream file;
    file.open(filePath, std::ios_base::app);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open the CSV file");
    }
    file << num1 << ", " << num2 << ", " << value << "\n";
    file.close();
}

int main(int argc, char **argv)
{

    // Check input arguments
    if (argc < 2 || argc > 4)
    {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File> <#elements(optional)> <debug(optional)>" << std::endl;
        return EXIT_FAILURE;
    }
    unsigned int num_elements = SIZE;
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
    auto kernel_1 = xrt::kernel(device, uuid, "kernel0:{kernel_1}");

    // Allocating the input size of sizeIn to MM2S
    std::cout << "Allocate Buffer in Global Memory" << std::endl;
    size_t size_in_bytes = sizeof(float) * (num_elements);
    auto in_buff_1 = xrt::bo(device, size_in_bytes, kernel_1.group_id(0));
    // auto in_buff_2 = xrt::bo(device, size_in_bytes, pl_mm2s_2.group_id(0));
    auto in_buff_2 = xrt::bo(device, size_in_bytes, kernel_1.group_id(1));
    auto out_buff_1 = xrt::bo(device, size_in_bytes, kernel_1.group_id(2));

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
    xrt::run kernel_1_run(kernel_1);
    kernel_1_run.set_arg(0, in_buff_1);
    kernel_1_run.set_arg(1, in_buff_2);
    kernel_1_run.set_arg(2, out_buff_1);
    kernel_1_run.set_arg(3, num_elements);
    for (auto x = 0; x < 10; x++) // JUST A WARM UP
    {
        kernel_1_run.start();
        kernel_1_run.wait();
    }
    std::chrono::duration<double> fpga_duration = std::chrono::nanoseconds::zero();
    for (auto x = 0; x < 100; x++)
    {
        auto fpga_begin = std::chrono::high_resolution_clock::now();
        kernel_1_run.start();

        // Wait for kernels to complete
        kernel_1_run.wait();
        auto fpga_end = std::chrono::high_resolution_clock::now();
        fpga_duration += fpga_end - fpga_begin;
    }
    std::cout << "kernel_1 completed in " << fpga_duration.count() / 100 << " s" << std::endl;

    try
    {
        std::string execPath = getExecutablePath();
        std::string parentDirName = getParentDirectoryName(execPath, 2); // Get the parent of the parent directory

        std::regex pattern(R"(vmul_PL_(\d+)_(\d+))");
        std::smatch match;
        if (std::regex_search(parentDirName, match, pattern))
        {
            if (match.size() == 3)
            { // Full match and two groups
                std::string num1 = match[1].str();
                std::string num2 = match[2].str();

                std::string csvPath = "/home/bouazim/autosa_gen/BZ_expr/AIESources/some_experiments/PLsVCK/execs.csv";
                appendToCSV(csvPath, num2, std::to_string(std::stoi(num1) / std::stoi(num2)), fpga_duration.count() / 100);

                std::cout << "Appended to CSV: " << num2 << ", " << std::to_string(std::stoi(num1) / std::stoi(num2)) << ", " << fpga_duration.count() / 100 << "\n";
            }
            else
            {
                std::cerr << "Error: Pattern did not match expected format\n";
            }
        }
        else
        {
            std::cerr << "Error: Pattern did not match\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    // Synchronize the output buffer data from the device
    std::cout << "Synchronize the output buffer data from the device" << std::endl;
    out_buff_1.sync(XCL_BO_SYNC_BO_FROM_DEVICE);

    // Read output buffer data to local buffer
    out_buff_1.read(DataOutput);

    // Compare results
    int errorCount = 0;
    for (unsigned int i = 0; i < num_elements; i++)
    {
        float golden = DataInput0[i] * DataInput1[i];
        if (DataOutput[i] != golden)
        {
            std::cout << "Error found @ " << std::dec << i;
            std::cout << ", " << DataOutput[i] << " != " << golden << std::endl;
            errorCount++;
        }
        if (debug)
        {
            std::cout << "Idx [" << std::setw(6) << i << "]" << std::setw(14) << DataInput0[i] << " + ";
            std::cout << std::setw(14) << DataInput1[i] << "	sw result" << std::setw(14);
            std::cout << golden << "	hw result" << std::setw(14) << DataOutput[i];
            std::cout << "	equal " << ((golden == DataOutput[i]) ? "True" : "False") << std::endl;
        }
    }
    if (errorCount)
        std::cout << "Test failed with " << std::dec << errorCount << " errors" << std::endl;
    else
        std::cout << "TEST PASSED with " << num_elements << " elements" << std::endl;

    return errorCount;
}