#include <x86intrin.h>
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
        __m128i align;
    };
    char* p = data;
    p = prevent_optimization(p);

    __m128i one = _mm_load_si128((__m128i*)p);
    one = _mm_cmov_si128(one, one, one);
    one = _mm_comeq_epi64(one, one);
    _mm_store_si128((__m128i*)p, one);

    p = prevent_optimization(p);
}
