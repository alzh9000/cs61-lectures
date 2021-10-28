#include <cstdio>
#include <cassert>

struct intnode {
    int i;
    intnode* next;
};

int main() {
    // integer set, implemented as a linked list
    intnode* iset = nullptr;

    // read integers from stdin, insert them in sorted order
    int num;
    while (scanf("%d", &num) == 1) {
        // find insertion position
        intnode* prev = nullptr;
        intnode* pos = iset;
        while (pos != nullptr && pos->i < num) {
            prev = pos;
            pos = pos->next;
        }
        // add node at insertion position
        intnode* n = new intnode;
        n->i = num;
        n->next = pos;
        if (prev != nullptr) {
            prev->next = n;
        } else {
            iset = n;
        }
    }
    assert(feof(stdin));

    // print integers in sorted order
    for (intnode* pos = iset; pos != nullptr; pos = pos->next) {
        printf("%d\n", pos->i);
    }
}
