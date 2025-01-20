
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
    void kernel0(data_t8 *A, data_t8 *B, data_t8 *C)
    {
#pragma HLS INTERFACE m_axi port = A offset = slave bundle = gmem_A depth = 32
#pragma HLS INTERFACE s_axilite port = A bundle = control
#pragma HLS INTERFACE m_axi port = B offset = slave bundle = gmem_B depth = 32
#pragma HLS INTERFACE s_axilite port = B bundle = control
#pragma HLS INTERFACE m_axi port = C offset = slave bundle = gmem_C depth = 32
#pragma HLS INTERFACE s_axilite port = C bundle = control
#pragma HLS INTERFACE s_axilite port = return bundle = control

#pragma HLS STABLE variable = A
#pragma HLS STABLE variable = B
#pragma HLS STABLE variable = C

        hls::stream<ap_uint<32>> sA0;
        hls::stream<ap_uint<32>> sA1;
        hls::stream<ap_uint<32>> sA2;
        hls::stream<ap_uint<32>> sA3;
        hls::stream<ap_uint<32>> sA4;
        hls::stream<ap_uint<32>> sA5;
        hls::stream<ap_uint<32>> sA6;
        hls::stream<ap_uint<32>> sA7;

        hls::stream<ap_uint<32>> sB0;
        hls::stream<ap_uint<32>> sB1;
        hls::stream<ap_uint<32>> sB2;
        hls::stream<ap_uint<32>> sB3;
        hls::stream<ap_uint<32>> sB4;
        hls::stream<ap_uint<32>> sB5;
        hls::stream<ap_uint<32>> sB6;
        hls::stream<ap_uint<32>> sB7;

        hls::stream<ap_uint<32>> sC0;
        hls::stream<ap_uint<32>> sC1;
        hls::stream<ap_uint<32>> sC2;
        hls::stream<ap_uint<32>> sC3;
        hls::stream<ap_uint<32>> sC4;
        hls::stream<ap_uint<32>> sC5;
        hls::stream<ap_uint<32>> sC6;
        hls::stream<ap_uint<32>> sC7;

#pragma HLS STREAM variable = sA0 depth = 2
#pragma HLS STREAM variable = sA1 depth = 2
#pragma HLS STREAM variable = sA2 depth = 2
#pragma HLS STREAM variable = sA3 depth = 2
#pragma HLS STREAM variable = sA4 depth = 2
#pragma HLS STREAM variable = sA5 depth = 2
#pragma HLS STREAM variable = sA6 depth = 2
#pragma HLS STREAM variable = sA7 depth = 2
#pragma HLS STREAM variable = sB0 depth = 2
#pragma HLS STREAM variable = sB1 depth = 2
#pragma HLS STREAM variable = sB2 depth = 2
#pragma HLS STREAM variable = sB3 depth = 2
#pragma HLS STREAM variable = sB4 depth = 2
#pragma HLS STREAM variable = sB5 depth = 2
#pragma HLS STREAM variable = sB6 depth = 2
#pragma HLS STREAM variable = sB7 depth = 2
#pragma HLS STREAM variable = sC0 depth = 2
#pragma HLS STREAM variable = sC1 depth = 2
#pragma HLS STREAM variable = sC2 depth = 2
#pragma HLS STREAM variable = sC3 depth = 2
#pragma HLS STREAM variable = sC4 depth = 2
#pragma HLS STREAM variable = sC5 depth = 2
#pragma HLS STREAM variable = sC6 depth = 2
#pragma HLS STREAM variable = sC7 depth = 2

#pragma HLS DATAFLOW

        pl_mm2s(A, 
                sA0, sA1, sA2, sA3, sA4, sA5, sA6, sA7);
        pl_mm2s(B,
                sB0, sB1, sB2, sB3, sB4, sB5, sB6, sB7);
        multiply(sA0, sB0, sC0);
        multiply(sA1, sB1, sC1);
        multiply(sA2, sB2, sC2);
        multiply(sA3, sB3, sC3);
        multiply(sA4, sB4, sC4);
        multiply(sA5, sB5, sC5);
        multiply(sA6, sB6, sC6);
        multiply(sA7, sB7, sC7);
        pl_s2mm(C,
                sC0, sC1, sC2, sC3, sC4, sC5, sC6, sC7);
    }
}   
