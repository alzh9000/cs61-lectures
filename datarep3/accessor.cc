#include "hexdump.hh"
#include <cstdlib>
#include <cstring>
#include <unistd.h>

int main(int argc, char* argv[]) {
<<<<<<< HEAD
    constexpr int size = 100000000;

    // initialize a very large array of integers
    int* v = new int[size];
    for (int i = 0; i != size; ++i) {
=======
    constexpr size_t size = 100000000;

    // initialize a very large array of integers
    int* v = new int[size];
    for (size_t i = 0; i != size; ++i) {
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
        v[i] = rand();
    }

    // check for access style argument
<<<<<<< HEAD
    enum access_style { access_up, access_down, access_random };
    access_style style = access_up;
    int opt;
    while ((opt = getopt(argc, argv, "rud")) != -1) {
        if (opt == 'r') {
            style = access_random;
        } else if (opt == 'd') {
            style = access_down;
        } else if (opt == 'u') {
            style = access_up;
=======
    int style = 'u';
    int opt;
    while ((opt = getopt(argc, argv, "rdu")) != -1) {
        if (opt == 'r' || opt == 'd' || opt == 'u') {
            style = opt;
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
        }
    }

    double t0 = cputime();

    // access 10M integers in up, down, or random order
    unsigned long sum = 0;
    unsigned long rand_sum = 0;

<<<<<<< HEAD
    for (int i = 0; i != size; ++i) {
        int r = rand() % size;

        int idx = 0;
        if (style == access_up) {
            idx = i;
        } else if (style == access_down) {
            idx = size - i - 1;
        } else if (style == access_random) {
=======
    for (size_t i = 0; i != size; ++i) {
        int r = rand() % size;

        int idx = 0;
        if (style == 'u') {
            idx = i;
        } else if (style == 'd') {
            idx = size - i - 1;
        } else if (style == 'r') {
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
            idx = r;
        }

        sum += v[idx];
        rand_sum += r;
    }

    double t1 = cputime();

<<<<<<< HEAD
    printf("accessed %d integers in %.09f sec\n", size, t1 - t0);
=======
    printf("accessed %zu integers, order %c, in %.09f sec\n", size, style, t1 - t0);
>>>>>>> 3564f1926423eea813da2a56dab9bb188e3260a2
    printf("sum: %lu, rand_sum: %lu\n", sum, rand_sum);
}
