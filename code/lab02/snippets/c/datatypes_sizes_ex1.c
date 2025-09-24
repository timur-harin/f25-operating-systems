#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    int integer = INT_MAX;
    unsigned short u_short = USHRT_MAX;
    long signed_long = LONG_MAX; // using max positive for demo
    float f = FLT_MAX;
    double d = DBL_MAX;

    printf("Sizes (bytes): int=%zu, unsigned short=%zu, long=%zu, float=%zu, double=%zu\n",
           sizeof(integer), sizeof(u_short), sizeof(signed_long), sizeof(f), sizeof(d));
    printf("Values: int=%d, unsigned short=%hu, long=%ld, float=%e, double=%e\n",
           integer, u_short, signed_long, f, d);
    return 0;
}


