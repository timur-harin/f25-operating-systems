#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static void die(const char *msg) {
	perror(msg);
	exit(EXIT_FAILURE);
}

/* TODO 1: Directory traversal
 * - use opendir/readdir to iterate entries of `path`
 * - call lstat on each entry and print size + permissions (hint: st_mode & 07777)
 */
static void cmd_list(const char *path) {
	(void)path;
	fprintf(stderr, "[TODO] Implement cmd_list() using opendir/readdir/lstat\n");
	/* Sample output format:
	 *   printf("%-25s size=%lld mode=%o\n", name, (long long)st.st_size, st.st_mode & 07777);
	 */
}

/* TODO 2: Inode metadata
 * - call lstat on `path`
 * - print inode, device, number of blocks, owner ids, timestamps (use st_mtime)
 */
static void cmd_stat(const char *path) {
	(void)path;
	fprintf(stderr, "[TODO] Implement cmd_stat() to inspect struct stat fields\n");
}

/* TODO 3: Robust file I/O demo
 * - create ./work/io_demo.txt (create parent dir if needed)
 * - open with O_CREAT|O_WRONLY|O_TRUNC, write a greeting, fsync, close
 * - reopen with O_WRONLY|O_APPEND, append a second line, close
 * - reopen with O_RDONLY and dump contents to stdout
 * - consider demonstrating short writes / EINTR handling
 */
static void cmd_io_demo(void) {
	fprintf(stderr, "[TODO] Implement cmd_io_demo() using open/write/fsync/read\n");
}

/* TODO 4: Sparse file creation
 * - create ./work/sparse.bin
 * - write a byte, lseek forward to create a hole (e.g., 8 MiB), write another byte
 * - close and stat the file to show logical size vs allocated blocks
 */
static void cmd_sparse(void) {
	fprintf(stderr, "[TODO] Implement cmd_sparse() with lseek to create a hole\n");
}

/* TODO 5: mmap-based copy
 * - open src (read-only) and dst (create/truncate)
 * - map src read-only, dst read/write using ftruncate to set size
 * - memcpy from src map to dst map, msync, cleanup
 * - print how many bytes were copied
 */
static void cmd_mmap_copy(const char *src, const char *dst) {
	(void)src;
	(void)dst;
	fprintf(stderr, "[TODO] Implement cmd_mmap_copy() using mmap + memcpy\n");
}

static void usage(const char *prog) {
	fprintf(stderr,
		"Usage: %s <command> [args]\n"
		"Commands:\n"
		"  list <path>        - traverse directory\n"
		"  stat <path>        - show inode metadata\n"
		"  io-demo            - write/read file with fsync\n"
		"  sparse             - create sparse file\n"
		"  mmap-copy <src> <dst> - copy file using mmap\n",
		prog);
}

int main(int argc, char **argv) {
	if (argc < 2) {
		usage(argv[0]);
		return EXIT_FAILURE;
	}
	if (strcmp(argv[1], "list") == 0) {
		if (argc != 3) { usage(argv[0]); return EXIT_FAILURE; }
		cmd_list(argv[2]);
	} else if (strcmp(argv[1], "stat") == 0) {
		if (argc != 3) { usage(argv[0]); return EXIT_FAILURE; }
		cmd_stat(argv[2]);
	} else if (strcmp(argv[1], "io-demo") == 0) {
		cmd_io_demo();
	} else if (strcmp(argv[1], "sparse") == 0) {
		cmd_sparse();
	} else if (strcmp(argv[1], "mmap-copy") == 0) {
		if (argc != 4) { usage(argv[0]); return EXIT_FAILURE; }
		cmd_mmap_copy(argv[2], argv[3]);
	} else {
		usage(argv[0]);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}


