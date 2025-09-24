#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    fflush(NULL);
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        // Child: parent will exit; observe PPID change to 1 (init/systemd or launchd).
        printf("[child ] PID=%d initial PPID=%d\n", getpid(), getppid());
        fflush(stdout);
        sleep(5);
        printf("[child ] PID=%d after parent exit, new PPID=%d (adopted)\n", getpid(), getppid());
        fflush(stdout);
        sleep(10);
        printf("[child ] exiting\n");
        fflush(stdout);
        _exit(0);
    } else {
        // Parent exits quickly, making the child an orphan.
        printf("[parent] PID=%d: spawned child PID=%d; exiting now to orphan the child.\n", getpid(), pid);
        fflush(stdout);
        _exit(0);
    }
}


