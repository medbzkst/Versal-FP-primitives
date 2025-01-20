def generate_code(SIZE,PE):
    if PE <= 0:
        raise ValueError("Size must be greataer than 1.")
    if SIZE % PE != 0:
        raise ValueError(f"Data size (given {SIZE}) should be a multiple of PE count (given {PE}).")
    if (SIZE / PE) % 8 != 0:
        raise ValueError(f"Data points given to a PE should be a multiple of 8 (Total points {SIZE}, total PEs {PE}, data points per PE {(SIZE / PE)} not multiple of 8).")


    code = f'[connectivity]\n'
    code += f'nk=pl_mm2s:1:pl_mm2s_1\n'
    code += f'nk=pl_s2mm:1:pl_s2mm_1\n\n'

    for i in range(PE) :
        code += f'stream_connect = pl_mm2s_1.sA{i}:ai_engine_0.StreamIn0_{i}\n'
        code += f'stream_connect = pl_mm2s_1.sB{i}:ai_engine_0.StreamIn1_{i}\n'
        code += f'stream_connect = ai_engine_0.StreamOut0_{i}:pl_s2mm_1.s{i}\n\n'
    return code

SIZE = 64
sc = False
COLS = 8
cc = False
packet_per_col = 2
pc = False
common_file = open("../common/common.h")
data_common_file = common_file.readlines()
for line in data_common_file:
    if "COLS" in line:
        if (not(sc)) :
            COLS = int(line.split(" ")[2])
            sc = True
    if "SIZE" in line:
        if (not(cc)) :
            SIZE = int(line.split(" ")[2])
            cc = True
    if "ROWS" in line:
        if (not(pc)) :
            packet_per_col = int(int(line.split(" ")[2]) / 4)
            pc = True

# Example usage:
generated_code = generate_code(SIZE,COLS*packet_per_col)
config_file = open("config.cfg", "w")
config_file.write(generated_code)
