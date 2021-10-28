#include <cstdio>
#include <cassert>

const int capacity = 10000000;
int iset[capacity];

int main() {
    for (int i = 0; i != capacity; ++i) {
	iset[i] = i;
    }

    // read integers from stdin, access `iset`
    size_t sum = 0;
    size_t count = 0;
    int num;
    while (scanf("%d", &num) == 1) {
        assert(num < capacity);
	sum += iset[num];
	++count;
    }
    assert(feof(stdin));

    printf("read %zu integers, sum %zu\n", count, sum);
}
