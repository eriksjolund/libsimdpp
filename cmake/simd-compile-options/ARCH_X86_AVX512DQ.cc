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
        char data[64];
        __m512 align;
    };
    char* p = data;
    p = prevent_optimization(p);

    __m512 f = _mm512_load_ps((float*)p);
    f = _mm512_and_ps(f, f); // only in AVX512-DQ
    _mm512_store_ps((float*)p, f);

    p = prevent_optimization(p);
}
