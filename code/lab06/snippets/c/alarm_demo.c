#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void alarm_handler(int signum) {
    printf("\n[handler] Caught signal %d (SIGALRM)\n", signum);
    printf("[handler] Timer expired! Child PID=%d\n", getpid());
    fflush(stdout);
}

int main(void) {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    
    if (pid == 0) {
        // Child process
        printf("[child ] PID=%d: Registering alarm handler\n", getpid());
        fflush(stdout);
        
        // Register signal handler for SIGALRM
        if (signal(SIGALRM, alarm_handler) == SIG_ERR) {
            perror("signal");
            _exit(1);
        }
        
        // Set alarm for 3 seconds
        printf("[child ] PID=%d: Setting alarm for 3 seconds\n", getpid());
        fflush(stdout);
        alarm(3);
        
        // Print messages for 5 seconds
        int count = 0;
        while (count < 5) {
            printf("[child ] Message %d (still running...)\n", ++count);
            fflush(stdout);
            sleep(1);
        }
        
        printf("[child ] PID=%d: Exiting\n", getpid());
        fflush(stdout);
        _exit(0);
    } else {
        // Parent process
        printf("[parent] PID=%d: Spawned child PID=%d\n", getpid(), pid);
        printf("[parent] Waiting for child to complete...\n");
        fflush(stdout);
        
        int status;
        waitpid(pid, &status, 0);
        
        printf("[parent] Child exited with status %d\n", WEXITSTATUS(status));
    }
    
    return 0;
}

