
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
#pragma HLS INTERFACE m_axi port = A offset = slave bundle = gmem_A depth = 192
#pragma HLS INTERFACE s_axilite port = A bundle = control
#pragma HLS INTERFACE m_axi port = B offset = slave bundle = gmem_B depth = 192
#pragma HLS INTERFACE s_axilite port = B bundle = control
#pragma HLS INTERFACE m_axi port = C offset = slave bundle = gmem_C depth = 192
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
        hls::stream<ap_uint<32>> sA32;
        hls::stream<ap_uint<32>> sA33;
        hls::stream<ap_uint<32>> sA34;
        hls::stream<ap_uint<32>> sA35;
        hls::stream<ap_uint<32>> sA36;
        hls::stream<ap_uint<32>> sA37;
        hls::stream<ap_uint<32>> sA38;
        hls::stream<ap_uint<32>> sA39;
        hls::stream<ap_uint<32>> sA40;
        hls::stream<ap_uint<32>> sA41;
        hls::stream<ap_uint<32>> sA42;
        hls::stream<ap_uint<32>> sA43;
        hls::stream<ap_uint<32>> sA44;
        hls::stream<ap_uint<32>> sA45;
        hls::stream<ap_uint<32>> sA46;
        hls::stream<ap_uint<32>> sA47;
        hls::stream<ap_uint<32>> sA48;
        hls::stream<ap_uint<32>> sA49;
        hls::stream<ap_uint<32>> sA50;
        hls::stream<ap_uint<32>> sA51;
        hls::stream<ap_uint<32>> sA52;
        hls::stream<ap_uint<32>> sA53;
        hls::stream<ap_uint<32>> sA54;
        hls::stream<ap_uint<32>> sA55;
        hls::stream<ap_uint<32>> sA56;
        hls::stream<ap_uint<32>> sA57;
        hls::stream<ap_uint<32>> sA58;
        hls::stream<ap_uint<32>> sA59;
        hls::stream<ap_uint<32>> sA60;
        hls::stream<ap_uint<32>> sA61;
        hls::stream<ap_uint<32>> sA62;
        hls::stream<ap_uint<32>> sA63;
        hls::stream<ap_uint<32>> sA64;
        hls::stream<ap_uint<32>> sA65;
        hls::stream<ap_uint<32>> sA66;
        hls::stream<ap_uint<32>> sA67;
        hls::stream<ap_uint<32>> sA68;
        hls::stream<ap_uint<32>> sA69;
        hls::stream<ap_uint<32>> sA70;
        hls::stream<ap_uint<32>> sA71;
        hls::stream<ap_uint<32>> sA72;
        hls::stream<ap_uint<32>> sA73;
        hls::stream<ap_uint<32>> sA74;
        hls::stream<ap_uint<32>> sA75;
        hls::stream<ap_uint<32>> sA76;
        hls::stream<ap_uint<32>> sA77;
        hls::stream<ap_uint<32>> sA78;
        hls::stream<ap_uint<32>> sA79;
        hls::stream<ap_uint<32>> sA80;
        hls::stream<ap_uint<32>> sA81;
        hls::stream<ap_uint<32>> sA82;
        hls::stream<ap_uint<32>> sA83;
        hls::stream<ap_uint<32>> sA84;
        hls::stream<ap_uint<32>> sA85;
        hls::stream<ap_uint<32>> sA86;
        hls::stream<ap_uint<32>> sA87;
        hls::stream<ap_uint<32>> sA88;
        hls::stream<ap_uint<32>> sA89;
        hls::stream<ap_uint<32>> sA90;
        hls::stream<ap_uint<32>> sA91;
        hls::stream<ap_uint<32>> sA92;
        hls::stream<ap_uint<32>> sA93;
        hls::stream<ap_uint<32>> sA94;
        hls::stream<ap_uint<32>> sA95;

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
        hls::stream<ap_uint<32>> sB32;
        hls::stream<ap_uint<32>> sB33;
        hls::stream<ap_uint<32>> sB34;
        hls::stream<ap_uint<32>> sB35;
        hls::stream<ap_uint<32>> sB36;
        hls::stream<ap_uint<32>> sB37;
        hls::stream<ap_uint<32>> sB38;
        hls::stream<ap_uint<32>> sB39;
        hls::stream<ap_uint<32>> sB40;
        hls::stream<ap_uint<32>> sB41;
        hls::stream<ap_uint<32>> sB42;
        hls::stream<ap_uint<32>> sB43;
        hls::stream<ap_uint<32>> sB44;
        hls::stream<ap_uint<32>> sB45;
        hls::stream<ap_uint<32>> sB46;
        hls::stream<ap_uint<32>> sB47;
        hls::stream<ap_uint<32>> sB48;
        hls::stream<ap_uint<32>> sB49;
        hls::stream<ap_uint<32>> sB50;
        hls::stream<ap_uint<32>> sB51;
        hls::stream<ap_uint<32>> sB52;
        hls::stream<ap_uint<32>> sB53;
        hls::stream<ap_uint<32>> sB54;
        hls::stream<ap_uint<32>> sB55;
        hls::stream<ap_uint<32>> sB56;
        hls::stream<ap_uint<32>> sB57;
        hls::stream<ap_uint<32>> sB58;
        hls::stream<ap_uint<32>> sB59;
        hls::stream<ap_uint<32>> sB60;
        hls::stream<ap_uint<32>> sB61;
        hls::stream<ap_uint<32>> sB62;
        hls::stream<ap_uint<32>> sB63;
        hls::stream<ap_uint<32>> sB64;
        hls::stream<ap_uint<32>> sB65;
        hls::stream<ap_uint<32>> sB66;
        hls::stream<ap_uint<32>> sB67;
        hls::stream<ap_uint<32>> sB68;
        hls::stream<ap_uint<32>> sB69;
        hls::stream<ap_uint<32>> sB70;
        hls::stream<ap_uint<32>> sB71;
        hls::stream<ap_uint<32>> sB72;
        hls::stream<ap_uint<32>> sB73;
        hls::stream<ap_uint<32>> sB74;
        hls::stream<ap_uint<32>> sB75;
        hls::stream<ap_uint<32>> sB76;
        hls::stream<ap_uint<32>> sB77;
        hls::stream<ap_uint<32>> sB78;
        hls::stream<ap_uint<32>> sB79;
        hls::stream<ap_uint<32>> sB80;
        hls::stream<ap_uint<32>> sB81;
        hls::stream<ap_uint<32>> sB82;
        hls::stream<ap_uint<32>> sB83;
        hls::stream<ap_uint<32>> sB84;
        hls::stream<ap_uint<32>> sB85;
        hls::stream<ap_uint<32>> sB86;
        hls::stream<ap_uint<32>> sB87;
        hls::stream<ap_uint<32>> sB88;
        hls::stream<ap_uint<32>> sB89;
        hls::stream<ap_uint<32>> sB90;
        hls::stream<ap_uint<32>> sB91;
        hls::stream<ap_uint<32>> sB92;
        hls::stream<ap_uint<32>> sB93;
        hls::stream<ap_uint<32>> sB94;
        hls::stream<ap_uint<32>> sB95;

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
        hls::stream<ap_uint<32>> sC32;
        hls::stream<ap_uint<32>> sC33;
        hls::stream<ap_uint<32>> sC34;
        hls::stream<ap_uint<32>> sC35;
        hls::stream<ap_uint<32>> sC36;
        hls::stream<ap_uint<32>> sC37;
        hls::stream<ap_uint<32>> sC38;
        hls::stream<ap_uint<32>> sC39;
        hls::stream<ap_uint<32>> sC40;
        hls::stream<ap_uint<32>> sC41;
        hls::stream<ap_uint<32>> sC42;
        hls::stream<ap_uint<32>> sC43;
        hls::stream<ap_uint<32>> sC44;
        hls::stream<ap_uint<32>> sC45;
        hls::stream<ap_uint<32>> sC46;
        hls::stream<ap_uint<32>> sC47;
        hls::stream<ap_uint<32>> sC48;
        hls::stream<ap_uint<32>> sC49;
        hls::stream<ap_uint<32>> sC50;
        hls::stream<ap_uint<32>> sC51;
        hls::stream<ap_uint<32>> sC52;
        hls::stream<ap_uint<32>> sC53;
        hls::stream<ap_uint<32>> sC54;
        hls::stream<ap_uint<32>> sC55;
        hls::stream<ap_uint<32>> sC56;
        hls::stream<ap_uint<32>> sC57;
        hls::stream<ap_uint<32>> sC58;
        hls::stream<ap_uint<32>> sC59;
        hls::stream<ap_uint<32>> sC60;
        hls::stream<ap_uint<32>> sC61;
        hls::stream<ap_uint<32>> sC62;
        hls::stream<ap_uint<32>> sC63;
        hls::stream<ap_uint<32>> sC64;
        hls::stream<ap_uint<32>> sC65;
        hls::stream<ap_uint<32>> sC66;
        hls::stream<ap_uint<32>> sC67;
        hls::stream<ap_uint<32>> sC68;
        hls::stream<ap_uint<32>> sC69;
        hls::stream<ap_uint<32>> sC70;
        hls::stream<ap_uint<32>> sC71;
        hls::stream<ap_uint<32>> sC72;
        hls::stream<ap_uint<32>> sC73;
        hls::stream<ap_uint<32>> sC74;
        hls::stream<ap_uint<32>> sC75;
        hls::stream<ap_uint<32>> sC76;
        hls::stream<ap_uint<32>> sC77;
        hls::stream<ap_uint<32>> sC78;
        hls::stream<ap_uint<32>> sC79;
        hls::stream<ap_uint<32>> sC80;
        hls::stream<ap_uint<32>> sC81;
        hls::stream<ap_uint<32>> sC82;
        hls::stream<ap_uint<32>> sC83;
        hls::stream<ap_uint<32>> sC84;
        hls::stream<ap_uint<32>> sC85;
        hls::stream<ap_uint<32>> sC86;
        hls::stream<ap_uint<32>> sC87;
        hls::stream<ap_uint<32>> sC88;
        hls::stream<ap_uint<32>> sC89;
        hls::stream<ap_uint<32>> sC90;
        hls::stream<ap_uint<32>> sC91;
        hls::stream<ap_uint<32>> sC92;
        hls::stream<ap_uint<32>> sC93;
        hls::stream<ap_uint<32>> sC94;
        hls::stream<ap_uint<32>> sC95;

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
#pragma HLS STREAM variable = sA32 depth = 2
#pragma HLS STREAM variable = sA33 depth = 2
#pragma HLS STREAM variable = sA34 depth = 2
#pragma HLS STREAM variable = sA35 depth = 2
#pragma HLS STREAM variable = sA36 depth = 2
#pragma HLS STREAM variable = sA37 depth = 2
#pragma HLS STREAM variable = sA38 depth = 2
#pragma HLS STREAM variable = sA39 depth = 2
#pragma HLS STREAM variable = sA40 depth = 2
#pragma HLS STREAM variable = sA41 depth = 2
#pragma HLS STREAM variable = sA42 depth = 2
#pragma HLS STREAM variable = sA43 depth = 2
#pragma HLS STREAM variable = sA44 depth = 2
#pragma HLS STREAM variable = sA45 depth = 2
#pragma HLS STREAM variable = sA46 depth = 2
#pragma HLS STREAM variable = sA47 depth = 2
#pragma HLS STREAM variable = sA48 depth = 2
#pragma HLS STREAM variable = sA49 depth = 2
#pragma HLS STREAM variable = sA50 depth = 2
#pragma HLS STREAM variable = sA51 depth = 2
#pragma HLS STREAM variable = sA52 depth = 2
#pragma HLS STREAM variable = sA53 depth = 2
#pragma HLS STREAM variable = sA54 depth = 2
#pragma HLS STREAM variable = sA55 depth = 2
#pragma HLS STREAM variable = sA56 depth = 2
#pragma HLS STREAM variable = sA57 depth = 2
#pragma HLS STREAM variable = sA58 depth = 2
#pragma HLS STREAM variable = sA59 depth = 2
#pragma HLS STREAM variable = sA60 depth = 2
#pragma HLS STREAM variable = sA61 depth = 2
#pragma HLS STREAM variable = sA62 depth = 2
#pragma HLS STREAM variable = sA63 depth = 2
#pragma HLS STREAM variable = sA64 depth = 2
#pragma HLS STREAM variable = sA65 depth = 2
#pragma HLS STREAM variable = sA66 depth = 2
#pragma HLS STREAM variable = sA67 depth = 2
#pragma HLS STREAM variable = sA68 depth = 2
#pragma HLS STREAM variable = sA69 depth = 2
#pragma HLS STREAM variable = sA70 depth = 2
#pragma HLS STREAM variable = sA71 depth = 2
#pragma HLS STREAM variable = sA72 depth = 2
#pragma HLS STREAM variable = sA73 depth = 2
#pragma HLS STREAM variable = sA74 depth = 2
#pragma HLS STREAM variable = sA75 depth = 2
#pragma HLS STREAM variable = sA76 depth = 2
#pragma HLS STREAM variable = sA77 depth = 2
#pragma HLS STREAM variable = sA78 depth = 2
#pragma HLS STREAM variable = sA79 depth = 2
#pragma HLS STREAM variable = sA80 depth = 2
#pragma HLS STREAM variable = sA81 depth = 2
#pragma HLS STREAM variable = sA82 depth = 2
#pragma HLS STREAM variable = sA83 depth = 2
#pragma HLS STREAM variable = sA84 depth = 2
#pragma HLS STREAM variable = sA85 depth = 2
#pragma HLS STREAM variable = sA86 depth = 2
#pragma HLS STREAM variable = sA87 depth = 2
#pragma HLS STREAM variable = sA88 depth = 2
#pragma HLS STREAM variable = sA89 depth = 2
#pragma HLS STREAM variable = sA90 depth = 2
#pragma HLS STREAM variable = sA91 depth = 2
#pragma HLS STREAM variable = sA92 depth = 2
#pragma HLS STREAM variable = sA93 depth = 2
#pragma HLS STREAM variable = sA94 depth = 2
#pragma HLS STREAM variable = sA95 depth = 2
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
#pragma HLS STREAM variable = sB32 depth = 2
#pragma HLS STREAM variable = sB33 depth = 2
#pragma HLS STREAM variable = sB34 depth = 2
#pragma HLS STREAM variable = sB35 depth = 2
#pragma HLS STREAM variable = sB36 depth = 2
#pragma HLS STREAM variable = sB37 depth = 2
#pragma HLS STREAM variable = sB38 depth = 2
#pragma HLS STREAM variable = sB39 depth = 2
#pragma HLS STREAM variable = sB40 depth = 2
#pragma HLS STREAM variable = sB41 depth = 2
#pragma HLS STREAM variable = sB42 depth = 2
#pragma HLS STREAM variable = sB43 depth = 2
#pragma HLS STREAM variable = sB44 depth = 2
#pragma HLS STREAM variable = sB45 depth = 2
#pragma HLS STREAM variable = sB46 depth = 2
#pragma HLS STREAM variable = sB47 depth = 2
#pragma HLS STREAM variable = sB48 depth = 2
#pragma HLS STREAM variable = sB49 depth = 2
#pragma HLS STREAM variable = sB50 depth = 2
#pragma HLS STREAM variable = sB51 depth = 2
#pragma HLS STREAM variable = sB52 depth = 2
#pragma HLS STREAM variable = sB53 depth = 2
#pragma HLS STREAM variable = sB54 depth = 2
#pragma HLS STREAM variable = sB55 depth = 2
#pragma HLS STREAM variable = sB56 depth = 2
#pragma HLS STREAM variable = sB57 depth = 2
#pragma HLS STREAM variable = sB58 depth = 2
#pragma HLS STREAM variable = sB59 depth = 2
#pragma HLS STREAM variable = sB60 depth = 2
#pragma HLS STREAM variable = sB61 depth = 2
#pragma HLS STREAM variable = sB62 depth = 2
#pragma HLS STREAM variable = sB63 depth = 2
#pragma HLS STREAM variable = sB64 depth = 2
#pragma HLS STREAM variable = sB65 depth = 2
#pragma HLS STREAM variable = sB66 depth = 2
#pragma HLS STREAM variable = sB67 depth = 2
#pragma HLS STREAM variable = sB68 depth = 2
#pragma HLS STREAM variable = sB69 depth = 2
#pragma HLS STREAM variable = sB70 depth = 2
#pragma HLS STREAM variable = sB71 depth = 2
#pragma HLS STREAM variable = sB72 depth = 2
#pragma HLS STREAM variable = sB73 depth = 2
#pragma HLS STREAM variable = sB74 depth = 2
#pragma HLS STREAM variable = sB75 depth = 2
#pragma HLS STREAM variable = sB76 depth = 2
#pragma HLS STREAM variable = sB77 depth = 2
#pragma HLS STREAM variable = sB78 depth = 2
#pragma HLS STREAM variable = sB79 depth = 2
#pragma HLS STREAM variable = sB80 depth = 2
#pragma HLS STREAM variable = sB81 depth = 2
#pragma HLS STREAM variable = sB82 depth = 2
#pragma HLS STREAM variable = sB83 depth = 2
#pragma HLS STREAM variable = sB84 depth = 2
#pragma HLS STREAM variable = sB85 depth = 2
#pragma HLS STREAM variable = sB86 depth = 2
#pragma HLS STREAM variable = sB87 depth = 2
#pragma HLS STREAM variable = sB88 depth = 2
#pragma HLS STREAM variable = sB89 depth = 2
#pragma HLS STREAM variable = sB90 depth = 2
#pragma HLS STREAM variable = sB91 depth = 2
#pragma HLS STREAM variable = sB92 depth = 2
#pragma HLS STREAM variable = sB93 depth = 2
#pragma HLS STREAM variable = sB94 depth = 2
#pragma HLS STREAM variable = sB95 depth = 2
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
#pragma HLS STREAM variable = sC32 depth = 2
#pragma HLS STREAM variable = sC33 depth = 2
#pragma HLS STREAM variable = sC34 depth = 2
#pragma HLS STREAM variable = sC35 depth = 2
#pragma HLS STREAM variable = sC36 depth = 2
#pragma HLS STREAM variable = sC37 depth = 2
#pragma HLS STREAM variable = sC38 depth = 2
#pragma HLS STREAM variable = sC39 depth = 2
#pragma HLS STREAM variable = sC40 depth = 2
#pragma HLS STREAM variable = sC41 depth = 2
#pragma HLS STREAM variable = sC42 depth = 2
#pragma HLS STREAM variable = sC43 depth = 2
#pragma HLS STREAM variable = sC44 depth = 2
#pragma HLS STREAM variable = sC45 depth = 2
#pragma HLS STREAM variable = sC46 depth = 2
#pragma HLS STREAM variable = sC47 depth = 2
#pragma HLS STREAM variable = sC48 depth = 2
#pragma HLS STREAM variable = sC49 depth = 2
#pragma HLS STREAM variable = sC50 depth = 2
#pragma HLS STREAM variable = sC51 depth = 2
#pragma HLS STREAM variable = sC52 depth = 2
#pragma HLS STREAM variable = sC53 depth = 2
#pragma HLS STREAM variable = sC54 depth = 2
#pragma HLS STREAM variable = sC55 depth = 2
#pragma HLS STREAM variable = sC56 depth = 2
#pragma HLS STREAM variable = sC57 depth = 2
#pragma HLS STREAM variable = sC58 depth = 2
#pragma HLS STREAM variable = sC59 depth = 2
#pragma HLS STREAM variable = sC60 depth = 2
#pragma HLS STREAM variable = sC61 depth = 2
#pragma HLS STREAM variable = sC62 depth = 2
#pragma HLS STREAM variable = sC63 depth = 2
#pragma HLS STREAM variable = sC64 depth = 2
#pragma HLS STREAM variable = sC65 depth = 2
#pragma HLS STREAM variable = sC66 depth = 2
#pragma HLS STREAM variable = sC67 depth = 2
#pragma HLS STREAM variable = sC68 depth = 2
#pragma HLS STREAM variable = sC69 depth = 2
#pragma HLS STREAM variable = sC70 depth = 2
#pragma HLS STREAM variable = sC71 depth = 2
#pragma HLS STREAM variable = sC72 depth = 2
#pragma HLS STREAM variable = sC73 depth = 2
#pragma HLS STREAM variable = sC74 depth = 2
#pragma HLS STREAM variable = sC75 depth = 2
#pragma HLS STREAM variable = sC76 depth = 2
#pragma HLS STREAM variable = sC77 depth = 2
#pragma HLS STREAM variable = sC78 depth = 2
#pragma HLS STREAM variable = sC79 depth = 2
#pragma HLS STREAM variable = sC80 depth = 2
#pragma HLS STREAM variable = sC81 depth = 2
#pragma HLS STREAM variable = sC82 depth = 2
#pragma HLS STREAM variable = sC83 depth = 2
#pragma HLS STREAM variable = sC84 depth = 2
#pragma HLS STREAM variable = sC85 depth = 2
#pragma HLS STREAM variable = sC86 depth = 2
#pragma HLS STREAM variable = sC87 depth = 2
#pragma HLS STREAM variable = sC88 depth = 2
#pragma HLS STREAM variable = sC89 depth = 2
#pragma HLS STREAM variable = sC90 depth = 2
#pragma HLS STREAM variable = sC91 depth = 2
#pragma HLS STREAM variable = sC92 depth = 2
#pragma HLS STREAM variable = sC93 depth = 2
#pragma HLS STREAM variable = sC94 depth = 2
#pragma HLS STREAM variable = sC95 depth = 2

