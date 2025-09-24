#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[257];
    size_t len = 0;
    int ch;
    while (len < sizeof(buf) - 1 && (ch = getchar()) != EOF) {
        if (ch == '.' || ch == '\n') break;
        buf[len++] = (char)ch;
    }
    buf[len] = '\0';

    printf("\"" );
    for (size_t i = len; i-- > 0; ) {
        putchar(buf[i]);
    }
    printf("\"\n");
    return 0;
}


