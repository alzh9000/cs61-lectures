#include "helpers.hh"
bool quiet = false;
double exit_delay = 0.5;
double timeout = 0.75;

void signal_handler(int signal) {
    (void) signal;
}

int main(int argc, char** argv) {
    parse_arguments(argc, argv);

    // Demand that SIGALRM interrupt system calls
    int r = set_signal_handler(SIGALRM, signal_handler);
    assert(r >= 0);

    double start_time = tstamp();

    // Start child
    pid_t p1 = fork();
    assert(p1 >= 0);
    if (p1 == 0) {
        if (exit_delay > 0.0) {
            usleep((unsigned) (exit_delay * 1000000));
        }
        if (!quiet) {
            fprintf(stderr, "%s[%d]: child exiting\n", argv[0], getpid());
        }
        exit(0);
    }

    // Set an alarm for `timeout` sec, after which kernel delivers SIGALRM
    struct itimerval itimer;
    timerclear(&itimer.it_interval);
    itimer.it_value = make_timeval(timeout);
    r = setitimer(ITIMER_REAL, &itimer, nullptr);
    assert(r >= 0);

    // Wait for child to exit or alarm; alarm will interrupt `waitpid`
    int status;
    pid_t exited_pid = waitpid(p1, &status, 0);

    // Print results
    if (exited_pid == -1 && errno == EINTR) {
        fprintf(stderr, "%s[%d]: parent interrupted by signal after %g sec\n",
                argv[0], getpid(), tstamp() - start_time);
        exit(0);
    }

    assert(exited_pid == 0 || exited_pid == p1);
    if (exited_pid == 0) {
        fprintf(stderr, "%s[%d]: child %d timed out\n", argv[0], getpid(), p1);
    } else if (WIFEXITED(status)) {
        double lifetime = tstamp() - start_time;
        if (!quiet || lifetime > exit_delay + 0.1) {
            fprintf(stderr, "%s[%d]: child %d exited with status %d after %g sec\n",
                    argv[0], getpid(), p1, WEXITSTATUS(status), lifetime);
        }
    } else {
        fprintf(stderr, "%s[%d]: child %d exited abnormally [%x]\n",
                argv[0], getpid(), p1, status);
    }
}
