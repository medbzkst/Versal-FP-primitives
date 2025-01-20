
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
#pragma HLS INTERFACE m_axi port = A offset = slave bundle = gmem_A depth = 64
#pragma HLS INTERFACE s_axilite port = A bundle = control
#pragma HLS INTERFACE m_axi port = B offset = slave bundle = gmem_B depth = 64
#pragma HLS INTERFACE s_axilite port = B bundle = control
#pragma HLS INTERFACE m_axi port = C offset = slave bundle = gmem_C depth = 64
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
        hls::stream<ap_uint<32>> sA8;
        hls::stream<ap_uint<32>> sA9;
        hls::stream<ap_uint<32>> sA10;
        hls::stream<ap_uint<32>> sA11;
        hls::stream<ap_uint<32>> sA12;
        hls::stream<ap_uint<32>> sA13;
        hls::stream<ap_uint<32>> sA14;
        hls::stream<ap_uint<32>> sA15;
        hls::stream<ap_uint<32>> sA16;
        hls::stream<ap_uint<32>> sA17;
        hls::stream<ap_uint<32>> sA18;
        hls::stream<ap_uint<32>> sA19;
        hls::stream<ap_uint<32>> sA20;
        hls::stream<ap_uint<32>> sA21;
        hls::stream<ap_uint<32>> sA22;
        hls::stream<ap_uint<32>> sA23;
        hls::stream<ap_uint<32>> sA24;
        hls::stream<ap_uint<32>> sA25;
        hls::stream<ap_uint<32>> sA26;
        hls::stream<ap_uint<32>> sA27;
        hls::stream<ap_uint<32>> sA28;
        hls::stream<ap_uint<32>> sA29;
        hls::stream<ap_uint<32>> sA30;
        hls::stream<ap_uint<32>> sA31;

        hls::stream<ap_uint<32>> sB0;
        hls::stream<ap_uint<32>> sB1;
        hls::stream<ap_uint<32>> sB2;
        hls::stream<ap_uint<32>> sB3;
        hls::stream<ap_uint<32>> sB4;
        hls::stream<ap_uint<32>> sB5;
        hls::stream<ap_uint<32>> sB6;
        hls::stream<ap_uint<32>> sB7;
        hls::stream<ap_uint<32>> sB8;
        hls::stream<ap_uint<32>> sB9;
        hls::stream<ap_uint<32>> sB10;
        hls::stream<ap_uint<32>> sB11;
        hls::stream<ap_uint<32>> sB12;
        hls::stream<ap_uint<32>> sB13;
        hls::stream<ap_uint<32>> sB14;
        hls::stream<ap_uint<32>> sB15;
        hls::stream<ap_uint<32>> sB16;
        hls::stream<ap_uint<32>> sB17;
        hls::stream<ap_uint<32>> sB18;
        hls::stream<ap_uint<32>> sB19;
        hls::stream<ap_uint<32>> sB20;
        hls::stream<ap_uint<32>> sB21;
        hls::stream<ap_uint<32>> sB22;
        hls::stream<ap_uint<32>> sB23;
        hls::stream<ap_uint<32>> sB24;
        hls::stream<ap_uint<32>> sB25;
        hls::stream<ap_uint<32>> sB26;
        hls::stream<ap_uint<32>> sB27;
        hls::stream<ap_uint<32>> sB28;
        hls::stream<ap_uint<32>> sB29;
        hls::stream<ap_uint<32>> sB30;
        hls::stream<ap_uint<32>> sB31;

        hls::stream<ap_uint<32>> sC0;
        hls::stream<ap_uint<32>> sC1;
        hls::stream<ap_uint<32>> sC2;
        hls::stream<ap_uint<32>> sC3;
        hls::stream<ap_uint<32>> sC4;
        hls::stream<ap_uint<32>> sC5;
        hls::stream<ap_uint<32>> sC6;
        hls::stream<ap_uint<32>> sC7;
        hls::stream<ap_uint<32>> sC8;
        hls::stream<ap_uint<32>> sC9;
        hls::stream<ap_uint<32>> sC10;
        hls::stream<ap_uint<32>> sC11;
        hls::stream<ap_uint<32>> sC12;
        hls::stream<ap_uint<32>> sC13;
        hls::stream<ap_uint<32>> sC14;
        hls::stream<ap_uint<32>> sC15;
        hls::stream<ap_uint<32>> sC16;
        hls::stream<ap_uint<32>> sC17;
        hls::stream<ap_uint<32>> sC18;
        hls::stream<ap_uint<32>> sC19;
        hls::stream<ap_uint<32>> sC20;
        hls::stream<ap_uint<32>> sC21;
        hls::stream<ap_uint<32>> sC22;
        hls::stream<ap_uint<32>> sC23;
        hls::stream<ap_uint<32>> sC24;
        hls::stream<ap_uint<32>> sC25;
        hls::stream<ap_uint<32>> sC26;
        hls::stream<ap_uint<32>> sC27;
        hls::stream<ap_uint<32>> sC28;
        hls::stream<ap_uint<32>> sC29;
        hls::stream<ap_uint<32>> sC30;
        hls::stream<ap_uint<32>> sC31;

