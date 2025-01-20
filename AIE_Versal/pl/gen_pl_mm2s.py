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
    code += f'#include "../aie/build.hw/work/temp/packet_ids_c.h"\n\n'

    code += f'typedef ap_uint<256> data_t8;\n\n'
    code += """ap_uint<32> generateHeader(unsigned int pktType, unsigned int ID){
            ap_uint<32> header=0;
            header(4,0)=ID;
            header(11,5)=0;
            header(14,12)=pktType;
            header[15]=0;
            header(20,16)=-1;//source row
            header(27,21)=-1;//source column
            header(30,28)=0;
            header[31]=header(30,0).xor_reduce()?(ap_uint<1>)0:(ap_uint<1>)1;
            return header;
        }
        """
    code += 'unsigned int packet_ids[__PE__] = {__STREAMS__};'.replace("__PE__", str(3*PE)).replace("__STREAMS__", ",".join([f'StreamIn0_{i}_{j},StreamIn1_{i}_{j},StreamOut0_{i}_{j}' for i in range(PACKET_CARRIER) for j in range(4)]))
    code += 'extern "C"\n{\n\n'
    code += '    void pl_mm2s(data_t8 *A, data_t8 *B,\n'
    for i in range(PACKET_CARRIER):
        code += f'                 hls::stream<ap_axiu<32, 0, 0, 0>> &sA{i},\n'
    for i in range(PACKET_CARRIER):
        code += f'                 hls::stream<ap_axiu<32, 0, 0, 0>> &sB{i}'
        if (i < PACKET_CARRIER - 1): code += ',\n'
        else: code += ')\n'
    code += '    {\n'
    code += f'#pragma HLS INTERFACE m_axi port = A offset = slave bundle = gmem_A\n'
    code += '#pragma HLS INTERFACE s_axilite port = A bundle = control\n'
    code += f'#pragma HLS INTERFACE m_axi port = B offset = slave bundle = gmem_B\n'
    code += '#pragma HLS INTERFACE s_axilite port = B bundle = control\n'
    for i in range(PACKET_CARRIER):
        code += f'#pragma HLS INTERFACE axis port = sA{i}\n'
    for i in range(PACKET_CARRIER):
        code += f'#pragma HLS INTERFACE axis port = sB{i}\n'
    code += '#pragma HLS INTERFACE s_axilite port = return bundle = control\n\n'
    
    
    
    
    code += '       data_mover_A:\n'
    code += '        for (auto row = 0; row < rows_per_packet; row++)\n'
    code += '        {\n'
    code += f'#pragma HLS PIPELINE II = {int(PACKET_CARRIER)}\n'
    for i in range(int(PACKET_CARRIER)):
        code += f"""
            unsigned int ID{i} = packet_ids[(rows_per_packet * {i} + row) * 3 + 0];
            ap_uint<32> header{i} = generateHeader(0, ID{i}); // packet header
            ap_axiu<32, 0, 0, 0> tmp{i};
            tmp{i}.data = header{i};
            tmp{i}.keep = -1;
            tmp{i}.last = 0;
            sA{i}.write(tmp{i});\n"""
    code += f'          for (auto i = 0; i < {int(SIZE / PE)}; i++)\n'
    code += '           {\n'
    code += '               data_t8 fu;\n'
    for i in range(int(PACKET_CARRIER/8)):
        code += f'              fu = A[rows_per_packet * ({int(PACKET_CARRIER/8)}*i+{i}) + row];\n\n'
        for j in range(8):
            code += f'              ap_axiu<32, 0, 0, 0> xA{i*8+j};\n'
            code += f'              xA{i*8+j}.data = fu(32*({j}+1)-1,32*{j});\n'
            code += f'              xA{i*8+j}.last = (i == {int(SIZE / PE) - 1});\n'
            code += f'              sA{i*8+j}.write(xA{i*8+j});\n\n'
    code += '           }\n'
    code += '        }\n'
    
    
    
    code += '       data_mover_B:\n'
    code += '        for (auto row = 0; row < rows_per_packet; row++)\n'
    code += '        {\n'
    code += f'#pragma HLS PIPELINE II = {int(PACKET_CARRIER)}\n'
    for i in range(int(PACKET_CARRIER)):
        code += f"""
            unsigned int ID{i} = packet_ids[(rows_per_packet * {i} + row) * 3 + 1];
            ap_uint<32> header{i} = generateHeader(0, ID{i}); // packet header
            ap_axiu<32, 0, 0, 0> tmp{i};
            tmp{i}.data = header{i};
            tmp{i}.keep = -1;
            tmp{i}.last = 0;
            sB{i}.write(tmp{i});\n"""
    code += f'        for (auto i = 0; i < {int(SIZE / PE)}; i++)\n'
    code += '        {\n'
    code += '            data_t8 fu;\n'
    for i in range(int(PACKET_CARRIER/8)):
        code += f'            fu = B[rows_per_packet * ({int(PACKET_CARRIER/8)}*i+{i}) + row];\n\n'
        for j in range(8):
            code += f'            ap_axiu<32, 0, 0, 0> xB{i*8+j};\n'
            code += f'            xB{i*8+j}.data = fu(32*({j}+1)-1,32*{j});\n'
            code += f'              xB{i*8+j}.last = (i == {int(SIZE / PE) - 1});\n'
            code += f'            sB{i*8+j}.write(xB{i*8+j});\n\n'
    code += '        }\n'
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
mm2s_file = open("pl_mm2s.cpp", "w")
mm2s_file.write(generated_code)
