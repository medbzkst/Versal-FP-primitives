#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include "../common/common.h"

typedef ap_uint<256> data_t8;

extern "C"
{

    void pl_s2mm(data_t8 *C,
                 hls::stream<ap_uint<32>> &s0,
                 hls::stream<ap_uint<32>> &s1,
                 hls::stream<ap_uint<32>> &s2,
                 hls::stream<ap_uint<32>> &s3,
                 hls::stream<ap_uint<32>> &s4,
                 hls::stream<ap_uint<32>> &s5,
                 hls::stream<ap_uint<32>> &s6,
                 hls::stream<ap_uint<32>> &s7);
}
extern "C"
{

    void pl_s2mm(data_t8 *C,
                 hls::stream<ap_uint<32>> &s0,
                 hls::stream<ap_uint<32>> &s1,
                 hls::stream<ap_uint<32>> &s2,
                 hls::stream<ap_uint<32>> &s3,
                 hls::stream<ap_uint<32>> &s4,
                 hls::stream<ap_uint<32>> &s5,
                 hls::stream<ap_uint<32>> &s6,
                 hls::stream<ap_uint<32>> &s7)
    {
       data_mover_output:
        for (auto i = 0; i < 8; i++)
        {
            ap_uint<32> x0 = s0.read();
            ap_uint<32> x1 = s1.read();
            ap_uint<32> x2 = s2.read();
            ap_uint<32> x3 = s3.read();
            ap_uint<32> x4 = s4.read();
            ap_uint<32> x5 = s5.read();
            ap_uint<32> x6 = s6.read();
            ap_uint<32> x7 = s7.read();
            C[1*i+0] = (x7, x6, x5, x4, x3, x2, x1, x0);
        }
    }
}
