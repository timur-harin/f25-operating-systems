#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t interrupt_count = 0;

void sigint_handler(int signum) {
    interrupt_count++;
    
    if (interrupt_count == 1) {
        printf("\n[handler] Caught signal %d (SIGINT)\n", signum);
        printf("[handler] Interrupted! Press Ctrl+C again to exit.\n");
        fflush(stdout);
    } else {
        printf("\n[handler] Second interrupt received. Restoring default handler.\n");
        fflush(stdout);
        // Restore default handler
        signal(SIGINT, SIG_DFL);
    }
}

int main(void) {
    // Register signal handler for SIGINT
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal");
        return 1;
    }

    printf("[main  ] PID=%d: Signal handler registered for SIGINT\n", getpid());
    printf("[main  ] Running infinite loop. Press Ctrl+C to test handler.\n");
    printf("[main  ] First Ctrl+C will be caught, second will use default action.\n");
    fflush(stdout);

    int count = 0;
    while (1) {
        printf("Hello world! (iteration %d)\n", ++count);
        fflush(stdout);
        sleep(1);
    }

    return 0;
}

