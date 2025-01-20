PLATFORM := xilinx_vck5000_gen4x8_xdma_2_202210_1
TARGET := hw
FREQ := 250

XSA = $(strip $(patsubst %.xpfm, % , $(shell basename $(PLATFORM))))
JOBS = 48

BUILD_DIR = build.$(TARGET)
VPP_FLAGS = -t $(TARGET) --platform $(PLATFORM)# --save-temps
VPP_FLAGS += --kernel_frequency $(FREQ)
VPP_FLAGS += -I ../common/
VPP_FLAGS += -I /usr/include/
VPP_FLAGS += --hls.jobs $(JOBS)

all: $(BUILD_DIR)/pl_mm2s.xo $(BUILD_DIR)/pl_s2mm.xo

$(BUILD_DIR)/pl_mm2s.xo: gen_pl_mm2s.py
# rm -f $(subst $(BUILD_DIR)/,,$(subst .xo,,$@)).cpp
# /usr/bin/python3 $^
	v++ $(VPP_FLAGS) -k $(subst $(BUILD_DIR)/,,$(subst .xo,,$@)) -c -g -o $@ $(subst $(BUILD_DIR)/,,$(subst .xo,,$@)).cpp

$(BUILD_DIR)/pl_s2mm.xo: gen_pl_s2mm.py
# rm -f $(subst $(BUILD_DIR)/,,$(subst .xo,,$@)).cpp
# /usr/bin/python3 $^
	v++ $(VPP_FLAGS) -k $(subst $(BUILD_DIR)/,,$(subst .xo,,$@)) -c -g -o $@ $(subst $(BUILD_DIR)/,,$(subst .xo,,$@)).cpp

clean:
	rm -rf $(BUILD_DIR) *.log *.jou .Xil/ _x/
