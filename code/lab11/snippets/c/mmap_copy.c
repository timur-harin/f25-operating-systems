#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv) {
	const char *src = (argc > 1) ? argv[1] : "README.md";
	const char *dst = (argc > 2) ? argv[2] : "bin/mmap_copy.out";

	if (mkdir("bin", 0777) == -1 && errno != EEXIST) {
		perror("mkdir bin");
		return 1;
	}
	int in = open(src, O_RDONLY);
	if (in == -1) { fprintf(stderr, "open(%s): %s\n", src, strerror(errno)); return 1; }
	struct stat st;
	if (fstat(in, &st) == -1) { perror("fstat"); close(in); return 1; }
	size_t len = (size_t)st.st_size;
	if (len == 0) { printf("Source is empty, nothing to copy.\n"); close(in); return 0; }

	void *map = mmap(NULL, len, PROT_READ, MAP_PRIVATE, in, 0);
	if (map == MAP_FAILED) { perror("mmap"); close(in); return 1; }

	int out = open(dst, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (out == -1) { perror("open out"); munmap(map, len); close(in); return 1; }
	if (ftruncate(out, (off_t)len) == -1) { perror("ftruncate"); }

	void *omap = mmap(NULL, len, PROT_WRITE | PROT_READ, MAP_SHARED, out, 0);
	if (omap == MAP_FAILED) { perror("mmap out"); close(out); munmap(map, len); close(in); return 1; }

	memcpy(omap, map, len);
	if (msync(omap, len, MS_SYNC) == -1) perror("msync");

	munmap(omap, len);
	munmap(map, len);
	close(out);
	close(in);
	printf("Copied %zu bytes from %s to %s using mmap.\n", len, src, dst);
	return 0;
}


