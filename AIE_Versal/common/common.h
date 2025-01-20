#ifndef __COMMON_H__
#define __COMMON_H__

#define ROWS 8
#define COLS 48
#define PE (ROWS*COLS)
#define SIMD 8
#define SIZE 245760 // PE*SIMD*PIPELINE

#define packet_per_col 2
#define rows_per_packet 4

#endif