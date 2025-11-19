#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_THREADS 4
#define MAX_RESOURCES 3

typedef struct {
	int thread;
	int resource;
} request;

static const request requests[] = {
	{1, 0},
	{2, 1},
	{1, 1},
	{2, 2},
	{1, 2}, // will block -> potential deadlock with thread 2 waiting for 0
	{2, 0},
};

static int resource_owner[MAX_RESOURCES]; // thread id or 0 for free
static int waits_for[MAX_THREADS + 1];    // resource id or -1

static void print_state(void) {
	puts("Current locks:");
	for (int r = 0; r < MAX_RESOURCES; r++) {
		if (resource_owner[r]) {
			printf("  resource %d -> thread %d\n", r, resource_owner[r]);
		} else {
			printf("  resource %d -> (free)\n", r);
		}
	}
	puts("Wait list:");
	for (int t = 1; t <= MAX_THREADS; t++) {
		if (waits_for[t] != -1) {
			printf("  thread %d waiting for resource %d\n", t, waits_for[t]);
		}
	}
}

static bool detect_cycle(int start_thread, int current_thread, bool *visited) {
	if (visited[current_thread]) return current_thread == start_thread;
	visited[current_thread] = true;
	int res = waits_for[current_thread];
	if (res == -1) return false;
	int owner = resource_owner[res];
	if (owner == 0) return false;
	return detect_cycle(start_thread, owner, visited);
}

static bool check_deadlock(void) {
	for (int t = 1; t <= MAX_THREADS; t++) {
		if (waits_for[t] == -1) continue;
		bool visited[MAX_THREADS + 1] = {false};
		if (detect_cycle(t, t, visited)) {
			printf("Deadlock detected involving thread %d!\n", t);
			return true;
		}
	}
	return false;
}

int main(void) {
	memset(resource_owner, 0, sizeof(resource_owner));
	for (int i = 0; i <= MAX_THREADS; i++) waits_for[i] = -1;

	puts("Processing requests (thread resource):");
	for (size_t i = 0; i < sizeof(requests)/sizeof(requests[0]); i++) {
		int t = requests[i].thread;
		int r = requests[i].resource;
		printf("\nRequest %zu: thread %d -> resource %d\n", i + 1, t, r);
		if (resource_owner[r] == 0) {
			resource_owner[r] = t;
			printf("  Granted. Thread %d now holds resource %d.\n", t, r);
		} else if (resource_owner[r] == t) {
			printf("  Thread %d already owns resource %d.\n", t, r);
		} else {
			printf("  Resource %d busy (owner thread %d). Thread %d waits.\n",
			       r, resource_owner[r], t);
			waits_for[t] = r;
			if (check_deadlock()) {
				print_state();
				puts("Terminating replay due to deadlock.");
				return 0;
			}
		}
		print_state();
	}
	puts("\nAll requests processed without deadlock.");
	return 0;
}


