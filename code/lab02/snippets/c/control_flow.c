#include <stdio.h>

int max_of_three(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

int main(void) {
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            sum += i;
        } else {
            continue;
        }
    }
    printf("Sum of even numbers 1..10 = %d\n", sum);
    printf("Max of (3,7,5) = %d\n", max_of_three(3,7,5));
    return 0;
}


