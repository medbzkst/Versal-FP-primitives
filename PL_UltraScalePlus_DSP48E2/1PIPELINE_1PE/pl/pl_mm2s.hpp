#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include "../common/common.h"

typedef ap_uint<256> data_t8;

extern "C"
{

    void pl_mm2s(data_t8 *A,
                 hls::stream<data_t8> &sA0,
                  int size);
}
extern "C"
{

    void pl_mm2s(data_t8 *A,
                 hls::stream<data_t8> &sA0,
                  int size)
    {
       data_mover_input:
        for (auto i = 0; i < size; i++)
        {
            sA0.write(A[i]);
        }
    }
}
