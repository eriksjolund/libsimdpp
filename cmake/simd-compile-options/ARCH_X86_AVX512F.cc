#include <immintrin.h>
#include <iostream>

#if defined(__GNUC__) && (__GNUC__ < 6) && !defined(__INTEL_COMPILER) && !defined(__clang__)
#error GCC 5.x and older are not supported on AVX512F. See simdpp/detail/workarounds.h
#endif

char* prevent_optimization(char* ptr)
{
    volatile bool never = false;
    if (never) {
        while (*ptr++)
            std::cout << *ptr;
    }
    char* volatile* volatile opaque;
    opaque = &ptr;
    return *opaque;
}

int main()
{
    union {
        char data[64];
        __m512 align;
    };
    char* p = data;
    p = prevent_optimization(p);
    __m512 f = _mm512_load_ps((float*)p);
    p = prevent_optimization(p);
    __m512i i = _mm512_load_epi32((__m512i*)p);
    p = prevent_optimization(p);

    f = _mm512_add_ps(f, f);

    // MSVC 2017 miss this
    i = _mm512_or_epi32(i, i);
    f = _mm512_ceil_ps(f);

    // ICE on various versions of Clang trying to select palignr
    __m512i i2 = _mm512_load_epi32((__m512i*)p);
    __m512i ap = _mm512_alignr_epi32(i, i, 2);
    i = _mm512_mask_alignr_epi32(ap, 0xcccc, i2, i2, 14);

    p = prevent_optimization(p);
    _mm512_store_ps((float*)p, f);
    p = prevent_optimization(p);
    _mm512_store_epi32((void*)p, i);
    p = prevent_optimization(p);
}
