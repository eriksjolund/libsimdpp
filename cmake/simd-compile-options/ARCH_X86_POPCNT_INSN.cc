#include <nmmintrin.h>
#include <iostream>

unsigned* prevent_optimization(unsigned* ptr)
{
    volatile bool never = false;
    if (never) {
        while (*ptr++)
            std::cout << *ptr;
    }
    unsigned* volatile* volatile opaque;
    opaque = &ptr;
    return *opaque;
}

int main()
{
    unsigned data;
    unsigned* p = &data;
    p = prevent_optimization(p);

    *p = _mm_popcnt_u32(*p);

    p = prevent_optimization(p);
}
