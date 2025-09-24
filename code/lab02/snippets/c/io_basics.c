#include <stdio.h>
#include <string.h>

int main(void) {
    char name[64];
    printf("Enter your name: ");
    if (fgets(name, sizeof name, stdin) == NULL) {
        return 1;
    }
    name[strcspn(name, "\n")] = '\0';

    printf("Hello, %s!\n", name);

    float f;
    printf("Enter a float: ");
    if (scanf("%f", &f) == 1) {
        printf("You entered: %f\n", f);
    }

    unsigned x;
    printf("\nEnter a hex number (e.g., ff): ");
    if (scanf(" %x", &x) == 1) {
        printf("hex=%x, dec=%u\n", x, x);
    }

    return 0;
}


