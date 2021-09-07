#include <cstdio>
#include "hexdump.hh"

int main() {
    int a[2] = {61, 62};

    union {
        int a;
        int b;
        char c;
        char d;
    } u;
    u.a = 61;

    struct {
        int a;
        int b;
        char c;
        char d;
    } s = {61, 62, 63, 64};

    hexdump_object(a);
    hexdump_object(u);
    hexdump_object(s);
}
