#include "helpers.hh"
bool quiet = false;
double exit_delay = 0.5;
double timeout = 0.75;
int signalpipe[2];

void signal_handler(int signal) {
    const char* msg = signal == SIGCHLD ? "E" : "T";
    ssize_t r = write(signalpipe[1], msg, 1);
    assert(r == 1);
}

int main(int argc, char** argv) {
    parse_arguments(argc, argv);

    // Create the signal pipe
    int r = pipe(signalpipe);
    assert(r >= 0);

    // SIGCHLD writes `E` to the pipe, SIGALRM writes `T`
    r = set_signal_handler(SIGCHLD, signal_handler);
    assert(r >= 0);
    r = set_signal_handler(SIGALRM, signal_handler);
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

    // `read` will either succeed or be interrupted by a signal
    // (either SIGCHLD or SIGALRM); we don’t care which!
    char c;
    ssize_t n = read(signalpipe[0], &c, 1);
    (void) n;

    // Check if child exited
    int status;
    pid_t exited_pid = waitpid(p1, &status, WNOHANG);
    assert(exited_pid == 0 || exited_pid == p1);

    // Print results
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