#pragma HLS STREAM variable = sA0 depth = 2
#pragma HLS STREAM variable = sA1 depth = 2
#pragma HLS STREAM variable = sA2 depth = 2
#pragma HLS STREAM variable = sA3 depth = 2
#pragma HLS STREAM variable = sA4 depth = 2
#pragma HLS STREAM variable = sA5 depth = 2
#pragma HLS STREAM variable = sA6 depth = 2
#pragma HLS STREAM variable = sA7 depth = 2
#pragma HLS STREAM variable = sA8 depth = 2
#pragma HLS STREAM variable = sA9 depth = 2
#pragma HLS STREAM variable = sA10 depth = 2
#pragma HLS STREAM variable = sA11 depth = 2
#pragma HLS STREAM variable = sA12 depth = 2
#pragma HLS STREAM variable = sA13 depth = 2
#pragma HLS STREAM variable = sA14 depth = 2
#pragma HLS STREAM variable = sA15 depth = 2
#pragma HLS STREAM variable = sA16 depth = 2
#pragma HLS STREAM variable = sA17 depth = 2
#pragma HLS STREAM variable = sA18 depth = 2
#pragma HLS STREAM variable = sA19 depth = 2
#pragma HLS STREAM variable = sA20 depth = 2
#pragma HLS STREAM variable = sA21 depth = 2
#pragma HLS STREAM variable = sA22 depth = 2
#pragma HLS STREAM variable = sA23 depth = 2
#pragma HLS STREAM variable = sA24 depth = 2
#pragma HLS STREAM variable = sA25 depth = 2
#pragma HLS STREAM variable = sA26 depth = 2
#pragma HLS STREAM variable = sA27 depth = 2
#pragma HLS STREAM variable = sA28 depth = 2
#pragma HLS STREAM variable = sA29 depth = 2
#pragma HLS STREAM variable = sA30 depth = 2
#pragma HLS STREAM variable = sA31 depth = 2
#pragma HLS STREAM variable = sB0 depth = 2
#pragma HLS STREAM variable = sB1 depth = 2
#pragma HLS STREAM variable = sB2 depth = 2
#pragma HLS STREAM variable = sB3 depth = 2
#pragma HLS STREAM variable = sB4 depth = 2
#pragma HLS STREAM variable = sB5 depth = 2
#pragma HLS STREAM variable = sB6 depth = 2
#pragma HLS STREAM variable = sB7 depth = 2
#pragma HLS STREAM variable = sB8 depth = 2
#pragma HLS STREAM variable = sB9 depth = 2
#pragma HLS STREAM variable = sB10 depth = 2
#pragma HLS STREAM variable = sB11 depth = 2
#pragma HLS STREAM variable = sB12 depth = 2
#pragma HLS STREAM variable = sB13 depth = 2
#pragma HLS STREAM variable = sB14 depth = 2
#pragma HLS STREAM variable = sB15 depth = 2
#pragma HLS STREAM variable = sB16 depth = 2
#pragma HLS STREAM variable = sB17 depth = 2
#pragma HLS STREAM variable = sB18 depth = 2
#pragma HLS STREAM variable = sB19 depth = 2
#pragma HLS STREAM variable = sB20 depth = 2
#pragma HLS STREAM variable = sB21 depth = 2
#pragma HLS STREAM variable = sB22 depth = 2
#pragma HLS STREAM variable = sB23 depth = 2
#pragma HLS STREAM variable = sB24 depth = 2
#pragma HLS STREAM variable = sB25 depth = 2
#pragma HLS STREAM variable = sB26 depth = 2
#pragma HLS STREAM variable = sB27 depth = 2
#pragma HLS STREAM variable = sB28 depth = 2
#pragma HLS STREAM variable = sB29 depth = 2
#pragma HLS STREAM variable = sB30 depth = 2
#pragma HLS STREAM variable = sB31 depth = 2
#pragma HLS STREAM variable = sC0 depth = 2
#pragma HLS STREAM variable = sC1 depth = 2
#pragma HLS STREAM variable = sC2 depth = 2
#pragma HLS STREAM variable = sC3 depth = 2
#pragma HLS STREAM variable = sC4 depth = 2
#pragma HLS STREAM variable = sC5 depth = 2
#pragma HLS STREAM variable = sC6 depth = 2
#pragma HLS STREAM variable = sC7 depth = 2
#pragma HLS STREAM variable = sC8 depth = 2
#pragma HLS STREAM variable = sC9 depth = 2
#pragma HLS STREAM variable = sC10 depth = 2
#pragma HLS STREAM variable = sC11 depth = 2
#pragma HLS STREAM variable = sC12 depth = 2
#pragma HLS STREAM variable = sC13 depth = 2
#pragma HLS STREAM variable = sC14 depth = 2
#pragma HLS STREAM variable = sC15 depth = 2
#pragma HLS STREAM variable = sC16 depth = 2
#pragma HLS STREAM variable = sC17 depth = 2
#pragma HLS STREAM variable = sC18 depth = 2
#pragma HLS STREAM variable = sC19 depth = 2
#pragma HLS STREAM variable = sC20 depth = 2
#pragma HLS STREAM variable = sC21 depth = 2
#pragma HLS STREAM variable = sC22 depth = 2
#pragma HLS STREAM variable = sC23 depth = 2
#pragma HLS STREAM variable = sC24 depth = 2
#pragma HLS STREAM variable = sC25 depth = 2
#pragma HLS STREAM variable = sC26 depth = 2
#pragma HLS STREAM variable = sC27 depth = 2
#pragma HLS STREAM variable = sC28 depth = 2
#pragma HLS STREAM variable = sC29 depth = 2
#pragma HLS STREAM variable = sC30 depth = 2
#pragma HLS STREAM variable = sC31 depth = 2

