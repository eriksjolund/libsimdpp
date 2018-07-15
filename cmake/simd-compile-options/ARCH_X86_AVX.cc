#include <immintrin.h>
#include <iostream>

#if (__clang_major__ == 3) && (__clang_minor__ == 6)
#error Not supported. See simdpp/detail/workarounds.h
#endif
#if (__GNUC__ == 4) && (__GNUC_MINOR__ == 4) && !defined(__INTEL_COMPILER) && !defined(__clang__)
#error Not supported. See simdpp/detail/workarounds.h
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
        char data[32];
        __m256 align;
    };
    char* p = data;
    p = prevent_optimization(p);

    __m256 one = _mm256_load_ps((float*)p);
    one = _mm256_add_ps(one, one);
    _mm256_store_ps((float*)p, one);

    p = prevent_optimization(p);
}
