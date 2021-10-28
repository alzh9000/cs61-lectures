#include <cstdio>
#include <cassert>
#include <unistd.h>

int main() {
    ssize_t nw = write(1, "Hello, world\n", 13);
    assert(nw == 13);
}
