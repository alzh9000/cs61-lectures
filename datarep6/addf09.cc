#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cerrno>
#include <cstdint>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

extern "C" {

int add(int a, int b) {
    const char* file = "cs61hello.jpg";
    size_t offset = 0x9efc;

    // Load the file into memory
    int fd = open(file, O_RDONLY);
    assert(fd >= 0);

    struct stat s;
    int r = fstat(fd, &s);
    assert(r >= 0 && S_ISREG(s.st_mode) && s.st_size > 0);

    void* data = mmap(NULL, s.st_size, PROT_READ | PROT_EXEC, MAP_SHARED, fd, 0);
    assert(data != MAP_FAILED);

    // Obtain address of add function in loaded file
    uintptr_t data_address = (uintptr_t) data + offset;
    int (*add_function)(int, int) = (int (*)(int, int)) (data_address);

    // Call add function
    return add_function(a, b);
}

}
