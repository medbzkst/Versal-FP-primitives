#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include "../common/common.h"

typedef ap_uint<256> data_t8;

extern "C"
{

    void pl_mm2s(data_t8 *A,
                 hls::stream<ap_uint<32>> &sA0,
                 hls::stream<ap_uint<32>> &sA1,
                 hls::stream<ap_uint<32>> &sA2,
                 hls::stream<ap_uint<32>> &sA3,
                 hls::stream<ap_uint<32>> &sA4,
                 hls::stream<ap_uint<32>> &sA5,
                 hls::stream<ap_uint<32>> &sA6,
                 hls::stream<ap_uint<32>> &sA7,
                 hls::stream<ap_uint<32>> &sA8,
                 hls::stream<ap_uint<32>> &sA9,
                 hls::stream<ap_uint<32>> &sA10,
                 hls::stream<ap_uint<32>> &sA11,
                 hls::stream<ap_uint<32>> &sA12,
                 hls::stream<ap_uint<32>> &sA13,
                 hls::stream<ap_uint<32>> &sA14,
                 hls::stream<ap_uint<32>> &sA15,
                 hls::stream<ap_uint<32>> &sA16,
                 hls::stream<ap_uint<32>> &sA17,
                 hls::stream<ap_uint<32>> &sA18,
                 hls::stream<ap_uint<32>> &sA19,
                 hls::stream<ap_uint<32>> &sA20,
                 hls::stream<ap_uint<32>> &sA21,
                 hls::stream<ap_uint<32>> &sA22,
                 hls::stream<ap_uint<32>> &sA23,
                 hls::stream<ap_uint<32>> &sA24,
                 hls::stream<ap_uint<32>> &sA25,
                 hls::stream<ap_uint<32>> &sA26,
                 hls::stream<ap_uint<32>> &sA27,
                 hls::stream<ap_uint<32>> &sA28,
                 hls::stream<ap_uint<32>> &sA29,
                 hls::stream<ap_uint<32>> &sA30,
                 hls::stream<ap_uint<32>> &sA31);
}
extern "C"
{

    void pl_mm2s(data_t8 *A,
                 hls::stream<ap_uint<32>> &sA0,
                 hls::stream<ap_uint<32>> &sA1,
                 hls::stream<ap_uint<32>> &sA2,
                 hls::stream<ap_uint<32>> &sA3,
                 hls::stream<ap_uint<32>> &sA4,
                 hls::stream<ap_uint<32>> &sA5,
                 hls::stream<ap_uint<32>> &sA6,
                 hls::stream<ap_uint<32>> &sA7,
                 hls::stream<ap_uint<32>> &sA8,
                 hls::stream<ap_uint<32>> &sA9,
                 hls::stream<ap_uint<32>> &sA10,
                 hls::stream<ap_uint<32>> &sA11,
                 hls::stream<ap_uint<32>> &sA12,
                 hls::stream<ap_uint<32>> &sA13,
                 hls::stream<ap_uint<32>> &sA14,
                 hls::stream<ap_uint<32>> &sA15,
                 hls::stream<ap_uint<32>> &sA16,
                 hls::stream<ap_uint<32>> &sA17,
                 hls::stream<ap_uint<32>> &sA18,
                 hls::stream<ap_uint<32>> &sA19,
                 hls::stream<ap_uint<32>> &sA20,
                 hls::stream<ap_uint<32>> &sA21,
                 hls::stream<ap_uint<32>> &sA22,
                 hls::stream<ap_uint<32>> &sA23,
                 hls::stream<ap_uint<32>> &sA24,
                 hls::stream<ap_uint<32>> &sA25,
                 hls::stream<ap_uint<32>> &sA26,
                 hls::stream<ap_uint<32>> &sA27,
                 hls::stream<ap_uint<32>> &sA28,
                 hls::stream<ap_uint<32>> &sA29,
                 hls::stream<ap_uint<32>> &sA30,
                 hls::stream<ap_uint<32>> &sA31)
    {
       data_mover_input:
        for (auto i = 0; i < 32; i++)
        {
            data_t8 fu;
            fu = A[4*i+0];

            ap_uint<32> xA0;
            xA0 = fu(32*(0+1)-1,32*0);
            sA0.write(xA0);

            ap_uint<32> xA1;
            xA1 = fu(32*(1+1)-1,32*1);
            sA1.write(xA1);

            ap_uint<32> xA2;
            xA2 = fu(32*(2+1)-1,32*2);
            sA2.write(xA2);

            ap_uint<32> xA3;
            xA3 = fu(32*(3+1)-1,32*3);
            sA3.write(xA3);

            ap_uint<32> xA4;
            xA4 = fu(32*(4+1)-1,32*4);
            sA4.write(xA4);

            ap_uint<32> xA5;
            xA5 = fu(32*(5+1)-1,32*5);
            sA5.write(xA5);

            ap_uint<32> xA6;
            xA6 = fu(32*(6+1)-1,32*6);
            sA6.write(xA6);

            ap_uint<32> xA7;
            xA7 = fu(32*(7+1)-1,32*7);
            sA7.write(xA7);

            fu = A[4*i+1];

            ap_uint<32> xA8;
            xA8 = fu(32*(0+1)-1,32*0);
            sA8.write(xA8);

            ap_uint<32> xA9;
            xA9 = fu(32*(1+1)-1,32*1);
            sA9.write(xA9);

            ap_uint<32> xA10;
            xA10 = fu(32*(2+1)-1,32*2);
            sA10.write(xA10);

            ap_uint<32> xA11;
            xA11 = fu(32*(3+1)-1,32*3);
            sA11.write(xA11);

            ap_uint<32> xA12;
            xA12 = fu(32*(4+1)-1,32*4);
            sA12.write(xA12);

            ap_uint<32> xA13;
            xA13 = fu(32*(5+1)-1,32*5);
            sA13.write(xA13);

            ap_uint<32> xA14;
            xA14 = fu(32*(6+1)-1,32*6);
            sA14.write(xA14);

            ap_uint<32> xA15;
            xA15 = fu(32*(7+1)-1,32*7);
            sA15.write(xA15);

            fu = A[4*i+2];

            ap_uint<32> xA16;
            xA16 = fu(32*(0+1)-1,32*0);
            sA16.write(xA16);

            ap_uint<32> xA17;
            xA17 = fu(32*(1+1)-1,32*1);
            sA17.write(xA17);

            ap_uint<32> xA18;
            xA18 = fu(32*(2+1)-1,32*2);
            sA18.write(xA18);

            ap_uint<32> xA19;
            xA19 = fu(32*(3+1)-1,32*3);
            sA19.write(xA19);

            ap_uint<32> xA20;
            xA20 = fu(32*(4+1)-1,32*4);
            sA20.write(xA20);

            ap_uint<32> xA21;
            xA21 = fu(32*(5+1)-1,32*5);
            sA21.write(xA21);

            ap_uint<32> xA22;
            xA22 = fu(32*(6+1)-1,32*6);
            sA22.write(xA22);

            ap_uint<32> xA23;
            xA23 = fu(32*(7+1)-1,32*7);
            sA23.write(xA23);

            fu = A[4*i+3];

            ap_uint<32> xA24;
            xA24 = fu(32*(0+1)-1,32*0);
            sA24.write(xA24);

            ap_uint<32> xA25;
            xA25 = fu(32*(1+1)-1,32*1);
            sA25.write(xA25);

            ap_uint<32> xA26;
            xA26 = fu(32*(2+1)-1,32*2);
            sA26.write(xA26);

            ap_uint<32> xA27;
            xA27 = fu(32*(3+1)-1,32*3);
            sA27.write(xA27);

            ap_uint<32> xA28;
            xA28 = fu(32*(4+1)-1,32*4);
            sA28.write(xA28);

            ap_uint<32> xA29;
            xA29 = fu(32*(5+1)-1,32*5);
            sA29.write(xA29);

            ap_uint<32> xA30;
            xA30 = fu(32*(6+1)-1,32*6);
            sA30.write(xA30);

            ap_uint<32> xA31;
            xA31 = fu(32*(7+1)-1,32*7);
            sA31.write(xA31);

        }
    }
}
