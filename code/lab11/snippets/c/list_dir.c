#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

static void print_entry(const char *dirpath, const char *name) {
	char path[1024];
	snprintf(path, sizeof(path), "%s/%s", dirpath, name);
	struct stat st;
	if (lstat(path, &st) == -1) {
		fprintf(stderr, "lstat(%s) failed: %s\n", path, strerror(errno));
		return;
	}
	printf("%-30s size=%lld mode=%o\n", name, (long long)st.st_size, st.st_mode & 07777);
}

int main(int argc, char **argv) {
	const char *dirpath = (argc > 1) ? argv[1] : ".";
	DIR *d = opendir(dirpath);
	if (!d) {
		fprintf(stderr, "opendir(%s) failed: %s\n", dirpath, strerror(errno));
		return 1;
	}
	printf("Listing: %s\n", dirpath);
	struct dirent *de;
	while ((de = readdir(d)) != NULL) {
		print_entry(dirpath, de->d_name);
	}
	closedir(d);
	return 0;
}


