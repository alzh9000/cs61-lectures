#include <cstdio>
#include "hexdump.hh"

int main() {
    int i = 1;
    unsigned u = 1;

    hexdump_object(i);
    hexdump_object(u);
}
