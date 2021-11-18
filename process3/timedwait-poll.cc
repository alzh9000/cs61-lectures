#include "helpers.hh"
bool quiet = false;
double exit_delay = 0.5;
double timeout = 0.75;

int main(int argc, char** argv) {
    parse_arguments(argc, argv);

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

    // Wait for timeout or child exit, whichever happens first, by polling
    int status;
    pid_t exited_pid = 0;
    while (tstamp() - start_time < timeout && exited_pid == 0) {
        exited_pid = waitpid(p1, &status, WNOHANG);
        assert(exited_pid == 0 || exited_pid == p1);
    }

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