#pragma HLS DATAFLOW

        pl_mm2s(A, 
                sA0, sA1, sA2, sA3, sA4, sA5, sA6, sA7, sA8, sA9, sA10, sA11, sA12, sA13, sA14, sA15, sA16, sA17, sA18, sA19, sA20, sA21, sA22, sA23, sA24, sA25, sA26, sA27, sA28, sA29, sA30, sA31, sA32, sA33, sA34, sA35, sA36, sA37, sA38, sA39, sA40, sA41, sA42, sA43, sA44, sA45, sA46, sA47, sA48, sA49, sA50, sA51, sA52, sA53, sA54, sA55, sA56, sA57, sA58, sA59, sA60, sA61, sA62, sA63, sA64, sA65, sA66, sA67, sA68, sA69, sA70, sA71, sA72, sA73, sA74, sA75, sA76, sA77, sA78, sA79, sA80, sA81, sA82, sA83, sA84, sA85, sA86, sA87, sA88, sA89, sA90, sA91, sA92, sA93, sA94, sA95);
        pl_mm2s(B,
                sB0, sB1, sB2, sB3, sB4, sB5, sB6, sB7, sB8, sB9, sB10, sB11, sB12, sB13, sB14, sB15, sB16, sB17, sB18, sB19, sB20, sB21, sB22, sB23, sB24, sB25, sB26, sB27, sB28, sB29, sB30, sB31, sB32, sB33, sB34, sB35, sB36, sB37, sB38, sB39, sB40, sB41, sB42, sB43, sB44, sB45, sB46, sB47, sB48, sB49, sB50, sB51, sB52, sB53, sB54, sB55, sB56, sB57, sB58, sB59, sB60, sB61, sB62, sB63, sB64, sB65, sB66, sB67, sB68, sB69, sB70, sB71, sB72, sB73, sB74, sB75, sB76, sB77, sB78, sB79, sB80, sB81, sB82, sB83, sB84, sB85, sB86, sB87, sB88, sB89, sB90, sB91, sB92, sB93, sB94, sB95);
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
        multiply(sA32, sB32, sC32);
        multiply(sA33, sB33, sC33);
        multiply(sA34, sB34, sC34);
        multiply(sA35, sB35, sC35);
        multiply(sA36, sB36, sC36);
        multiply(sA37, sB37, sC37);
        multiply(sA38, sB38, sC38);
        multiply(sA39, sB39, sC39);
        multiply(sA40, sB40, sC40);
        multiply(sA41, sB41, sC41);
        multiply(sA42, sB42, sC42);
        multiply(sA43, sB43, sC43);
        multiply(sA44, sB44, sC44);
        multiply(sA45, sB45, sC45);
        multiply(sA46, sB46, sC46);
        multiply(sA47, sB47, sC47);
        multiply(sA48, sB48, sC48);
        multiply(sA49, sB49, sC49);
        multiply(sA50, sB50, sC50);
        multiply(sA51, sB51, sC51);
        multiply(sA52, sB52, sC52);
        multiply(sA53, sB53, sC53);
        multiply(sA54, sB54, sC54);
        multiply(sA55, sB55, sC55);
        multiply(sA56, sB56, sC56);
        multiply(sA57, sB57, sC57);
        multiply(sA58, sB58, sC58);
        multiply(sA59, sB59, sC59);
        multiply(sA60, sB60, sC60);
        multiply(sA61, sB61, sC61);
        multiply(sA62, sB62, sC62);
        multiply(sA63, sB63, sC63);
        multiply(sA64, sB64, sC64);
        multiply(sA65, sB65, sC65);
        multiply(sA66, sB66, sC66);
        multiply(sA67, sB67, sC67);
        multiply(sA68, sB68, sC68);
        multiply(sA69, sB69, sC69);
        multiply(sA70, sB70, sC70);
        multiply(sA71, sB71, sC71);
        multiply(sA72, sB72, sC72);
        multiply(sA73, sB73, sC73);
        multiply(sA74, sB74, sC74);
        multiply(sA75, sB75, sC75);
        multiply(sA76, sB76, sC76);
        multiply(sA77, sB77, sC77);
        multiply(sA78, sB78, sC78);
        multiply(sA79, sB79, sC79);
        multiply(sA80, sB80, sC80);
        multiply(sA81, sB81, sC81);
        multiply(sA82, sB82, sC82);
        multiply(sA83, sB83, sC83);
        multiply(sA84, sB84, sC84);
        multiply(sA85, sB85, sC85);
        multiply(sA86, sB86, sC86);
        multiply(sA87, sB87, sC87);
        multiply(sA88, sB88, sC88);
        multiply(sA89, sB89, sC89);
        multiply(sA90, sB90, sC90);
        multiply(sA91, sB91, sC91);
        multiply(sA92, sB92, sC92);
        multiply(sA93, sB93, sC93);
        multiply(sA94, sB94, sC94);
        multiply(sA95, sB95, sC95);
        pl_s2mm(C,
                sC0, sC1, sC2, sC3, sC4, sC5, sC6, sC7, sC8, sC9, sC10, sC11, sC12, sC13, sC14, sC15, sC16, sC17, sC18, sC19, sC20, sC21, sC22, sC23, sC24, sC25, sC26, sC27, sC28, sC29, sC30, sC31, sC32, sC33, sC34, sC35, sC36, sC37, sC38, sC39, sC40, sC41, sC42, sC43, sC44, sC45, sC46, sC47, sC48, sC49, sC50, sC51, sC52, sC53, sC54, sC55, sC56, sC57, sC58, sC59, sC60, sC61, sC62, sC63, sC64, sC65, sC66, sC67, sC68, sC69, sC70, sC71, sC72, sC73, sC74, sC75, sC76, sC77, sC78, sC79, sC80, sC81, sC82, sC83, sC84, sC85, sC86, sC87, sC88, sC89, sC90, sC91, sC92, sC93, sC94, sC95);
    }
}   
