# Benchmarking Floating Point Performance of Massively Parallel Dataflow Overlays on AMD Versal FPGA Compute Primitives

This repository contains the code base for the benchmarking model presented in the study **"Benchmarking Floating Point Performance of Massively Parallel Dataflow Overlays on AMD Versal FPGA Compute Primitives"**. It evaluates the practical limit performance of floating-point multiplication pipelined across multiple stages on AMD Versal (VCK5000) FP primitives through DSP58 and AIE and is used for comparison against AMD UltraScale+ (Alveo U280) FP primitives through DSP48E2.

## Repository Structure

The repository is organized into three folders, each representing a distinct experimental setup:

1. **AIE_Versal**
   - This folder contains the implementation for a design using 384 AIEs (AI Engines) on AMD Versal devices.
   - Each AIE is configured as an 8-lane SIMD multiplier.

2. **PL_Versal_DSP58**
   - This folder contains the implementation for a design using AMD Versal DSP58s.
   - DSP58 are used to implement 8-lane SIMD multipliers, with 1 DSP per multiplication.

3. **PL_UltraScalePlus_DSP48E2**
   - This folder contains the implementation for a design using AMD UltraScale+ DSP48E2s.
   - DSP48E2 are used to implement 8-lane SIMD multipliers, with 3 DSP per multiplication.

## Tools and Hardware

- **AMD Vitis and Vitis HLS Version**: 2022.1
- **FPGA Boards**:
  - AMD Versal ACAP VCK5000
  - AMD UltraScale+ Alveo U280

## How to Use
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-name>
   ```
2. Navigate to the desired folder (e.g., `AIE_Versal`, `PL_Versal_DSP58`, or `PL_UltraScalePlus_DSP48E2`) to access the corresponding experimental setup.
3. Run the ``make all`` command on each experiment to build the required design point (might take a few hours per each).


## License
This project is licensed under the MIT License.

## Contact
For any questions or issues, please reach out to Mohamed Bouaziz at [mohamed.bouaziz@kaust.edu.sa].

