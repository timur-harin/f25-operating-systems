## Lab 03 — Recap (Pointers, Arrays, Structures)

Source slides text: `slides_lab03.txt`

### Q&A Recap

- **How to read a float number `grade` from stdin?**
  - `scanf("%f", &grade);`
  - With stream: `fscanf(stdin, "%f", &grade);`

- **How to get command-line parameters?**
  - `int main(int argc, char *args[])`

- **Stages of compiling a C program?**
  - Preprocessing → Compiling → Assembling → Linking

- **Define a string `username` in C (50 characters) without pointers:**
  - `char username[50];`

- **Read a short string `university` (4 chars). Which are (un)safe?**
  - Safe: `fgets(university, 4, stdin)`
  - Safer scanf-width: `scanf("%4s", university)` (still careful)
  - Unsafe: `scanf("%s", university)`, `gets(university)`

### Pointers essentials

- Declaration: `<type>* var = NULL;`
- Dynamic memory: `malloc`, `calloc`, `realloc`, `free`
- `const` with pointers:
  - Pointer to constant: `const T* p;` (data read-only, pointer can change)
  - Constant pointer: `T* const p = addr;` (pointer fixed, data mutable)
  - Constant pointer to constant: `const T* const p = addr;`
- Note: Modifying `const` objects via casts/pointers is Undefined Behavior.

### Arrays basics

- Contiguous, homogeneous, fixed-size: `sizeof(arr)/sizeof(arr[0])`
- Multi-dimensional supported
- Dynamic arrays via pointers + `realloc`

### Structures basics

- Define and access fields with `.`; via pointer with `->`
- Whole-structure assignment is allowed: `p2 = p1;`

### Function pointers and variadic functions

- Function pointer: `<ret> (*fn)(types);`
- Variadic: `<ret> func(first_params, ...);` with `va_list`, `va_start`, `va_arg`, `va_end`

### Exercises (from slides)

- **Ex1**: Pointer/const, 3 contiguous ints, Tribonacci-in-place function
- **Ex2**: `struct Point`, distance and triangle area
- **Ex4**: `aggregate(void* base, size_t size, int n, void* init, void* (*opr)(const void*, const void*))` on int/double arrays
- **Ex5**: `vaggregate` variadic version of `aggregate`
- **Ex6 (opt.)**: Quicksort



