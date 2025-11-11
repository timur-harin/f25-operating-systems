#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int inode;
	char data[32];
} log_record;

typedef struct {
	log_record records[128];
	int len;
} segment;

static void append(segment *seg, int inode, const char *data) {
	if (seg->len >= 128) {
		printf("[LFS] Segment full, cannot append.\n");
		return;
	}
	seg->records[seg->len].inode = inode;
	snprintf(seg->records[seg->len].data, sizeof(seg->records[seg->len].data), "%s", data);
	seg->len++;
}

static void summarize(const segment *seg) {
	printf("[LFS] Segment summary: %d records\n", seg->len);
	for (int i = 0; i < seg->len; i++) {
		printf("  rec[%02d]: inode=%d data=\"%s\"\n", i, seg->records[i].inode, seg->records[i].data);
	}
}

static void clean(segment *seg) {
	// Simple cleaner: keep only last update per inode
	int last_for_inode[256];
	for (int i = 0; i < 256; i++) last_for_inode[i] = -1;
	for (int i = 0; i < seg->len; i++) last_for_inode[seg->records[i].inode] = i;
	segment out = { .len = 0 };
	for (int i = 0; i < seg->len; i++) {
		if (last_for_inode[seg->records[i].inode] == i) {
			append(&out, seg->records[i].inode, seg->records[i].data);
		}
	}
	*seg = out;
}

int main(void) {
	segment seg = { .len = 0 };
	printf("[LFS] Append records to log...\n");
	append(&seg, 1, "A1");
	append(&seg, 2, "B1");
	append(&seg, 1, "A2");
	append(&seg, 3, "C1");
	append(&seg, 2, "B2");
	summarize(&seg);
	printf("[LFS] Clean segment (keep latest per inode)...\n");
	clean(&seg);
	summarize(&seg);
	return 0;
}


