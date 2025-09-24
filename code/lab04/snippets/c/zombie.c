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
        // Child: exit immediately so parent can keep us as a zombie (no wait).
        printf("[child ] PID=%d PPID=%d: exiting to become zombie until parent waits\n", getpid(), getppid());
        fflush(stdout);
        _exit(0);
    } else {
        // Parent: do not call wait(); sleep to keep child in zombie state.
        printf("[parent] PID=%d: spawned child PID=%d; NOT calling wait().\n", getpid(), pid);
        printf("[parent] Observe with: pstree -p %d  (or ps)\n", getpid());
        fflush(stdout);
        sleep(30);
        printf("[parent] Done sleeping; exiting now (zombie will be reaped by init/launchd).\n");
        fflush(stdout);
    }
    return 0;
}


