#include <stdio.h>
#include <stdbool.h>

#define MAXN 6

static const char *names[MAXN] = { "P0", "P1", "P2", "P3", "P4", "P5" };
static int graph[MAXN][MAXN] = {
	//  P0 P1 P2 P3 P4 P5
	{ 0, 1, 0, 0, 0, 0 }, // P0 waits for P1
	{ 0, 0, 1, 0, 0, 0 }, // P1 waits for P2
	{ 0, 0, 0, 1, 0, 0 }, // P2 waits for P3
	{ 0, 0, 0, 0, 1, 0 }, // P3 waits for P4
	{ 1, 0, 0, 0, 0, 0 }, // P4 waits for P0 (cycle)
	{ 0, 0, 0, 0, 0, 0 }, // P5 free
};

static bool dfs(int node, bool *visited, bool *stack, int *cycle, int *cycle_len) {
	visited[node] = true;
	stack[node] = true;
	for (int neighbor = 0; neighbor < MAXN; neighbor++) {
		if (!graph[node][neighbor]) continue;
		if (!visited[neighbor]) {
			if (dfs(neighbor, visited, stack, cycle, cycle_len)) {
				cycle[(*cycle_len)++] = node;
				return true;
			}
		} else if (stack[neighbor]) {
			cycle[(*cycle_len)++] = node;
			cycle[(*cycle_len)++] = neighbor;
			return true;
		}
	}
	stack[node] = false;
	return false;
}

int main(void) {
	bool visited[MAXN] = {false};
	bool in_stack[MAXN] = {false};
	int cycle[MAXN] = {0};
	int cycle_len = 0;

	puts("Wait-for graph (adjacency):");
	for (int i = 0; i < MAXN; i++) {
		printf("%s waits for:", names[i]);
		bool has_edge = false;
		for (int j = 0; j < MAXN; j++) {
			if (graph[i][j]) {
				printf(" %s", names[j]);
				has_edge = true;
			}
		}
		if (!has_edge) printf(" (none)");
		printf("\n");
	}

	for (int i = 0; i < MAXN; i++) {
		if (!visited[i] && dfs(i, visited, in_stack, cycle, &cycle_len)) {
			puts("\nDeadlock detected! Cycle:");
			for (int j = cycle_len - 1; j >= 0; j--) {
				printf("%s%s", names[cycle[j]], (j == 0 ? "\n" : " -> "));
			}
			return 0;
		}
	}
	puts("\nNo cycles found; system is safe.");
	return 0;
}


