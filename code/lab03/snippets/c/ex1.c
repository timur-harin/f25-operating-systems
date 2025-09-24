#include <stdio.h>
#include <stdlib.h>

static int calculateTribonacciInPlace(int *const tribonacciCells, int n) {
    if (n == 0) return tribonacciCells[0];
    if (n == 1) return tribonacciCells[1];
    if (n == 2) return tribonacciCells[2];
    for (int i = 3; i <= n; i++) {
        int nextValue = tribonacciCells[0] + tribonacciCells[1] + tribonacciCells[2];
        tribonacciCells[0] = tribonacciCells[1];
        tribonacciCells[1] = tribonacciCells[2];
        tribonacciCells[2] = nextValue;
    }
    return tribonacciCells[2];
}

int main(void) {
    const int x = 1;

    int *const p = (int *)malloc(3 * sizeof(int));
    if (!p) {
        fprintf(stderr, "Allocation failed\n");
        return 1;
    }

    const int *q = &x;

    p[0] = *q;      // x
    p[1] = *q;      // x
    p[2] = 2 * (*q); // 2x

    printf("Addresses: %p %p %p\n", (void *)&p[0], (void *)&p[1], (void *)&p[2]);
    long long diff1 = (char *)&p[1] - (char *)&p[0];
    long long diff2 = (char *)&p[2] - (char *)&p[1];
    printf("Contiguous check (bytes between cells): %lld, %lld (sizeof(int)=%zu)\n",
           diff1, diff2, sizeof(int));

    p[0] = 0; // T0
    p[1] = 1; // T1
    p[2] = 1; // T2
    int n = 10;
    int tn = calculateTribonacciInPlace(p, n);
    printf("T%d = %d\n", n, tn);

    free(p);
    return 0;
}



