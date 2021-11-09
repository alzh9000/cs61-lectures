#include "helpers.hh"

int main() {
    const char* childargs[] = {
        "./myecho", // argv[0] is the string used to execute the program
        "Hello, world",
        nullptr
    };

    fprintf(stderr, "execmyecho[%d]: running\n", getpid());
    for (int i = 0; childargs[i] != nullptr; ++i) {
        fprintf(stderr, "execmyecho[%d]: childargs[%d] @%p: \"%s\"\n",
        getpid(), i, childargs[i], childargs[i]);
    }

    int r = execv("./myecho", (char**) childargs);
    fprintf(stderr, "execmyecho[%d]: exec returned %d\n",
        getpid(), r);
}
