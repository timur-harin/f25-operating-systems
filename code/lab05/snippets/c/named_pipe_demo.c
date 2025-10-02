#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define FIFO_PATH "/tmp/demo_fifo"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    // Remove old fifo if exists
    unlink(FIFO_PATH);

    // Create named pipe (FIFO)
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

    printf("[parent] PID=%d: Created named pipe at %s\n", getpid(), FIFO_PATH);
    fflush(stdout);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        unlink(FIFO_PATH);
        return 1;
    }

    if (pid == 0) {
        // Child process: reader
        printf("[child ] PID=%d: Opening FIFO for reading...\n", getpid());
        fflush(stdout);

        int fd = open(FIFO_PATH, O_RDONLY);
        if (fd == -1) {
            perror("open");
            _exit(1);
        }

        char buffer[BUFFER_SIZE];
        ssize_t n = read(fd, buffer, BUFFER_SIZE - 1);
        if (n > 0) {
            buffer[n] = '\0';
            printf("[child ] PID=%d: Received from FIFO: \"%s\"\n", getpid(), buffer);
        }

        close(fd);
        _exit(0);
    } else {
        // Parent process: writer
        sleep(1); // Ensure child opens first

        printf("[parent] PID=%d: Opening FIFO for writing...\n", getpid());
        fflush(stdout);

        int fd = open(FIFO_PATH, O_WRONLY);
        if (fd == -1) {
            perror("open");
            unlink(FIFO_PATH);
            return 1;
        }

        const char *message = argv[1];
        printf("[parent] PID=%d: Writing to FIFO: \"%s\"\n", getpid(), message);
        fflush(stdout);

        write(fd, message, strlen(message));
        close(fd);

        // Wait for child
        int status;
        waitpid(pid, &status, 0);

        // Cleanup
        unlink(FIFO_PATH);
        printf("[parent] PID=%d: Cleaned up FIFO\n", getpid());
    }

    return 0;
}

