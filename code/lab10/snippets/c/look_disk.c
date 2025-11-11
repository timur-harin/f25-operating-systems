#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
	int ia = *(const int*)a;
	int ib = *(const int*)b;
	return (ia > ib) - (ia < ib);
}

static void run_look(const int *requests_in, int n, int head) {
	int *req = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) req[i] = requests_in[i];
	qsort(req, n, sizeof(int), cmp_int);

	int total = 0;
	printf("LOOK order: %d", head);
	int idx = 0;
	while (idx < n && req[idx] < head) idx++;
	// Right until the last request
	for (int i = idx; i < n; i++) {
		total += abs(req[i] - head);
		head = req[i];
		printf(" -> %d", head);
	}
	// Then reverse to the smallest on the left
	for (int i = idx - 1; i >= 0; i--) {
		total += abs(req[i] - head);
		head = req[i];
		printf(" -> %d", head);
	}
	printf("\nTotal head movement: %d cylinders\n", total);
	free(req);
}

int main(void) {
	int requests[] = { 95, 180, 34, 119, 11, 123, 62, 64 };
	int n = (int)(sizeof(requests)/sizeof(requests[0]));
	int head = 50;
	run_look(requests, n, head);
	return 0;
}


