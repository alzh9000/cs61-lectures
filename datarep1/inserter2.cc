#include <cstdio>
#include <cassert>

int main() {
    // integer set, implemented as a growing array
    int* iset = nullptr;
    int size = 0;

    // read integers from stdin, insert them in sorted order
    int num;
    while (scanf("%d", &num) == 1) {
        // allocate new set
        int* nset = new int[size + 1];
        // copy smaller data, looking for insertion position
        int pos = 0;
        while (pos != size && iset[pos] < num) {
            nset[pos] = iset[pos];
            ++pos;
        }
        // insert element
        nset[pos] = num;
        ++pos;
        // copy larger data
        while (pos <= size) {
            nset[pos] = iset[pos - 1];
            ++pos;
        }
        ++size;
        // deallocate old set
        delete[] iset;
        iset = nset;
    }
    assert(feof(stdin));

    // print integers
    for (int i = 0; i != size; ++i) {
        printf("%d\n", iset[i]);
    }
}
