#include <aie_api/aie.hpp>
#include <aie_api/aie_adf.hpp>
#include <aie_api/utils.hpp>
#include "common.h"

constexpr int upper_bound = SIZE / PE / SIMD;

void aie_vmul_window(input_window<float> *in0, input_window<float> *in1, output_window<float> *out)
{
    for (auto i = 0; i < upper_bound; i++)
        chess_prepare_for_pipelining
        chess_loop_range(upper_bound, upper_bound)
        {
            auto a = window_read_v<SIMD>(in0);
            auto b = window_read_v<SIMD>(in1);
            auto res = aie::mul(a, b);
            window_writeincr(out, res);
        }
}