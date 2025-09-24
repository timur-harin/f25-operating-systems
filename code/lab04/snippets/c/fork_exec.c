#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    fflush(NULL);
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        // Child: replace image with a shell that prints IDs and sleeps.
        // Portable across Linux/macOS.
        const char *cmd = "echo child exec: PID=$$ PPID=$PPID; ps -o pid,ppid,pgid,stat,command -p $$; sleep 5";
        execlp("sh", "sh", "-c", cmd, (char *)NULL);
        perror("execlp");
        _exit(127);
    } else {
        printf("[parent] PID=%d: forked child PID=%d; waiting for it...\n", getpid(), pid);
        fflush(stdout);
        int status = 0;
        if (waitpid(pid, &status, 0) < 0) {
            perror("waitpid");
            return 1;
        }
        if (WIFEXITED(status)) {
            printf("[parent] child exited with code %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("[parent] child killed by signal %d\n", WTERMSIG(status));
        }
        fflush(stdout);
    }
    return 0;
}


