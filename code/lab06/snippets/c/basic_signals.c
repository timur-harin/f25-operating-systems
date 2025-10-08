#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void) {
    printf("[main  ] PID=%d: Running infinite loop...\n", getpid());
    printf("[main  ] Press Ctrl+C (SIGINT) to terminate\n");
    printf("[main  ] Press Ctrl+\\ (SIGQUIT) to quit with core dump\n");
    printf("[main  ] Or use 'kill -SIGTERM %d' from another terminal\n", getpid());
    fflush(stdout);

    int count = 0;
    while (1) {
        printf("Hello world! (iteration %d)\n", ++count);
        fflush(stdout);
        sleep(1);
    }

    return 0;
}

