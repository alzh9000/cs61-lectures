#include <cstdio>
#include "hexdump.hh"

int main() {
    struct {
        int a;
        int b;
        char c;
        char d;
    } s1 = {61, 62, 63, 64};

    struct {
        int a;
        char b;
        int c;
        char d;
    } s2 = {61, 62, 63, 64};

    hexdump_object(s1);
    hexdump_object(s2);
}
