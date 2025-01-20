def generate_code(SIZE,PE,PACKET_CARRIER):
    code = """#include <gmp.h>
#define __gmp_const const

#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include "../common/common.h"

#define TB

typedef ap_uint<256> data_t8;

extern "C"
{
    void pl_mm2s(data_t8 *A, data_t8 *B, """
    for i in range(PACKET_CARRIER):
        code += f'                 hls::stream<ap_axiu<32, 0, 0, 0>> &sA{i},'
        if (i % 8 == 0) : code += f'\n'
    for i in range(PACKET_CARRIER):
        code += f'                 hls::stream<ap_axiu<32, 0, 0, 0>> &sB{i}'
        if (i < PACKET_CARRIER - 1): code += ','
        else: code += ');\n'
        if (i % 8 == 0) : code += f'\n'
    code += """}

int main()
{
    data_t8 A[SIZE / 8], B[SIZE / 8];

    for (auto i = 0; i < SIZE / 8; i++)
    {
        for (auto j = 0; j < 8; j++)
        {
            A[i](32 * (j + 1) - 1, 32 * j) = i * 8 + j;
            B[i](32 * (j + 1) - 1, 32 * j) = i * 8 + j;
        }
    }"""
        
    for i in range(PACKET_CARRIER):
        code += f'                 hls::stream<ap_axiu<32, 0, 0, 0>> sA{i};\n'        
    for i in range(PACKET_CARRIER):
        code += f'                 hls::stream<ap_axiu<32, 0, 0, 0>> sB{i};\n' 

    code += """    pl_mm2s(A, B, """
    for i in range(PACKET_CARRIER):
        code += f'                 sA{i},'
        if (i % 8 == 0) : code += f'\n'
    for i in range(PACKET_CARRIER):
        code += f'                 sB{i}'
        if (i < PACKET_CARRIER - 1): code += ','
        else: code += ');\n'
        if (i % 8 == 0) : code += f'\n'
    code += """
    int err = 0;

    for (auto row = 0; row < rows_per_packet; row++)
    {"""
        
    for i in range(PACKET_CARRIER):
        code += f'                 ap_axiu<32, 0, 0, 0> xA{i} = sA{i}.read();\n'        
    for i in range(PACKET_CARRIER):
        code += f'                 ap_axiu<32, 0, 0, 0> xB{i} = sB{i}.read();\n'    
            
    for i in range(PACKET_CARRIER):
        code += """        if (xA__IDX__.data(4, 0) != xB__IDX__.data(4, 0))
        {
            std::cout << "Detected problem with channel __IDX__ on row " << row << std::endl;
            err++;
        }\n""".replace("__IDX__", str(i))
    code += """
        for (auto i = 0; i < __SIMD*PIPELINE__; i++)
        {""".replace("__SIMD*PIPELINE__", str(int(SIZE/PE)))
    for i in range(PACKET_CARRIER):
        code += """
            xA__IDX__ = sA__IDX__.read();
            xB__IDX__ = sB__IDX__.read();
            if (xA__IDX__.data != xB__IDX__.data)
            {
                std::cout << "Detected problem with channel __IDX__ on segment " << i << std::endl;
                err++;
                std::cout << "Values are " << xA__IDX__.data << " " << xB__IDX__.data << std::endl;
            }""".replace("__IDX__", str(i))
    code +="""
        }
    }
    if (err > 0)
        return -1;
    return 0;
}"""

    return code

SIZE = 512
sc = False
COLS = 64
cc = False
ROWS = 64
rc = False
common_file = open("../common/common.h")
data_common_file = common_file.readlines()
for line in data_common_file:
    if "COLS" in line:
        if (not(cc)) :
            COLS = int(line.split(" ")[2])
            cc = True
    if "ROWS" in line:
        if (not(rc)) :
            ROWS = int(line.split(" ")[2])
            rc = True
    if "SIZE" in line:
        if (not(sc)) :
            SIZE = int(line.split(" ")[2])
            sc = True

PE = COLS*ROWS
PACKET_CARRIER = COLS * 2
# Example usage:
generated_code = generate_code(SIZE,PE,PACKET_CARRIER)
mm2s_tb_file = open("mm2s_tb.cpp", "w")
mm2s_tb_file.write(generated_code)