#pragma HLS DATAFLOW

        pl_mm2s(A, 
                sA0, sA1, sA2, sA3, sA4, sA5, sA6, sA7, sA8, sA9, sA10, sA11, sA12, sA13, sA14, sA15, sA16, sA17, sA18, sA19, sA20, sA21, sA22, sA23, sA24, sA25, sA26, sA27, sA28, sA29, sA30, sA31);
        pl_mm2s(B,
                sB0, sB1, sB2, sB3, sB4, sB5, sB6, sB7, sB8, sB9, sB10, sB11, sB12, sB13, sB14, sB15, sB16, sB17, sB18, sB19, sB20, sB21, sB22, sB23, sB24, sB25, sB26, sB27, sB28, sB29, sB30, sB31);
        multiply(sA0, sB0, sC0);
        multiply(sA1, sB1, sC1);
        multiply(sA2, sB2, sC2);
        multiply(sA3, sB3, sC3);
        multiply(sA4, sB4, sC4);
        multiply(sA5, sB5, sC5);
        multiply(sA6, sB6, sC6);
        multiply(sA7, sB7, sC7);
        multiply(sA8, sB8, sC8);
        multiply(sA9, sB9, sC9);
        multiply(sA10, sB10, sC10);
        multiply(sA11, sB11, sC11);
        multiply(sA12, sB12, sC12);
        multiply(sA13, sB13, sC13);
        multiply(sA14, sB14, sC14);
        multiply(sA15, sB15, sC15);
        multiply(sA16, sB16, sC16);
        multiply(sA17, sB17, sC17);
        multiply(sA18, sB18, sC18);
        multiply(sA19, sB19, sC19);
        multiply(sA20, sB20, sC20);
        multiply(sA21, sB21, sC21);
        multiply(sA22, sB22, sC22);
        multiply(sA23, sB23, sC23);
        multiply(sA24, sB24, sC24);
        multiply(sA25, sB25, sC25);
        multiply(sA26, sB26, sC26);
        multiply(sA27, sB27, sC27);
        multiply(sA28, sB28, sC28);
        multiply(sA29, sB29, sC29);
        multiply(sA30, sB30, sC30);
        multiply(sA31, sB31, sC31);
        pl_s2mm(C,
                sC0, sC1, sC2, sC3, sC4, sC5, sC6, sC7, sC8, sC9, sC10, sC11, sC12, sC13, sC14, sC15, sC16, sC17, sC18, sC19, sC20, sC21, sC22, sC23, sC24, sC25, sC26, sC27, sC28, sC29, sC30, sC31);
    }
}   
