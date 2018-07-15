#include <msa.h>
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
        v4i32 align;
    };
    char* p = data;
    p = prevent_optimization(p);

    v16i8 v = __msa_ld_b(p, 0);
    v = __msa_add_a_b(v, v);
    __msa_st_b(v, p, 0);

    p = prevent_optimization(p);
}
