#if defined(__clang_major__)
#if (__clang_major__ < 3) || ((__clang_major__ == 3) && (__clang_minor__ <= 3))
#error NEON is not supported on clang 3.3 and earlier.
#endif
#endif

#include <arm_neon.h>
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
        uint32x4_t align;
    };
    char* p = data;
    p = prevent_optimization(p);

    uint32x4_t one = vld1q_u32((uint32_t*)p);
    one = vaddq_u32(one, one);
    vst1q_u32((uint32_t*)p, one);

    p = prevent_optimization(p);
}
