#include <cstdint>
#include <cstdio>
#include "hexdump.hh"

int main() {
    int a[2] = {61, 62};

    int* p1 = &a[1];
    int* p2 = &a[0];

    uintptr_t diff1 = (uintptr_t) p1 - (uintptr_t) p2;
    uintptr_t diff2 = (uintptr_t) (p1 - p2);

    printf("diff1=%zu, diff2=%zu, p1=%p, p2=%p\n", diff1, diff2, p1, p2);
    hexdump_object(a);
}
