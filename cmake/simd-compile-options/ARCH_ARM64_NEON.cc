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

    uint32x4_t one = vld1q_u32((uint32_t*)(*p));
    one = vaddq_u32(one, one);

    // GCC 4.8 misses a subset of functions
    one = vdupq_laneq_u32(one, 1);

    vst1q_u32((uint32_t*)(*p), one);
    p = prevent_optimization(p);
}
