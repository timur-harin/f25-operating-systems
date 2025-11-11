#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	bool has_begin;
	bool has_commit;
	char payload[64];
} journal_txn;

static void replay(const journal_txn *j, char *fs_data) {
	printf("[JRNL] Replay start...\n");
	if (j->has_begin && j->has_commit) {
		printf("[JRNL] Found committed txn. Applying payload: \"%s\"\n", j->payload);
		snprintf(fs_data, 64, "%s", j->payload);
	} else if (j->has_begin && !j->has_commit) {
		printf("[JRNL] Found uncommitted begin; IGNORE to preserve consistency.\n");
	} else if (!j->has_begin && j->has_commit) {
		printf("[JRNL] Commit without begin; treat as noise.\n");
	} else {
		printf("[JRNL] No journal entries.\n");
	}
	printf("[JRNL] Replay complete. FS state: \"%s\"\n", fs_data);
}

int main(void) {
	char fs_data[64] = "clean";
	journal_txn j = {0};

	printf("[JRNL] Initial FS state: \"%s\"\n", fs_data);
	printf("[JRNL] Begin transaction...\n");
	j.has_begin = true;
	snprintf(j.payload, sizeof(j.payload), "write:X=42");
	printf("[JRNL] Crash before commit (simulate power loss)...\n");
	replay(&j, fs_data);

	printf("\n[JRNL] New transaction...\n");
	memset(&j, 0, sizeof(j));
	j.has_begin = true;
	snprintf(j.payload, sizeof(j.payload), "write:Y=99");
	printf("[JRNL] Commit transaction...\n");
	j.has_commit = true;
	replay(&j, fs_data);

	return 0;
}


