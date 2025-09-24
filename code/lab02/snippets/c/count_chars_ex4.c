#include <stdio.h>
#include <ctype.h>
#include <string.h>

static int count_char(const char *s, int ch_lower) {
    int cnt = 0;
    for (const char *p = s; *p; ++p) {
        if (tolower((unsigned char)*p) == ch_lower) cnt++;
    }
    return cnt;
}

static void count_all(const char *s) {
    int seen[256] = {0};
    int first = 1;
    for (const char *p = s; *p; ++p) {
        unsigned char c = (unsigned char)tolower(*p);
        if (!seen[c]) {
            int cnt = count_char(s, c);
            if (!first) printf(", ");
            printf("%c:%d", c, cnt);
            first = 0;
            seen[c] = 1;
        }
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }
    // Join all args with spaces to mimic a sentence
    char buf[512] = {0};
    size_t pos = 0;
    for (int i = 1; i < argc; ++i) {
        size_t n = strlen(argv[i]);
        if (pos + n + 1 >= sizeof buf) break;
        memcpy(buf + pos, argv[i], n);
        pos += n;
        if (i + 1 < argc && pos + 1 < sizeof buf) buf[pos++] = ' ';
    }
    buf[pos] = '\0';

    count_all(buf);
    return 0;
}


