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
                 hls::stream<ap_uint<32>> &s7,
                 hls::stream<ap_uint<32>> &s8,
                 hls::stream<ap_uint<32>> &s9,
                 hls::stream<ap_uint<32>> &s10,
                 hls::stream<ap_uint<32>> &s11,
                 hls::stream<ap_uint<32>> &s12,
                 hls::stream<ap_uint<32>> &s13,
                 hls::stream<ap_uint<32>> &s14,
                 hls::stream<ap_uint<32>> &s15,
                 hls::stream<ap_uint<32>> &s16,
                 hls::stream<ap_uint<32>> &s17,
                 hls::stream<ap_uint<32>> &s18,
                 hls::stream<ap_uint<32>> &s19,
                 hls::stream<ap_uint<32>> &s20,
                 hls::stream<ap_uint<32>> &s21,
                 hls::stream<ap_uint<32>> &s22,
                 hls::stream<ap_uint<32>> &s23,
                 hls::stream<ap_uint<32>> &s24,
                 hls::stream<ap_uint<32>> &s25,
                 hls::stream<ap_uint<32>> &s26,
                 hls::stream<ap_uint<32>> &s27,
                 hls::stream<ap_uint<32>> &s28,
                 hls::stream<ap_uint<32>> &s29,
                 hls::stream<ap_uint<32>> &s30,
                 hls::stream<ap_uint<32>> &s31,
                 hls::stream<ap_uint<32>> &s32,
                 hls::stream<ap_uint<32>> &s33,
                 hls::stream<ap_uint<32>> &s34,
                 hls::stream<ap_uint<32>> &s35,
                 hls::stream<ap_uint<32>> &s36,
                 hls::stream<ap_uint<32>> &s37,
                 hls::stream<ap_uint<32>> &s38,
                 hls::stream<ap_uint<32>> &s39,
                 hls::stream<ap_uint<32>> &s40,
                 hls::stream<ap_uint<32>> &s41,
                 hls::stream<ap_uint<32>> &s42,
                 hls::stream<ap_uint<32>> &s43,
                 hls::stream<ap_uint<32>> &s44,
                 hls::stream<ap_uint<32>> &s45,
                 hls::stream<ap_uint<32>> &s46,
                 hls::stream<ap_uint<32>> &s47,
                 hls::stream<ap_uint<32>> &s48,
                 hls::stream<ap_uint<32>> &s49,
                 hls::stream<ap_uint<32>> &s50,
                 hls::stream<ap_uint<32>> &s51,
                 hls::stream<ap_uint<32>> &s52,
                 hls::stream<ap_uint<32>> &s53,
                 hls::stream<ap_uint<32>> &s54,
                 hls::stream<ap_uint<32>> &s55,
                 hls::stream<ap_uint<32>> &s56,
                 hls::stream<ap_uint<32>> &s57,
                 hls::stream<ap_uint<32>> &s58,
                 hls::stream<ap_uint<32>> &s59,
                 hls::stream<ap_uint<32>> &s60,
                 hls::stream<ap_uint<32>> &s61,
                 hls::stream<ap_uint<32>> &s62,
                 hls::stream<ap_uint<32>> &s63);
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
                 hls::stream<ap_uint<32>> &s7,
                 hls::stream<ap_uint<32>> &s8,
                 hls::stream<ap_uint<32>> &s9,
                 hls::stream<ap_uint<32>> &s10,
                 hls::stream<ap_uint<32>> &s11,
                 hls::stream<ap_uint<32>> &s12,
                 hls::stream<ap_uint<32>> &s13,
                 hls::stream<ap_uint<32>> &s14,
                 hls::stream<ap_uint<32>> &s15,
                 hls::stream<ap_uint<32>> &s16,
                 hls::stream<ap_uint<32>> &s17,
                 hls::stream<ap_uint<32>> &s18,
                 hls::stream<ap_uint<32>> &s19,
                 hls::stream<ap_uint<32>> &s20,
                 hls::stream<ap_uint<32>> &s21,
                 hls::stream<ap_uint<32>> &s22,
                 hls::stream<ap_uint<32>> &s23,
                 hls::stream<ap_uint<32>> &s24,
                 hls::stream<ap_uint<32>> &s25,
                 hls::stream<ap_uint<32>> &s26,
                 hls::stream<ap_uint<32>> &s27,
                 hls::stream<ap_uint<32>> &s28,
                 hls::stream<ap_uint<32>> &s29,
                 hls::stream<ap_uint<32>> &s30,
                 hls::stream<ap_uint<32>> &s31,
                 hls::stream<ap_uint<32>> &s32,
                 hls::stream<ap_uint<32>> &s33,
                 hls::stream<ap_uint<32>> &s34,
                 hls::stream<ap_uint<32>> &s35,
                 hls::stream<ap_uint<32>> &s36,
                 hls::stream<ap_uint<32>> &s37,
                 hls::stream<ap_uint<32>> &s38,
                 hls::stream<ap_uint<32>> &s39,
                 hls::stream<ap_uint<32>> &s40,
                 hls::stream<ap_uint<32>> &s41,
                 hls::stream<ap_uint<32>> &s42,
                 hls::stream<ap_uint<32>> &s43,
                 hls::stream<ap_uint<32>> &s44,
                 hls::stream<ap_uint<32>> &s45,
                 hls::stream<ap_uint<32>> &s46,
                 hls::stream<ap_uint<32>> &s47,
                 hls::stream<ap_uint<32>> &s48,
                 hls::stream<ap_uint<32>> &s49,
                 hls::stream<ap_uint<32>> &s50,
                 hls::stream<ap_uint<32>> &s51,
                 hls::stream<ap_uint<32>> &s52,
                 hls::stream<ap_uint<32>> &s53,
                 hls::stream<ap_uint<32>> &s54,
                 hls::stream<ap_uint<32>> &s55,
                 hls::stream<ap_uint<32>> &s56,
                 hls::stream<ap_uint<32>> &s57,
                 hls::stream<ap_uint<32>> &s58,
                 hls::stream<ap_uint<32>> &s59,
                 hls::stream<ap_uint<32>> &s60,
                 hls::stream<ap_uint<32>> &s61,
                 hls::stream<ap_uint<32>> &s62,
                 hls::stream<ap_uint<32>> &s63)
    {
       data_mover_output:
        for (auto i = 0; i < 16; i++)
        {
            ap_uint<32> x0 = s0.read();
            ap_uint<32> x1 = s1.read();
            ap_uint<32> x2 = s2.read();
            ap_uint<32> x3 = s3.read();
            ap_uint<32> x4 = s4.read();
            ap_uint<32> x5 = s5.read();
            ap_uint<32> x6 = s6.read();
            ap_uint<32> x7 = s7.read();
            C[8*i+0] = (x7, x6, x5, x4, x3, x2, x1, x0);
            ap_uint<32> x8 = s8.read();
            ap_uint<32> x9 = s9.read();
            ap_uint<32> x10 = s10.read();
            ap_uint<32> x11 = s11.read();
            ap_uint<32> x12 = s12.read();
            ap_uint<32> x13 = s13.read();
            ap_uint<32> x14 = s14.read();
            ap_uint<32> x15 = s15.read();
            C[8*i+1] = (x15, x14, x13, x12, x11, x10, x9, x8);
            ap_uint<32> x16 = s16.read();
            ap_uint<32> x17 = s17.read();
            ap_uint<32> x18 = s18.read();
            ap_uint<32> x19 = s19.read();
            ap_uint<32> x20 = s20.read();
            ap_uint<32> x21 = s21.read();
            ap_uint<32> x22 = s22.read();
            ap_uint<32> x23 = s23.read();
            C[8*i+2] = (x23, x22, x21, x20, x19, x18, x17, x16);
            ap_uint<32> x24 = s24.read();
            ap_uint<32> x25 = s25.read();
            ap_uint<32> x26 = s26.read();
            ap_uint<32> x27 = s27.read();
            ap_uint<32> x28 = s28.read();
            ap_uint<32> x29 = s29.read();
            ap_uint<32> x30 = s30.read();
            ap_uint<32> x31 = s31.read();
            C[8*i+3] = (x31, x30, x29, x28, x27, x26, x25, x24);
            ap_uint<32> x32 = s32.read();
            ap_uint<32> x33 = s33.read();
            ap_uint<32> x34 = s34.read();
            ap_uint<32> x35 = s35.read();
            ap_uint<32> x36 = s36.read();
            ap_uint<32> x37 = s37.read();
            ap_uint<32> x38 = s38.read();
            ap_uint<32> x39 = s39.read();
            C[8*i+4] = (x39, x38, x37, x36, x35, x34, x33, x32);
            ap_uint<32> x40 = s40.read();
            ap_uint<32> x41 = s41.read();
            ap_uint<32> x42 = s42.read();
            ap_uint<32> x43 = s43.read();
            ap_uint<32> x44 = s44.read();
            ap_uint<32> x45 = s45.read();
            ap_uint<32> x46 = s46.read();
            ap_uint<32> x47 = s47.read();
            C[8*i+5] = (x47, x46, x45, x44, x43, x42, x41, x40);
            ap_uint<32> x48 = s48.read();
            ap_uint<32> x49 = s49.read();
            ap_uint<32> x50 = s50.read();
            ap_uint<32> x51 = s51.read();
            ap_uint<32> x52 = s52.read();
            ap_uint<32> x53 = s53.read();
            ap_uint<32> x54 = s54.read();
            ap_uint<32> x55 = s55.read();
            C[8*i+6] = (x55, x54, x53, x52, x51, x50, x49, x48);
            ap_uint<32> x56 = s56.read();
            ap_uint<32> x57 = s57.read();
            ap_uint<32> x58 = s58.read();
            ap_uint<32> x59 = s59.read();
            ap_uint<32> x60 = s60.read();
            ap_uint<32> x61 = s61.read();
            ap_uint<32> x62 = s62.read();
            ap_uint<32> x63 = s63.read();
            C[8*i+7] = (x63, x62, x61, x60, x59, x58, x57, x56);
        }
    }
}
