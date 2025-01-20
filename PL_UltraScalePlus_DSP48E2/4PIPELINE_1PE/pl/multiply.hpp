#ifndef __MULTIPLY_HPP__
#define __MULTIPLY_HPP__

#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include "../common/common.h"

union Punner
{
    ap_uint<256> i = 0;
    struct {float d7, d6, d5, d4, d3, d2, d1, d0;} flos;
};

extern "C"
{
    void multiply(
        hls::stream<ap_uint<256>> &sA,
        hls::stream<ap_uint<256>> &sB,
        hls::stream<ap_uint<256>> &sC,
        int size);
}

void multiplier(
    hls::stream<float> &a,
    hls::stream<float> &b,
    hls::stream<float> &c)
{
#pragma HLS INLINE OFF
    float res;
#pragma HLS BIND_OP variable = res op = fmul impl = maxdsp latency = 4
    res = a.read() * b.read();

    c.write(res);
}

void surjector(hls::stream<ap_uint<256>> &sA,
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
    Punner a_lanes;

    a_lanes.i = sA.read();

    a_lane0.write(a_lanes.flos.d0);

    a_lane1.write(a_lanes.flos.d1);

    a_lane2.write(a_lanes.flos.d2);

    a_lane3.write(a_lanes.flos.d3);

    a_lane4.write(a_lanes.flos.d4);

    a_lane5.write(a_lanes.flos.d5);

    a_lane6.write(a_lanes.flos.d6);

    a_lane7.write(a_lanes.flos.d7);
}

void injector(hls::stream<ap_uint<256>> &sC,
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
    Punner c_lanes;
    c_lanes.flos.d0 = c_lane0.read();

    c_lanes.flos.d1 = c_lane1.read();

    c_lanes.flos.d2 = c_lane2.read();

    c_lanes.flos.d3 = c_lane3.read();

    c_lanes.flos.d4 = c_lane4.read();

    c_lanes.flos.d5 = c_lane5.read();

    c_lanes.flos.d6 = c_lane6.read();

    c_lanes.flos.d7 = c_lane7.read();
    sC.write(c_lanes.i);
}

extern "C"
{
    void multiply(
        hls::stream<ap_uint<256>> &sA,
        hls::stream<ap_uint<256>> &sB,
        hls::stream<ap_uint<256>> &sC,
        int size)
    {

        for (auto i = 0; i < size; i++)
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
    