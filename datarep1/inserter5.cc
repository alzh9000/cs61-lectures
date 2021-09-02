#include <cstdio>
#include <cassert>
#include <forward_list>

int main() {
    // integer set, implemented (by the C++ standard library) as a singly-linked list
    std::forward_list<int> iset;

    // read integers from stdin, storing them in sorted order
    int num;
    while (scanf("%d", &num) == 1) {
        if (iset.empty() || iset.front() >= num) {
            iset.push_front(num);
        } else {
            auto prev = iset.begin();
            auto it = iset.begin();
            while (it != iset.end() && *it < num) {
                prev = it;
                ++it;
            }
            iset.insert_after(prev, num);
        }
    }
    assert(feof(stdin));

    // print integers in sorted order
    for (auto it = iset.begin(); it != iset.end(); ++it) {
        printf("%d\n", *it);
    }
}
