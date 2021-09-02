#include <cstdio>
#include <cassert>
#include <set>

int main() {
    // integer set, implemented (by the C++ standard library) as a binary tree
    std::multiset<int> iset;

    // read integers from stdin, storing them in sorted order
    int num;
    while (scanf("%d", &num) == 1) {
        iset.insert(num);
    }
    assert(feof(stdin));

    // print integers in sorted order
    for (auto it = iset.begin(); it != iset.end(); ++it) {
        printf("%d\n", *it);
    }
}
