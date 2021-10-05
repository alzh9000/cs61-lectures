#include <cstdio>

[[gnu::noinline]] int deref(int* ptr) {
	return *ptr;
}

int main(int argc, char** argv) {
    (void) argv;
    printf("Deref gives %d\n", deref(&argc));
}
