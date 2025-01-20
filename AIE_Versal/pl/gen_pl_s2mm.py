def generate_code(SIZE,PE,PACKET_CARRIER):
    if PE <= 0:
        raise ValueError("Size must be greataer than 1.")
    if SIZE % PE != 0:
        raise ValueError(f"Data size (given {SIZE}) should be a multiple of PE count (given {PE}).")
    if (SIZE / PE) % 8 != 0:
        raise ValueError(f"Data points given to a PE should be a multiple of 8 (Total points {SIZE}, total PEs {PE}, data points per PE {(SIZE / PE)} not multiple of 8).")

    code = f'#include <ap_int.h>\n'
    code += f'#include <hls_stream.h>\n'
    code += f'#include <ap_axi_sdata.h>\n'
    code += f'#include "../common/common.h"\n\n'

    code += f'typedef ap_uint<256> data_t8;\n\n'

    code += 'extern "C"\n{\n\n'
    code += '    void pl_s2mm(data_t8 *C,\n'
    for i in range(PACKET_CARRIER):
        code += f'                 hls::stream<ap_axiu<32, 0, 0, 0>> &s{i}'
        if (i < PACKET_CARRIER - 1): code += ',\n'
        else: code += ')\n'
    code += '    {\n'
    code += f'#pragma HLS INTERFACE m_axi port = C offset = slave bundle = gmem_C\n'
    code += '#pragma HLS INTERFACE s_axilite port = C bundle = control\n'
    for i in range(PACKET_CARRIER):
        code += f'#pragma HLS INTERFACE axis port = s{i}\n'
    code += '#pragma HLS INTERFACE s_axilite port = return bundle = control\n'
    
    code += '       data_mover_C:\n'
    code += '        for (auto row = 0; row < rows_per_packet; row++)\n'
    code += '        {\n'
    code += f'#pragma HLS PIPELINE II = {int(PACKET_CARRIER)}\n'
    for i in range(int(PACKET_CARRIER)):
        code += f"        s{i}.read(); //get rid of the header\n"
    code += f'          for (auto i = 0; i < {int(SIZE / PE)}; i++)\n'
    code += '           {\n'
    for i in range(int(PACKET_CARRIER/8)):
        for j in range(8):
            code += f'              ap_axiu<32, 0, 0, 0> x{i*8+j} = s{i*8+j}.read();\n'
        code += f'              C[rows_per_packet * ({int(PACKET_CARRIER/8)}*i+{i}) + row] = (x{i*8+7}.data, x{i*8+6}.data, x{i*8+5}.data, x{i*8+4}.data, x{i*8+3}.data, x{i*8+2}.data, x{i*8+1}.data, x{i*8+0}.data);\n'
    code += '           }\n'
    code += '        }\n'

    code += '    }\n'
    code += '}\n'

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
s2mm_file = open("pl_s2mm.cpp", "w")
s2mm_file.write(generated_code)
