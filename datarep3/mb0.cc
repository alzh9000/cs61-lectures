#include "membench.hh"
#include <random>

struct node {
    long contents;
};


unsigned long memnode_benchmark(unsigned noperations, int seed) {
    const int nnodes = 8192;
    node* n[nnodes];
    for (int i = 0; i != nnodes; ++i) {
        n[i] = nullptr;
    }

    std::minstd_rand randomness(seed);
    std::uniform_int_distribution<int> random_node_index(0, nnodes - 1);

    // allocate and free nodes `noperations` times
    long counter = 0;
    for (unsigned i = 0; i != noperations; ++i) {
        int pos = random_node_index(randomness);
        if (n[pos] == nullptr) {
            n[pos] = new node;
            n[pos]->contents = counter;
            ++counter;
        } else {
            delete n[pos];
            n[pos] = nullptr;
        }
    }

    // compute a statistic from the remaining nodes and free them
    unsigned long result = 0;
    for (int i = 0; i != nnodes; ++i) {
        if (n[i]) {
            result += n[i]->contents;
            delete n[i];
        }
    }
    return result;
}
