PLATFORM := xilinx_u280_gen3x16_xdma_1_202211_1
TARGET := hw

XSA = $(strip $(patsubst %.xpfm, % , $(shell basename $(PLATFORM))))
PL_DIR = $(shell readlink -f ./pl)
HOST_DIR = $(shell readlink -f ./host)
HW_LINK = $(shell readlink -f ./pl/config.cfg)

XCLBIN_NAME = vmul
JOBS = 40
FREQ = 350


PACKAGE_FLAGS = -t $(TARGET) --platform $(PLATFORM) --save-temps

VPP_FLAGS = $(PACKAGE_FLAGS)
VPP_FLAGS += -g --optimize 2
VPP_FLAGS += --hls.jobs $(JOBS)
VPP_FLAGS += --config $(HW_LINK)
VPP_FLAGS += --profile.data all:all:all
ifneq (gen3x16,$(findstring gen3x16, $(XSA)))
	VPP_FLAGS += --clock.defaultFreqHz $(shell echo "scale=0;$(FREQ)*1000000/1" | bc)
endif

VPP_LDFLAGS := --vivado.synth.jobs $(JOBS) --vivado.impl.jobs $(JOBS)

BUILD_DIR = build.$(TARGET)
OUTPUT_DIR = $(shell readlink -f ./$(BUILD_DIR))

XO_SRCS = $(PL_DIR)/$(BUILD_DIR)/kernel.xo
HOST_APP = $(HOST_DIR)/$(XCLBIN_NAME).exe

all: $(OUTPUT_DIR)/${XCLBIN_NAME}.xclbin $(HOST_APP)

$(XO_SRCS):
	make -C $(PL_DIR)/ PLATFORM=$(PLATFORM) FREQ=$(FREQ) TARGET=$(TARGET)

$(HOST_APP):
	make -C $(HOST_DIR)

# Building xclbin
$(OUTPUT_DIR)/$(XCLBIN_NAME).xclbin: $(XO_SRCS)
	@echo "### ***** linking pl kernels into $(XCLBIN_NAME).xclbin ... *****"
	sed -i 's/\#nk/nk/' $(HW_LINK);	mkdir -p $(OUTPUT_DIR); 	cd $(OUTPUT_DIR); 	v++ -l $(VPP_FLAGS) 	  --temp_dir _x_temp/ 	  --report_dir reports/ 	  $(VPP_LDFLAGS) 	  $^ 	  -o $@ 2>&1 | tee $(XCLBIN_NAME)_xclbin.log
	@echo "### ***** $(XCLBIN_NAME).xclbin linking done! *****"


clean:
	rm -rf *.log *.jou .Xil/ _x/

distclean: clean
	rm -rf $(BUILD_DIR)