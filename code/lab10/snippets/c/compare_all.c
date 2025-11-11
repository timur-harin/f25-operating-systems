#include <stdio.h>
#include <stdlib.h>

extern int main_fcfs(void);
extern int main_sstf(void);
extern int main_scan(void);
extern int main_cscan(void);
extern int main_look(void);

// Minimal duplication: recompile logic separately is simpler in Makefile model,
// here we just print guidance to run individual demos.
int main(void) {
	printf("Compare all disk scheduling algorithms:\n");
	printf("Run each binary to see movements and order:\n");
	printf("  ./bin/fcfs_disk\n");
	printf("  ./bin/sstf_disk\n");
	printf("  ./bin/scan_disk\n");
	printf("  ./bin/cscan_disk\n");
	printf("  ./bin/look_disk\n");
	return 0;
}


