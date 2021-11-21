#include <cstdio>
#include <thread>
#include <sstream>
#include <unistd.h>

// Return a `std::string` for a thread ID
std::string tid2str(std::thread::id tid) {
    std::stringstream buf;
    buf << tid;
    return buf.str();
}

// Any function returning `void` can be a thread entry point
void simple_thread() {
    char buf[100];
    usleep(100);
    printf("%d:%s: Hello from thread! `buf` == %p\n",
           getpid(), tid2str(std::this_thread::get_id()).c_str(), buf);
    usleep(1000000);
}

void thread_with_argument(int arg) {
    printf("%d:%s: Hello from thread(%d)!\n",
           getpid(), tid2str(std::this_thread::get_id()).c_str(), arg);
    usleep(1000000);
}


int main() {
    printf("%d:%s: Hello from the main thread!\n\n",
           getpid(), tid2str(std::this_thread::get_id()).c_str());


    // Start two threads that run in parallel.
    // Each thread is running the `simple_thread` function as an
    // entry point. When that function returns, the thread exits.
    std::thread t0 = std::thread(simple_thread);
    printf("%d:%s: Created thread %s\n",
           getpid(), tid2str(std::this_thread::get_id()).c_str(),
           tid2str(t0.get_id()).c_str());

    std::thread t1 = std::thread(simple_thread);
    printf("%d:%s: Created thread %s\n",
           getpid(), tid2str(std::this_thread::get_id()).c_str(),
           tid2str(t1.get_id()).c_str());

    // Wait for the threads to complete
    t0.join();
    t1.join();

    printf("%d:%s: Threads have completed!\n\n",
           getpid(), tid2str(std::this_thread::get_id()).c_str());


    // It is also possible to pass arguments to a thread.
    t0 = std::thread(thread_with_argument, 1);
    printf("%d:%s: Created thread %s (argument 1)\n",
           getpid(), tid2str(std::this_thread::get_id()).c_str(),
           tid2str(t0.get_id()).c_str());

    t1 = std::thread(thread_with_argument, 2);
    printf("%d:%s: Created thread %s (argument 2)\n",
           getpid(), tid2str(std::this_thread::get_id()).c_str(),
           tid2str(t1.get_id()).c_str());

    // Wait for the threads to complete
    t0.join();
    t1.join();

    printf("%d:%s: Threads have completed!\n\n",
           getpid(), tid2str(std::this_thread::get_id()).c_str());


    // A “detached” thread runs totally independently & cannot be joined.
    std::thread(thread_with_argument, 1000).detach();
}
