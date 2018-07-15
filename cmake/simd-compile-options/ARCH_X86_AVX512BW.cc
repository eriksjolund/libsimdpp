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
        __m512i align;
    };
    char* p = data;
    p = prevent_optimization(p);

    __m512i i = _mm512_load_si512((void*)p);
    i = _mm512_add_epi16(i, i); // only in AVX-512BW
    _mm512_store_si512((void*)p, i);

    p = prevent_optimization(p);
}
