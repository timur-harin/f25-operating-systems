#include <stdio.h>

// Iterative Tribonacci without arrays or recursion
static unsigned long long tribonacci(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    unsigned long long t0 = 0, t1 = 1, t2 = 1;
    unsigned long long tn = 0;
    for (int i = 3; i <= n; ++i) {
        tn = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = tn;
    }
    return tn;
}

int main(void) {
    printf("T4=%llu\n", tribonacci(4));
    printf("T36=%llu\n", tribonacci(36));
    return 0;
}


