#if !defined(__APPLE__) && (__clang_major__ == 3)
#error AVX512VL is not supported on clang 3.9 and earlier.
#endif

#include <immintrin.h>
#include <iostream>

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
        char data[16];
        __m128 align;
    };
    char* p = data;
    p = prevent_optimization(p);

    __m128 f = _mm_load_ps((float*)p);
    f = _mm_rcp14_ps(f); // only in AVX512-VL
    _mm_store_ps((float*)p, f);

    p = prevent_optimization(p);
}
