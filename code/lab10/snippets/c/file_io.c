#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main(void) {
	const char *path = "bin/io_demo.txt";
	const char *msg1 = "Hello, filesystem!\n";
	const char *msg2 = "Appended line.\n";

	if (mkdir("bin", 0777) == -1 && errno != EEXIST) {
		perror("mkdir bin");
		return 1;
	}

	int fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1) {
		fprintf(stderr, "open(%s) failed: %s\n", path, strerror(errno));
		return 1;
	}
	ssize_t w = write(fd, msg1, strlen(msg1));
	if (w < 0) perror("write");
	if (fsync(fd) == -1) perror("fsync");
	close(fd);

	fd = open(path, O_WRONLY | O_APPEND);
	if (fd == -1) { perror("open append"); return 1; }
	w = write(fd, msg2, strlen(msg2));
	if (w < 0) perror("write append");
	close(fd);

	fd = open(path, O_RDONLY);
	if (fd == -1) { perror("open read"); return 1; }
	char buf[256];
	ssize_t r;
	printf("=== File content (%s) ===\n", path);
	while ((r = read(fd, buf, sizeof(buf))) > 0) {
		fwrite(buf, 1, (size_t)r, stdout);
	}
	if (r < 0) perror("read");
	close(fd);
	return 0;
}


