#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* TODO 1: Log-Structured Filesystem (LFS) mini-sim
 * - Maintain an append-only array of records: (inode, version)
 * - Implement 'append(inode)' that bumps version and appends a record
 * - Implement 'clean()' that keeps only the latest record per inode
 */
static void cmd_lfs(void) {
	fprintf(stderr, "[TODO] Implement LFS append and clean simulation\n");
}

/* TODO 2: Journaling
 * - Simulate a transaction with begin and commit flags and a payload string
 * - Implement 'replay' that applies payload only if both begin and commit seen
 */
static void cmd_journal(void) {
	fprintf(stderr, "[TODO] Implement journaling begin/commit and replay logic\n");
}

/* TODO 3: Copy-on-Write (CoW) tree
 * - Represent a tiny binary tree and implement 'cow_update' that returns a
 *   new root with only the path nodes copied, others shared.
 * - Show that the old root is unchanged (snapshot semantics)
 */
static void cmd_cow(void) {
	fprintf(stderr, "[TODO] Implement CoW tree update and snapshot demonstration\n");
}

static void usage(const char *prog) {
	fprintf(stderr,
		"Usage: %s <command>\n"
		"Commands:\n"
		"  lfs       - log-structured FS append+clean simulation\n"
		"  journal   - journaling begin/commit + replay\n"
		"  cow       - copy-on-write tree snapshot demo\n", prog);
}

int main(int argc, char **argv) {
	if (argc != 2) { usage(argv[0]); return 1; }
	if (strcmp(argv[1], "lfs") == 0) {
		cmd_lfs();
	} else if (strcmp(argv[1], "journal") == 0) {
		cmd_journal();
	} else if (strcmp(argv[1], "cow") == 0) {
		cmd_cow();
	} else {
		usage(argv[0]);
		return 1;
	}
	return 0;
}


