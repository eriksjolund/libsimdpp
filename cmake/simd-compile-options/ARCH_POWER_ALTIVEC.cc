#include <altivec.h>
#include <iostream>

#if defined(__GNUC__) && (__GNUC__ < 6) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#if !defined(__INTEL_COMPILER) && !defined(__clang__)
#error GCC 5.0 and older are not supported on PPC little-endian. See simdpp/detail/workarounds.h
#endif
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
        char data[16];
        vector unsigned char align;
    };
    char* p = data;
    p = prevent_optimization(p);

    vector unsigned char v = vec_ld(0, (unsigned char*)p);
    v = vec_add(v, v);
    vec_st(v, 0, (unsigned char*)p);

    p = prevent_optimization(p);
}
