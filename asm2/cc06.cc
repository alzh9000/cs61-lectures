//! -O3 -Wno-unused -fno-stack-protector

extern int rand();

bool nth_bit(int i, unsigned n) {
    return ((i >> n) & 1) != 0;
}

bool nth_random_bit(unsigned n) {
    return nth_bit(rand(), n);
    int i = rand();
    return ((i >> n) & 1) != 0;
}
