#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
	int ia = *(const int*)a;
	int ib = *(const int*)b;
	return (ia > ib) - (ia < ib);
}

static void run_cscan(const int *requests_in, int n, int head, int max_cyl) {
	int *req = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) req[i] = requests_in[i];
	qsort(req, n, sizeof(int), cmp_int);

	int total = 0;
	printf("C-SCAN order: %d", head);
	int idx = 0;
	while (idx < n && req[idx] < head) idx++;

	// Service to the right
	for (int i = idx; i < n; i++) {
		total += abs(req[i] - head);
		head = req[i];
		printf(" -> %d", head);
	}
	// Jump to start (circular)
	if (head != max_cyl) {
		total += abs(max_cyl - head);
		head = max_cyl;
	}
	// Wrap to 0
	total += max_cyl;
	head = 0;
	// Service from start up to idx-1
	for (int i = 0; i < idx; i++) {
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
	int max_cyl = 199;
	run_cscan(requests, n, head, max_cyl);
	return 0;
}


