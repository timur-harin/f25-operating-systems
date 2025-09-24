#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int is_valid_in_base(const char *digits, int base) {
    if (base < 2 || base > 10) return 0;
    if (digits[0] == '\0') return 0;
    for (const char *p = digits; *p; ++p) {
        if (!isdigit((unsigned char)*p)) return 0;
        int v = *p - '0';
        if (v < 0 || v >= base) return 0;
    }
    return 1;
}

static int to_decimal(const char *digits, int base, long long *out) {
    long long value = 0;
    for (const char *p = digits; *p; ++p) {
        int v = *p - '0';
        value = value * base + v;
    }
    *out = value;
    return 1;
}

static void reverse_string(char *s) {
    size_t n = strlen(s);
    for (size_t i = 0, j = n ? n - 1 : 0; i < j; ++i, --j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

static int from_decimal(long long value, int base, char *out, size_t out_size) {
    if (base < 2 || base > 10 || out_size < 2) return 0;
    if (value == 0) {
        out[0] = '0';
        out[1] = '\0';
        return 1;
    }
    size_t i = 0;
    while (value > 0 && i + 1 < out_size) {
        int rem = (int)(value % base);
        out[i++] = (char)('0' + rem);
        value /= base;
    }
    if (value != 0) return 0; // not enough space
    out[i] = '\0';
    reverse_string(out);
    return 1;
}

// convert x (as decimal-digit string) from base s to base t
static int convert(const char *x_str, int s, int t, char *out, size_t out_size) {
    if (!is_valid_in_base(x_str, s)) return 0;
    long long dec = 0;
    if (!to_decimal(x_str, s, &dec)) return 0;
    if (!from_decimal(dec, t, out, out_size)) return 0;
    return 1;
}

int main(void) {
    char x_str[128];
    int s, t;
    if (printf("Enter: <number> <source_base 2-10> <target_base 2-10>\n") < 0) return 1;
    if (scanf("%127s %d %d", x_str, &s, &t) != 3) {
        printf("cannot convert!\n");
        return 0;
    }
    char out[128];
    if (!convert(x_str, s, t, out, sizeof out)) {
        printf("cannot convert!\n");
        return 0;
    }
    printf("%s\n", out);
    return 0;
}


