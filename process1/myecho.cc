#include "helpers.hh"

int main(int argc, char* argv[]) {
    fprintf(stderr, "myecho[%d]: running\n", getpid());
    for (int i = 0; i != argc; ++i) {
        fprintf(stderr, "myecho[%d]: argv[%d] @%p: \"%s\"\n",
        getpid(), i, argv[i], argv[i]);
    }
}
