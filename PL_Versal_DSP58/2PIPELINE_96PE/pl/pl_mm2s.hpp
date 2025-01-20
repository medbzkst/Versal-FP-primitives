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
                 hls::stream<ap_uint<32>> &sA31,
                 hls::stream<ap_uint<32>> &sA32,
                 hls::stream<ap_uint<32>> &sA33,
                 hls::stream<ap_uint<32>> &sA34,
                 hls::stream<ap_uint<32>> &sA35,
                 hls::stream<ap_uint<32>> &sA36,
                 hls::stream<ap_uint<32>> &sA37,
                 hls::stream<ap_uint<32>> &sA38,
                 hls::stream<ap_uint<32>> &sA39,
                 hls::stream<ap_uint<32>> &sA40,
                 hls::stream<ap_uint<32>> &sA41,
                 hls::stream<ap_uint<32>> &sA42,
                 hls::stream<ap_uint<32>> &sA43,
                 hls::stream<ap_uint<32>> &sA44,
                 hls::stream<ap_uint<32>> &sA45,
                 hls::stream<ap_uint<32>> &sA46,
                 hls::stream<ap_uint<32>> &sA47,
                 hls::stream<ap_uint<32>> &sA48,
                 hls::stream<ap_uint<32>> &sA49,
                 hls::stream<ap_uint<32>> &sA50,
                 hls::stream<ap_uint<32>> &sA51,
                 hls::stream<ap_uint<32>> &sA52,
                 hls::stream<ap_uint<32>> &sA53,
                 hls::stream<ap_uint<32>> &sA54,
                 hls::stream<ap_uint<32>> &sA55,
                 hls::stream<ap_uint<32>> &sA56,
                 hls::stream<ap_uint<32>> &sA57,
                 hls::stream<ap_uint<32>> &sA58,
                 hls::stream<ap_uint<32>> &sA59,
                 hls::stream<ap_uint<32>> &sA60,
                 hls::stream<ap_uint<32>> &sA61,
                 hls::stream<ap_uint<32>> &sA62,
                 hls::stream<ap_uint<32>> &sA63,
                 hls::stream<ap_uint<32>> &sA64,
                 hls::stream<ap_uint<32>> &sA65,
                 hls::stream<ap_uint<32>> &sA66,
                 hls::stream<ap_uint<32>> &sA67,
                 hls::stream<ap_uint<32>> &sA68,
                 hls::stream<ap_uint<32>> &sA69,
                 hls::stream<ap_uint<32>> &sA70,
                 hls::stream<ap_uint<32>> &sA71,
                 hls::stream<ap_uint<32>> &sA72,
                 hls::stream<ap_uint<32>> &sA73,
                 hls::stream<ap_uint<32>> &sA74,
                 hls::stream<ap_uint<32>> &sA75,
                 hls::stream<ap_uint<32>> &sA76,
                 hls::stream<ap_uint<32>> &sA77,
                 hls::stream<ap_uint<32>> &sA78,
                 hls::stream<ap_uint<32>> &sA79,
                 hls::stream<ap_uint<32>> &sA80,
                 hls::stream<ap_uint<32>> &sA81,
                 hls::stream<ap_uint<32>> &sA82,
                 hls::stream<ap_uint<32>> &sA83,
                 hls::stream<ap_uint<32>> &sA84,
                 hls::stream<ap_uint<32>> &sA85,
                 hls::stream<ap_uint<32>> &sA86,
                 hls::stream<ap_uint<32>> &sA87,
                 hls::stream<ap_uint<32>> &sA88,
                 hls::stream<ap_uint<32>> &sA89,
                 hls::stream<ap_uint<32>> &sA90,
                 hls::stream<ap_uint<32>> &sA91,
                 hls::stream<ap_uint<32>> &sA92,
                 hls::stream<ap_uint<32>> &sA93,
                 hls::stream<ap_uint<32>> &sA94,
                 hls::stream<ap_uint<32>> &sA95);
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
                 hls::stream<ap_uint<32>> &sA31,
                 hls::stream<ap_uint<32>> &sA32,
                 hls::stream<ap_uint<32>> &sA33,
                 hls::stream<ap_uint<32>> &sA34,
                 hls::stream<ap_uint<32>> &sA35,
                 hls::stream<ap_uint<32>> &sA36,
                 hls::stream<ap_uint<32>> &sA37,
                 hls::stream<ap_uint<32>> &sA38,
                 hls::stream<ap_uint<32>> &sA39,
                 hls::stream<ap_uint<32>> &sA40,
                 hls::stream<ap_uint<32>> &sA41,
                 hls::stream<ap_uint<32>> &sA42,
                 hls::stream<ap_uint<32>> &sA43,
                 hls::stream<ap_uint<32>> &sA44,
                 hls::stream<ap_uint<32>> &sA45,
                 hls::stream<ap_uint<32>> &sA46,
                 hls::stream<ap_uint<32>> &sA47,
                 hls::stream<ap_uint<32>> &sA48,
                 hls::stream<ap_uint<32>> &sA49,
                 hls::stream<ap_uint<32>> &sA50,
                 hls::stream<ap_uint<32>> &sA51,
                 hls::stream<ap_uint<32>> &sA52,
                 hls::stream<ap_uint<32>> &sA53,
                 hls::stream<ap_uint<32>> &sA54,
                 hls::stream<ap_uint<32>> &sA55,
                 hls::stream<ap_uint<32>> &sA56,
                 hls::stream<ap_uint<32>> &sA57,
                 hls::stream<ap_uint<32>> &sA58,
                 hls::stream<ap_uint<32>> &sA59,
                 hls::stream<ap_uint<32>> &sA60,
                 hls::stream<ap_uint<32>> &sA61,
                 hls::stream<ap_uint<32>> &sA62,
                 hls::stream<ap_uint<32>> &sA63,
                 hls::stream<ap_uint<32>> &sA64,
                 hls::stream<ap_uint<32>> &sA65,
                 hls::stream<ap_uint<32>> &sA66,
                 hls::stream<ap_uint<32>> &sA67,
                 hls::stream<ap_uint<32>> &sA68,
                 hls::stream<ap_uint<32>> &sA69,
                 hls::stream<ap_uint<32>> &sA70,
                 hls::stream<ap_uint<32>> &sA71,
                 hls::stream<ap_uint<32>> &sA72,
                 hls::stream<ap_uint<32>> &sA73,
                 hls::stream<ap_uint<32>> &sA74,
                 hls::stream<ap_uint<32>> &sA75,
                 hls::stream<ap_uint<32>> &sA76,
                 hls::stream<ap_uint<32>> &sA77,
                 hls::stream<ap_uint<32>> &sA78,
                 hls::stream<ap_uint<32>> &sA79,
                 hls::stream<ap_uint<32>> &sA80,
                 hls::stream<ap_uint<32>> &sA81,
                 hls::stream<ap_uint<32>> &sA82,
                 hls::stream<ap_uint<32>> &sA83,
                 hls::stream<ap_uint<32>> &sA84,
                 hls::stream<ap_uint<32>> &sA85,
                 hls::stream<ap_uint<32>> &sA86,
                 hls::stream<ap_uint<32>> &sA87,
                 hls::stream<ap_uint<32>> &sA88,
                 hls::stream<ap_uint<32>> &sA89,
                 hls::stream<ap_uint<32>> &sA90,
                 hls::stream<ap_uint<32>> &sA91,
                 hls::stream<ap_uint<32>> &sA92,
                 hls::stream<ap_uint<32>> &sA93,
                 hls::stream<ap_uint<32>> &sA94,
                 hls::stream<ap_uint<32>> &sA95)
    {
       data_mover_input:
        for (auto i = 0; i < 16; i++)
        {
            data_t8 fu;
            fu = A[12*i+0];

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

            fu = A[12*i+1];

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

            fu = A[12*i+2];

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

            fu = A[12*i+3];

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

            fu = A[12*i+4];

            ap_uint<32> xA32;
            xA32 = fu(32*(0+1)-1,32*0);
            sA32.write(xA32);

            ap_uint<32> xA33;
            xA33 = fu(32*(1+1)-1,32*1);
            sA33.write(xA33);

            ap_uint<32> xA34;
            xA34 = fu(32*(2+1)-1,32*2);
            sA34.write(xA34);

            ap_uint<32> xA35;
            xA35 = fu(32*(3+1)-1,32*3);
            sA35.write(xA35);

            ap_uint<32> xA36;
            xA36 = fu(32*(4+1)-1,32*4);
            sA36.write(xA36);

            ap_uint<32> xA37;
            xA37 = fu(32*(5+1)-1,32*5);
            sA37.write(xA37);

            ap_uint<32> xA38;
            xA38 = fu(32*(6+1)-1,32*6);
            sA38.write(xA38);

            ap_uint<32> xA39;
            xA39 = fu(32*(7+1)-1,32*7);
            sA39.write(xA39);

            fu = A[12*i+5];

            ap_uint<32> xA40;
            xA40 = fu(32*(0+1)-1,32*0);
            sA40.write(xA40);

            ap_uint<32> xA41;
            xA41 = fu(32*(1+1)-1,32*1);
            sA41.write(xA41);

            ap_uint<32> xA42;
            xA42 = fu(32*(2+1)-1,32*2);
            sA42.write(xA42);

            ap_uint<32> xA43;
            xA43 = fu(32*(3+1)-1,32*3);
            sA43.write(xA43);

            ap_uint<32> xA44;
            xA44 = fu(32*(4+1)-1,32*4);
            sA44.write(xA44);

            ap_uint<32> xA45;
            xA45 = fu(32*(5+1)-1,32*5);
            sA45.write(xA45);

            ap_uint<32> xA46;
            xA46 = fu(32*(6+1)-1,32*6);
            sA46.write(xA46);

            ap_uint<32> xA47;
            xA47 = fu(32*(7+1)-1,32*7);
            sA47.write(xA47);

            fu = A[12*i+6];

            ap_uint<32> xA48;
            xA48 = fu(32*(0+1)-1,32*0);
            sA48.write(xA48);

            ap_uint<32> xA49;
            xA49 = fu(32*(1+1)-1,32*1);
            sA49.write(xA49);

            ap_uint<32> xA50;
            xA50 = fu(32*(2+1)-1,32*2);
            sA50.write(xA50);

            ap_uint<32> xA51;
            xA51 = fu(32*(3+1)-1,32*3);
            sA51.write(xA51);

            ap_uint<32> xA52;
            xA52 = fu(32*(4+1)-1,32*4);
            sA52.write(xA52);

            ap_uint<32> xA53;
            xA53 = fu(32*(5+1)-1,32*5);
            sA53.write(xA53);

            ap_uint<32> xA54;
            xA54 = fu(32*(6+1)-1,32*6);
            sA54.write(xA54);

            ap_uint<32> xA55;
            xA55 = fu(32*(7+1)-1,32*7);
            sA55.write(xA55);

            fu = A[12*i+7];

            ap_uint<32> xA56;
            xA56 = fu(32*(0+1)-1,32*0);
            sA56.write(xA56);

            ap_uint<32> xA57;
            xA57 = fu(32*(1+1)-1,32*1);
            sA57.write(xA57);

            ap_uint<32> xA58;
            xA58 = fu(32*(2+1)-1,32*2);
            sA58.write(xA58);

            ap_uint<32> xA59;
            xA59 = fu(32*(3+1)-1,32*3);
            sA59.write(xA59);

            ap_uint<32> xA60;
            xA60 = fu(32*(4+1)-1,32*4);
            sA60.write(xA60);

            ap_uint<32> xA61;
            xA61 = fu(32*(5+1)-1,32*5);
            sA61.write(xA61);

            ap_uint<32> xA62;
            xA62 = fu(32*(6+1)-1,32*6);
            sA62.write(xA62);

            ap_uint<32> xA63;
            xA63 = fu(32*(7+1)-1,32*7);
            sA63.write(xA63);

            fu = A[12*i+8];

            ap_uint<32> xA64;
            xA64 = fu(32*(0+1)-1,32*0);
            sA64.write(xA64);

            ap_uint<32> xA65;
            xA65 = fu(32*(1+1)-1,32*1);
            sA65.write(xA65);

            ap_uint<32> xA66;
            xA66 = fu(32*(2+1)-1,32*2);
            sA66.write(xA66);

            ap_uint<32> xA67;
            xA67 = fu(32*(3+1)-1,32*3);
            sA67.write(xA67);

            ap_uint<32> xA68;
            xA68 = fu(32*(4+1)-1,32*4);
            sA68.write(xA68);

            ap_uint<32> xA69;
            xA69 = fu(32*(5+1)-1,32*5);
            sA69.write(xA69);

            ap_uint<32> xA70;
            xA70 = fu(32*(6+1)-1,32*6);
            sA70.write(xA70);

            ap_uint<32> xA71;
            xA71 = fu(32*(7+1)-1,32*7);
            sA71.write(xA71);

            fu = A[12*i+9];

            ap_uint<32> xA72;
            xA72 = fu(32*(0+1)-1,32*0);
            sA72.write(xA72);

            ap_uint<32> xA73;
            xA73 = fu(32*(1+1)-1,32*1);
            sA73.write(xA73);

            ap_uint<32> xA74;
            xA74 = fu(32*(2+1)-1,32*2);
            sA74.write(xA74);

            ap_uint<32> xA75;
            xA75 = fu(32*(3+1)-1,32*3);
            sA75.write(xA75);

            ap_uint<32> xA76;
            xA76 = fu(32*(4+1)-1,32*4);
            sA76.write(xA76);

            ap_uint<32> xA77;
            xA77 = fu(32*(5+1)-1,32*5);
            sA77.write(xA77);

            ap_uint<32> xA78;
            xA78 = fu(32*(6+1)-1,32*6);
            sA78.write(xA78);

            ap_uint<32> xA79;
            xA79 = fu(32*(7+1)-1,32*7);
            sA79.write(xA79);

            fu = A[12*i+10];

            ap_uint<32> xA80;
            xA80 = fu(32*(0+1)-1,32*0);
            sA80.write(xA80);

            ap_uint<32> xA81;
            xA81 = fu(32*(1+1)-1,32*1);
            sA81.write(xA81);

            ap_uint<32> xA82;
            xA82 = fu(32*(2+1)-1,32*2);
            sA82.write(xA82);

            ap_uint<32> xA83;
            xA83 = fu(32*(3+1)-1,32*3);
            sA83.write(xA83);

            ap_uint<32> xA84;
            xA84 = fu(32*(4+1)-1,32*4);
            sA84.write(xA84);

            ap_uint<32> xA85;
            xA85 = fu(32*(5+1)-1,32*5);
            sA85.write(xA85);

            ap_uint<32> xA86;
            xA86 = fu(32*(6+1)-1,32*6);
            sA86.write(xA86);

            ap_uint<32> xA87;
            xA87 = fu(32*(7+1)-1,32*7);
            sA87.write(xA87);

            fu = A[12*i+11];

            ap_uint<32> xA88;
            xA88 = fu(32*(0+1)-1,32*0);
            sA88.write(xA88);

            ap_uint<32> xA89;
            xA89 = fu(32*(1+1)-1,32*1);
            sA89.write(xA89);

            ap_uint<32> xA90;
            xA90 = fu(32*(2+1)-1,32*2);
            sA90.write(xA90);

            ap_uint<32> xA91;
            xA91 = fu(32*(3+1)-1,32*3);
            sA91.write(xA91);

            ap_uint<32> xA92;
            xA92 = fu(32*(4+1)-1,32*4);
            sA92.write(xA92);

            ap_uint<32> xA93;
            xA93 = fu(32*(5+1)-1,32*5);
            sA93.write(xA93);

            ap_uint<32> xA94;
            xA94 = fu(32*(6+1)-1,32*6);
            sA94.write(xA94);

            ap_uint<32> xA95;
            xA95 = fu(32*(7+1)-1,32*7);
            sA95.write(xA95);

        }
    }
}
