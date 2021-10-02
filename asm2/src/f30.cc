//! -O1

struct small { char a1, a2; };
int f(small s) {
    return s.a1 + 2 * s.a2;
}
