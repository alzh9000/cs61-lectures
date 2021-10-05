#include <cstdio>
#include <cassert>
#include <unistd.h>

[[gnu::noinline]]
int deref(int* ptr) {
    return *ptr;
}

int main(int argc, char** argv) {
    (void) argv;
    printf("Deref gives %d\n", deref(&argc));

    // ssize_t w = write(1, "Hi!\n", 4);
    // assert(w == 4);
}
