#include <stdio.h>
#include <stdlib.h>

static void run_fcfs(const int *requests, int n, int head) {
	int total = 0;
	printf("FCFS order: %d", head);
	for (int i = 0; i < n; i++) {
		int dist = abs(requests[i] - head);
		total += dist;
		head = requests[i];
		printf(" -> %d", head);
	}
	printf("\nTotal head movement: %d cylinders\n", total);
}

int main(void) {
	int requests[] = { 95, 180, 34, 119, 11, 123, 62, 64 };
	int n = (int)(sizeof(requests)/sizeof(requests[0]));
	int head = 50;
	run_fcfs(requests, n, head);
	return 0;
}


