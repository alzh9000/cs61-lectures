#include <cstdio>
#include <cassert>

int main() {
    // integer set, implemented as an array
    const int capacity = 100000;
    int iset[capacity];
    int size = 0;

    // read integers from stdin, insert them in sorted order
    int num;
    while (scanf("%d", &num) == 1) {
        assert(size < capacity);
        // find insertion position
        int pos = 0;
        while (pos != size && iset[pos] < num) {
            ++pos;
        }
        // insert and move other data up
        while (pos <= size) {
            int tmp = iset[pos];
            iset[pos] = num;
            num = tmp;
            ++pos;
        }
        ++size;
    }
    assert(feof(stdin));

    // print integers in sorted order
    for (int i = 0; i != size; ++i) {
        printf("%d\n", iset[i]);
    }
}
