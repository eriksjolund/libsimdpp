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
        __m128 align;
    };
    char* p = data;
    p = prevent_optimization(p);

    __m128 one = _mm_load_ps((float*)p);
    one = _mm_macc_ps(one, one, one);
    _mm_store_ps((float*)p, one);

    p = prevent_optimization(p);
}
