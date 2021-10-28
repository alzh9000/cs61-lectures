#include <cstdio>
#include <cassert>
#include <vector>

int main() {
    // integer set, implemented (by the C++ standard library) as a growable array
    std::vector<int> iset;

    // read integers from stdin, storing them in sorted order
    int num;
    while (scanf("%d", &num) == 1) {
        auto it = std::lower_bound(iset.begin(), iset.end(), num);
        iset.insert(it, num);
    }
    assert(feof(stdin));

    // print integers in sorted order
    for (auto it = iset.begin(); it != iset.end(); ++it) {
        printf("%d\n", *it);
    }
}
