#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "hexdump.hh"

int main(int argc, char** argv) {
    int x;
    if (argc >= 2) {
        x = strtol(argv[1], nullptr, 0);
    } else {
        fprintf(stderr, "Usage: %s NUMBER\n", argv[0]);
        exit(1);
    }

    unsigned sum = 0;
    for (int i = 0; i < x; ++i) {
        sum += i;
    }
    printf("Sum is %u\n", sum);
}
