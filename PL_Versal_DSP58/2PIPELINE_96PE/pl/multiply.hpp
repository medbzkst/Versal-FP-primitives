#ifndef __MULTIPLY_HPP__
#define __MULTIPLY_HPP__

#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include "../common/common.h"

union Punner
{
    ap_uint<32> i = 0;
    float d;
};

extern "C"
{
    void multiply(
        hls::stream<ap_uint<32>> &sA,
        hls::stream<ap_uint<32>> &sB,
        hls::stream<ap_uint<32>> &sC);
}

void multiplier(
    hls::stream<float> &a,
    hls::stream<float> &b,
    hls::stream<float> &c)
{
#pragma HLS INLINE OFF
    float res;
#pragma HLS BIND_OP variable = res op = fmul impl = primitivedsp latency = 2
    res = a.read() * b.read();

    c.write(res);
}

void surjector(hls::stream<ap_uint<32>> &sA,
               hls::stream<float> &a_lane0,
               hls::stream<float> &a_lane1,
               hls::stream<float> &a_lane2,
               hls::stream<float> &a_lane3,
               hls::stream<float> &a_lane4,
               hls::stream<float> &a_lane5,
               hls::stream<float> &a_lane6,
               hls::stream<float> &a_lane7)
{
#pragma HLS INLINE OFF
    Punner a_lanes[8];

    a_lanes[0].i = sA.read();
    a_lane0.write(a_lanes[0].d);
    a_lanes[1].i = sA.read();
    a_lane1.write(a_lanes[1].d);
    a_lanes[2].i = sA.read();
    a_lane2.write(a_lanes[2].d);
    a_lanes[3].i = sA.read();
    a_lane3.write(a_lanes[3].d);
    a_lanes[4].i = sA.read();
    a_lane4.write(a_lanes[4].d);
    a_lanes[5].i = sA.read();
    a_lane5.write(a_lanes[5].d);
    a_lanes[6].i = sA.read();
    a_lane6.write(a_lanes[6].d);
    a_lanes[7].i = sA.read();
    a_lane7.write(a_lanes[7].d);
}

void injector(hls::stream<ap_uint<32>> &sC,
              hls::stream<float> &c_lane0,
              hls::stream<float> &c_lane1,
              hls::stream<float> &c_lane2,
              hls::stream<float> &c_lane3,
              hls::stream<float> &c_lane4,
              hls::stream<float> &c_lane5,
              hls::stream<float> &c_lane6,
              hls::stream<float> &c_lane7)
{
#pragma HLS INLINE OFF
    Punner c_lanes[8];
    c_lanes[0].d = c_lane0.read();
    sC.write(c_lanes[0].i);
    c_lanes[1].d = c_lane1.read();
    sC.write(c_lanes[1].i);
    c_lanes[2].d = c_lane2.read();
    sC.write(c_lanes[2].i);
    c_lanes[3].d = c_lane3.read();
    sC.write(c_lanes[3].i);
    c_lanes[4].d = c_lane4.read();
    sC.write(c_lanes[4].i);
    c_lanes[5].d = c_lane5.read();
    sC.write(c_lanes[5].i);
    c_lanes[6].d = c_lane6.read();
    sC.write(c_lanes[6].i);
    c_lanes[7].d = c_lane7.read();
    sC.write(c_lanes[7].i);
}

extern "C"
{
    void multiply(
        hls::stream<ap_uint<32>> &sA,
        hls::stream<ap_uint<32>> &sB,
        hls::stream<ap_uint<32>> &sC)
    {

        for (auto i = 0; i < SIZE / PE / 8; i++)
        {
#pragma HLS DATAFLOW
            hls::stream<float> a_lane0;
#pragma HLS STREAM variable = a_lane0 depth = 2
            hls::stream<float> a_lane1;
#pragma HLS STREAM variable = a_lane1 depth = 2
            hls::stream<float> a_lane2;
#pragma HLS STREAM variable = a_lane2 depth = 2
            hls::stream<float> a_lane3;
#pragma HLS STREAM variable = a_lane3 depth = 2
            hls::stream<float> a_lane4;
#pragma HLS STREAM variable = a_lane4 depth = 2
            hls::stream<float> a_lane5;
#pragma HLS STREAM variable = a_lane5 depth = 2
            hls::stream<float> a_lane6;
#pragma HLS STREAM variable = a_lane6 depth = 2
            hls::stream<float> a_lane7;
#pragma HLS STREAM variable = a_lane7 depth = 2
            hls::stream<float> b_lane0;
#pragma HLS STREAM variable = b_lane0 depth = 2
            hls::stream<float> b_lane1;
#pragma HLS STREAM variable = b_lane1 depth = 2
            hls::stream<float> b_lane2;
#pragma HLS STREAM variable = b_lane2 depth = 2
            hls::stream<float> b_lane3;
#pragma HLS STREAM variable = b_lane3 depth = 2
            hls::stream<float> b_lane4;
#pragma HLS STREAM variable = b_lane4 depth = 2
            hls::stream<float> b_lane5;
#pragma HLS STREAM variable = b_lane5 depth = 2
            hls::stream<float> b_lane6;
#pragma HLS STREAM variable = b_lane6 depth = 2
            hls::stream<float> b_lane7;
#pragma HLS STREAM variable = b_lane7 depth = 2
            hls::stream<float> c_lane0;
#pragma HLS STREAM variable = c_lane0 depth = 2
            hls::stream<float> c_lane1;
#pragma HLS STREAM variable = c_lane1 depth = 2
            hls::stream<float> c_lane2;
#pragma HLS STREAM variable = c_lane2 depth = 2
            hls::stream<float> c_lane3;
#pragma HLS STREAM variable = c_lane3 depth = 2
            hls::stream<float> c_lane4;
#pragma HLS STREAM variable = c_lane4 depth = 2
            hls::stream<float> c_lane5;
#pragma HLS STREAM variable = c_lane5 depth = 2
            hls::stream<float> c_lane6;
#pragma HLS STREAM variable = c_lane6 depth = 2
            hls::stream<float> c_lane7;
#pragma HLS STREAM variable = c_lane7 depth = 2

            surjector(sA,
                      a_lane0, a_lane1, a_lane2, a_lane3, a_lane4, a_lane5, a_lane6, a_lane7);
            surjector(sB,
                      b_lane0, b_lane1, b_lane2, b_lane3, b_lane4, b_lane5, b_lane6, b_lane7);
            multiplier(a_lane0, b_lane0, c_lane0);
            multiplier(a_lane1, b_lane1, c_lane1);
            multiplier(a_lane2, b_lane2, c_lane2);
            multiplier(a_lane3, b_lane3, c_lane3);
            multiplier(a_lane4, b_lane4, c_lane4);
            multiplier(a_lane5, b_lane5, c_lane5);
            multiplier(a_lane6, b_lane6, c_lane6);
            multiplier(a_lane7, b_lane7, c_lane7);
            // std::cout << "mult done" << std::endl;

            injector(sC,
                      c_lane0, c_lane1, c_lane2, c_lane3, c_lane4, c_lane5, c_lane6, c_lane7);
        }
    }
}

#endif
    