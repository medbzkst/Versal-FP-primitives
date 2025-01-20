
#include <gmp.h>
#define __gmp_const const

#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

#include "multiply.hpp"
#include "pl_mm2s.hpp"
#include "pl_s2mm.hpp"

extern "C"
{
    void kernel0(data_t8 *A, data_t8 *B, data_t8 *C, int size)
    {
#pragma HLS INTERFACE m_axi port = A offset = slave bundle = gmem_A
#pragma HLS INTERFACE s_axilite port = A bundle = control
#pragma HLS INTERFACE m_axi port = B offset = slave bundle = gmem_B
#pragma HLS INTERFACE s_axilite port = B bundle = control
#pragma HLS INTERFACE m_axi port = C offset = slave bundle = gmem_C
#pragma HLS INTERFACE s_axilite port = C bundle = control
#pragma HLS INTERFACE s_axilite port = return bundle = control
#pragma HLS INTERFACE s_axilite port = size bundle = control

#pragma HLS STABLE variable = A
#pragma HLS STABLE variable = B
#pragma HLS STABLE variable = C

        hls::stream<data_t8> sA0;

        hls::stream<data_t8> sB0;

        hls::stream<data_t8> sC0;

#pragma HLS STREAM variable = sA0 depth = 2
#pragma HLS STREAM variable = sB0 depth = 2
#pragma HLS STREAM variable = sC0 depth = 2

#pragma HLS DATAFLOW

        pl_mm2s(A, 
                sA0, size);
        pl_mm2s(B,
                sB0, size);
        multiply(sA0, sB0, sC0, size);
        pl_s2mm(C,
                sC0, size);
    }
}   
