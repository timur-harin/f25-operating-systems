#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>

void sigusr1_handler(int signum) {
    printf("\n[handler] Caught signal %d (SIGUSR1)\n", signum);
    printf("[handler] Error: Input appears to be negative!\n");
    printf("[handler] Please enter a positive number.\n");
    fflush(stdout);
}

void sigusr2_handler(int signum) {
    printf("\n[handler] Caught signal %d (SIGUSR2)\n", signum);
    printf("[handler] Error: Input is not a valid number!\n");
    printf("[handler] Please enter digits only.\n");
    fflush(stdout);
}

int main(void) {
    // Register signal handlers
    if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR) {
        perror("signal SIGUSR1");
        return 1;
    }
    if (signal(SIGUSR2, sigusr2_handler) == SIG_ERR) {
        perror("signal SIGUSR2");
        return 1;
    }

    printf("[main  ] PID=%d: Signal handlers registered\n", getpid());
    printf("[main  ] SIGUSR1: triggered on negative numbers (starts with '-')\n");
    printf("[main  ] SIGUSR2: triggered on non-numeric input\n");
    printf("[main  ] Enter 'quit' to exit\n\n");
    fflush(stdout);

    char input[256];
    while (1) {
        printf("Enter a positive integer: ");
        fflush(stdout);
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        // Remove newline
        input[strcspn(input, "\n")] = 0;
        
        if (strcmp(input, "quit") == 0) {
            printf("[main  ] Exiting...\n");
            break;
        }
        
        // Check if starts with '-'
        if (input[0] == '-') {
            printf("[main  ] Raising SIGUSR1...\n");
            fflush(stdout);
            raise(SIGUSR1);
            continue;
        }
        
        // Check if all characters are digits
        int is_number = 1;
        for (size_t i = 0; i < strlen(input); i++) {
            if (!isdigit((unsigned char)input[i])) {
                is_number = 0;
                break;
            }
        }
        
        if (!is_number) {
            printf("[main  ] Raising SIGUSR2...\n");
            fflush(stdout);
            raise(SIGUSR2);
            continue;
        }
        
        // Valid positive integer
        printf("[main  ] Valid input: %s\n", input);
        fflush(stdout);
    }

    return 0;
}

