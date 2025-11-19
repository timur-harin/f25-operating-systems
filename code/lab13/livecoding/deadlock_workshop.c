#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int thread;
	int resource;
} request;

/* TODO 1: parse "thread resource" lines from the provided file.
 * Store them in an array for later use.
 */
static size_t load_requests(const char *path, request **out) {
	(void)path; (void)out;
	fprintf(stderr, "[TODO] Implement load_requests()\n");
	return 0;
}

/* TODO 2: build wait-for graph given ownership + pending requests.
 * Represent as adjacency matrix or adjacency lists.
 */
static void build_graph(const request *reqs, size_t count) {
	(void)reqs; (void)count;
	fprintf(stderr, "[TODO] Implement build_graph()\n");
}

/* TODO 3: detect cycles and suggest recovery (pick a victim thread).
 * Use DFS/backtracking similar to the slide algorithm.
 */
static void detect_deadlock(void) {
	fprintf(stderr, "[TODO] Implement detect_deadlock()\n");
}

static void usage(const char *prog) {
	fprintf(stderr, "Usage: %s <graph|detect|recover> <input.txt>\n", prog);
}

int main(int argc, char **argv) {
	if (argc != 3) {
		usage(argv[0]);
		return 1;
	}
	request *reqs = NULL;
	size_t count = load_requests(argv[2], &reqs);
	if (count == 0) {
		fprintf(stderr, "No requests loaded (or TODO not implemented).\n");
		return 1;
	}
	if (strcmp(argv[1], "graph") == 0) {
		build_graph(reqs, count);
	} else if (strcmp(argv[1], "detect") == 0) {
		detect_deadlock();
	} else if (strcmp(argv[1], "recover") == 0) {
		fprintf(stderr, "[TODO] Implement recovery suggestions.\n");
	} else {
		usage(argv[0]);
	}
	free(reqs);
	return 0;
}


