#include <immintrin.h>
#include <iostream>

#if (__clang_major__ == 3) && (__clang_minor__ == 6)
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

    __m256i one = _mm256_load_si256((__m256i*)p);
    one = _mm256_or_si256(one, one);
    _mm256_store_si256((__m256i*)p, one);

    p = prevent_optimization(p);
}
