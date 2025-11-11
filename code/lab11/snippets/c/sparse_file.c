#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main(void) {
	const char *path = "bin/sparse_demo.bin";
	if (mkdir("bin", 0777) == -1 && errno != EEXIST) {
		perror("mkdir bin");
		return 1;
	}
	int fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1) { perror("open"); return 1; }
	// Write at start
	const char *a = "A";
	if (write(fd, a, 1) != 1) perror("write A");
	// Seek forward to create a hole
	off_t hole = 10 * 1024 * 1024; // 10 MiB hole
	if (lseek(fd, hole, SEEK_CUR) == (off_t)-1) perror("lseek");
	const char *b = "B";
	if (write(fd, b, 1) != 1) perror("write B");
	close(fd);

	struct stat st;
	if (stat(path, &st) == -1) { perror("stat"); return 1; }
	printf("Sparse file: %s\n", path);
	printf("Logical size: %lld bytes\n", (long long)st.st_size);
	printf("Blocks: %lld (block size=%lld)\n", (long long)st.st_blocks, (long long)st.st_blksize);
	printf("Note: Allocated blocks << logical size due to hole.\n");
	return 0;
}


