#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

static void print_mode(mode_t m) {
	char p[11] = "----------";
	if (S_ISDIR(m)) p[0] = 'd';
	else if (S_ISLNK(m)) p[0] = 'l';
	else if (S_ISCHR(m)) p[0] = 'c';
	else if (S_ISBLK(m)) p[0] = 'b';
	else if (S_ISSOCK(m)) p[0] = 's';
	else if (S_ISFIFO(m)) p[0] = 'p';
	if (m & S_IRUSR) p[1] = 'r';
	if (m & S_IWUSR) p[2] = 'w';
	if (m & S_IXUSR) p[3] = 'x';
	if (m & S_IRGRP) p[4] = 'r';
	if (m & S_IWGRP) p[5] = 'w';
	if (m & S_IXGRP) p[6] = 'x';
	if (m & S_IROTH) p[7] = 'r';
	if (m & S_IWOTH) p[8] = 'w';
	if (m & S_IXOTH) p[9] = 'x';
	printf("%s", p);
}

int main(int argc, char **argv) {
	const char *path = (argc > 1) ? argv[1] : ".";
	struct stat st;
	if (lstat(path, &st) == -1) {
		fprintf(stderr, "lstat(%s) failed: %s\n", path, strerror(errno));
		return 1;
	}
	printf("Path: %s\n", path);
	printf("Device: %lld\n", (long long)st.st_dev);
	printf("Inode: %lld\n", (long long)st.st_ino);
	printf("Mode: "); print_mode(st.st_mode); printf(" (%o)\n", st.st_mode & 07777);
	printf("Links: %lld\n", (long long)st.st_nlink);
	printf("UID: %lld GID: %lld\n", (long long)st.st_uid, (long long)st.st_gid);
	printf("Size: %lld bytes\n", (long long)st.st_size);
	printf("Block size: %lld bytes\n", (long long)st.st_blksize);
	printf("Blocks: %lld\n", (long long)st.st_blocks);
	return 0;
}


