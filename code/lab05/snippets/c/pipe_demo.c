#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    printf("[parent] PID=%d: Created pipe (read_fd=%d, write_fd=%d)\n", 
           getpid(), pipefd[0], pipefd[1]);
    fflush(stdout);

    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process: reads from pipe
        close(pipefd[1]); // Close write end
        
        printf("[child ] PID=%d: Waiting to read from pipe...\n", getpid());
        fflush(stdout);

        ssize_t n = read(pipefd[0], buffer, BUFFER_SIZE - 1);
        if (n > 0) {
            buffer[n] = '\0';
            printf("[child ] PID=%d: Received message: \"%s\"\n", getpid(), buffer);
            printf("[child ] PID=%d: Message length: %zd\n", getpid(), n);
        }
        
        close(pipefd[0]);
        _exit(0);
    } else {
        // Parent process: writes to pipe
        close(pipefd[0]); // Close read end
        
        // Give child time to open read end
        sleep(1);
        
        const char *message = argv[1];
        printf("[parent] PID=%d: Sending message: \"%s\"\n", getpid(), message);
        fflush(stdout);

        write(pipefd[1], message, strlen(message));
        close(pipefd[1]);

        // Wait for child
        int status;
        waitpid(pid, &status, 0);
        printf("[parent] PID=%d: Child finished\n", getpid());
    }

    return 0;
}

