#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

static int nearest_request(const int *requests, const bool *served, int n, int head) {
	int best_idx = -1;
	int best_dist = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (served[i]) continue;
		int dist = abs(requests[i] - head);
		if (dist < best_dist) {
			best_dist = dist;
			best_idx = i;
		}
	}
	return best_idx;
}

static void run_sstf(const int *requests_in, int n, int head) {
	int *req = (int*)malloc(n * sizeof(int));
	bool *served = (bool*)calloc(n, sizeof(bool));
	for (int i = 0; i < n; i++) req[i] = requests_in[i];

	int total = 0;
	printf("SSTF order: %d", head);
	for (int served_count = 0; served_count < n; served_count++) {
		int idx = nearest_request(req, served, n, head);
		int dist = abs(req[idx] - head);
		total += dist;
		head = req[idx];
		served[idx] = true;
		printf(" -> %d", head);
	}
	printf("\nTotal head movement: %d cylinders\n", total);

	free(req);
	free(served);
}

int main(void) {
	int requests[] = { 95, 180, 34, 119, 11, 123, 62, 64 };
	int n = (int)(sizeof(requests)/sizeof(requests[0]));
	int head = 50;
	run_sstf(requests, n, head);
	return 0;
}


