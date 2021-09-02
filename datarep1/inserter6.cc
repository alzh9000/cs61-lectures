#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

int main() {
    // integer set, implemented (by the C++ standard library) as a growable array
    std::vector<int> iset;

    // read integers from stdin, storing them in UNSORTED order
    int num;
    while (scanf("%d", &num) == 1) {
        iset.push_back(num);
    }
    assert(feof(stdin));

    // print integers in sorted order
    std::sort(iset.begin(), iset.end());
    for (auto it = iset.begin(); it != iset.end(); ++it) {
        printf("%d\n", *it);
    }
}
