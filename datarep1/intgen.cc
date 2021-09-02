#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <random>

template <typename T, typename G>
T uniform_int_between(T min, T max, G& generator) {
    std::uniform_int_distribution<T> distribution(min, max);
    return distribution(generator);
}

int main(int argc, char** argv) {
    int n = 6;
    int order = 'r';

    // parse command line arguments
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-r") == 0
            || strcmp(argv[i], "-u") == 0
            || strcmp(argv[i], "-d") == 0
            || strcmp(argv[i], "-m") == 0) {
            order = argv[i][1];
        } else if (strcmp(argv[i], "-n") == 0) {
            n = strtol(argv[i + 1], NULL, 0);
            assert(n > 0);
            ++i;
        } else {
            fprintf(stderr, "Usage: %s [-r|-u|-d|-m] [-n SIZE]\n", argv[0]);
            exit(1);
        }
    }

    // print `n` integers according to `order`
    if (order == 'u') {
        // ascending order
        for (int i = 0; i != n; ++i) {
            printf("%d\n", i);
        }

    } else if (order == 'd') {
        // descending order
        for (int i = n; i != 0; --i) {
            printf("%d\n", i - 1);
        }

    } else if (order == 'r') {
        // random order
        std::default_random_engine randomness((std::random_device())());
        // We want no duplicates, which requires some work!
        int* v = new int[n];
        for (int i = 0; i != n; ++i) {
            v[i] = i;
        }
        while (n != 0) {
            int idx = uniform_int_between(0, n - 1, randomness);
            printf("%d\n", v[idx]);
            v[idx] = v[n - 1];
            --n;
        }
        delete[] v;

    } else if (order == 'm') {
        // magic order
        int z = 0;
        for (int i = 0; i != (n + 1) / 2; ++i) {
            printf("%d\n", z);
            z += 2;
        }
        z -= n % 2 ? 3 : 1;
        for (int i = (n + 1) / 2; i != n; ++i) {
            printf("%d\n", z);
            z -= 2;
        }
    }
}
