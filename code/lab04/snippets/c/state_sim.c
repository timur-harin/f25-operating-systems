#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void print_state(const char *state) {
    printf("[sim] %-8s\n", state);
    fflush(stdout);
}

int main(int argc, char **argv) {
    int cycles = 3;
    if (argc >= 2) {
        cycles = atoi(argv[1]);
        if (cycles <= 0) cycles = 3;
    }

    printf("Process state transitions (simulated)\n");
    printf("Cycle count: %d\n", cycles);
    fflush(stdout);

    for (int i = 0; i < cycles; i++) {
        print_state("READY");
        sleep(1);
        print_state("RUNNING");
        sleep(1);
        print_state("BLOCKED (I/O)");
        sleep(2);
        print_state("READY");
        sleep(1);
    }

    print_state("TERMINATED");
    return 0;
}


