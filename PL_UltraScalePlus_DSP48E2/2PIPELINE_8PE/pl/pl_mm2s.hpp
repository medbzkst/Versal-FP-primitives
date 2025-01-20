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
                 hls::stream<ap_uint<32>> &sA7);
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
                 hls::stream<ap_uint<32>> &sA7)
    {
       data_mover_input:
        for (auto i = 0; i < 16; i++)
        {
            data_t8 fu;
            fu = A[1*i+0];

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

        }
    }
}
