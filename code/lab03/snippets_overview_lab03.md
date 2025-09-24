## Lab 03 — Snippets Overview

This overview links typical code snippets you can create or adapt for Lab 03 topics. See `slides_lab03.txt` for slide references. Implement snippets in `snippets/c` and small runner scripts in `snippets/sh` as in Lab 02.

### Pointers and const correctness

- Pointer kinds:
  - `const int *p;` pointer to const int (data read-only)
  - `int * const p = &x;` constant pointer (fixed address)
  - `const int * const p = &x;` both constant

- Demo idea: allocate a small buffer, modify via indexing and pointer arithmetic, then free.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char * const p = malloc(6);
    memset(p, 'A', 5); p[5] = '\0';
    (*(p+1))++;
    *p = *(p+1);
    printf("%s\n", p);
    free(p);
    return 0;
}
```

### Arrays basics and pointer interplay

- Static array size: `size_t n = sizeof(a)/sizeof(a[0]);`
- Pointer view of arrays and `sizeof` differences.

```c
#include <stdio.h>

int main(void) {
    float m[4] = {0.25f, 0.5f, 0.75f, 1.0f};
    float *p = m; // array-to-pointer decay
    printf("sizeof(m)=%zu, sizeof(*m)=%zu, len=%zu\n",
           sizeof m, sizeof *m, sizeof m / sizeof *m);
    printf("sizeof(p)=%zu\n", sizeof p);
    for (size_t i = 0; i < 4; i++) printf("%g ", p[i]);
    printf("\n");
}
```

### Structures: definition, access, arrays of structs

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct { char *name; int age; float height; } Person;

Person *createPerson(char *name, int age, float height) {
    Person *p = malloc(sizeof *p);
    p->name = name; p->age = age; p->height = height;
    return p;
}

void showPerson(const Person *p) {
    printf("%s, %d, %.2f\n", p->name, p->age, p->height);
}

int main(void) {
    Person *friends[3] = {
        createPerson("Alice", 20, 1.65f),
        createPerson("Bob", 21, 1.75f),
        createPerson("Carol", 19, 1.70f)
    };
    for (int i = 0; i < 3; i++) showPerson(friends[i]);
    for (int i = 0; i < 3; i++) free(friends[i]);
}
```

### Exercise-aligned skeletons

- Ex1: contiguous ints and in-place Tribonacci with one temp variable.

```c
// ex1.c (skeleton)
#include <stdio.h>
#include <stdlib.h>

static int const_tri(int * const p, int n) {
    if (n == 0) return p[0];
    if (n == 1) return p[1];
    if (n == 2) return p[2];
    for (int i = 3; i <= n; i++) {
        int temp = p[0] + p[1] + p[2];
        p[0] = p[1]; p[1] = p[2]; p[2] = temp;
    }
    return p[2];
}

int main(void) {
    const int x = 1;
    int * const p = malloc(3 * sizeof *p);
    p[0] = x; p[1] = x; p[2] = 2*x;
    printf("%d\n", const_tri(p, 10));
    free(p);
}
```

- Ex2: `struct Point`, distance and triangle area.

```c
#include <stdio.h>
#include <math.h>

typedef struct { double x, y; } Point;

double distance(Point a, Point b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double area(Point a, Point b, Point c) {
    return 0.5 * fabs(a.x*b.y - b.x*a.y + b.x*c.y - c.x*b.y + c.x*a.y - a.x*c.y);
}
```

- Ex4: `aggregate` with function pointer.

```c
// signature per slides
void* aggregate(void* base, size_t size, int n, void* init,
                void* (*opr)(const void*, const void*));
```

- Ex5: `vaggregate` variadic version of `aggregate`.

### Suggested runner scripts (like Lab 02)

Create simple scripts in `snippets/sh` (remember `chmod +x`).

```sh
#!/usr/bin/env bash
set -euo pipefail
gcc -std=c11 -Wall -Wextra -O2 "$1" -o app && ./app
```



