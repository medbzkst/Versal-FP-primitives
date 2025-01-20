#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include "../common/common.h"

typedef ap_uint<256> data_t8;

extern "C"
{

    void pl_s2mm(data_t8 *C,
                 hls::stream<data_t8> &s0,
                  int size);
}
extern "C"
{

    void pl_s2mm(data_t8 *C,
                 hls::stream<data_t8> &s0,
                  int size)
    {
       data_mover_output:
        for (auto i = 0; i < size; i++)
        {
            C[i] = s0.read();
        }
    }
}
