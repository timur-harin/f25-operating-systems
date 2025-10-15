#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void demonstrate_malloc(void) {
    printf("=== malloc() - Memory Allocation ===\n\n");
    
    int n = 5;
    int *array = (int *)malloc(n * sizeof(int));
    
    if (array == NULL) {
        fprintf(stderr, "malloc failed!\n");
        return;
    }
    
    printf("Allocated %d integers using malloc\n", n);
    printf("Note: malloc does NOT initialize memory\n");
    printf("Uninitialized values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("(garbage values)\n\n");
    
    // Fill array
    for (int i = 0; i < n; i++) {
        array[i] = i * 10;
    }
    
    printf("After initialization: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
    
    free(array);
    printf("Memory freed with free()\n\n");
}

void demonstrate_calloc(void) {
    printf("=== calloc() - Zeroed Allocation ===\n\n");
    
    int n = 5;
    int *array = (int *)calloc(n, sizeof(int));
    
    if (array == NULL) {
        fprintf(stderr, "calloc failed!\n");
        return;
    }
    
    printf("Allocated %d integers using calloc\n", n);
    printf("Note: calloc initializes memory to zero\n");
    printf("Initial values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("(all zeros)\n\n");
    
    free(array);
}

void demonstrate_realloc(void) {
    printf("=== realloc() - Resize Allocation ===\n\n");
    
    int initial_size = 3;
    int *array = (int *)malloc(initial_size * sizeof(int));
    
    if (array == NULL) {
        fprintf(stderr, "malloc failed!\n");
        return;
    }
    
    // Initialize
    for (int i = 0; i < initial_size; i++) {
        array[i] = i + 1;
    }
    
    printf("Initial array (size %d): ", initial_size);
    for (int i = 0; i < initial_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
    
    // Resize
    int new_size = 6;
    int *new_array = (int *)realloc(array, new_size * sizeof(int));
    
    if (new_array == NULL) {
        fprintf(stderr, "realloc failed!\n");
        free(array);
        return;
    }
    
    array = new_array;
    
    // Initialize new elements
    for (int i = initial_size; i < new_size; i++) {
        array[i] = i + 1;
    }
    
    printf("After realloc (size %d): ", new_size);
    for (int i = 0; i < new_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Note: Old data preserved, new space uninitialized\n\n");
    
    free(array);
}

void demonstrate_memory_leak(void) {
    printf("=== Memory Leak Example ===\n\n");
    
    printf("BAD: Memory leak (allocated but never freed)\n");
    printf("  int *leak = malloc(1024);\n");
    printf("  // ... leak goes out of scope without free()\n\n");
    
    printf("GOOD: Proper memory management\n");
    printf("  int *data = malloc(1024);\n");
    printf("  // ... use data ...\n");
    printf("  free(data);\n\n");
}

int main(void) {
    printf("Dynamic Memory Allocation in C\n");
    printf("==============================\n\n");
    
    demonstrate_malloc();
    demonstrate_calloc();
    demonstrate_realloc();
    demonstrate_memory_leak();
    
    printf("=== Summary ===\n\n");
    printf("malloc(size):        Allocate size bytes (uninitialized)\n");
    printf("calloc(n, size):     Allocate n*size bytes (zeroed)\n");
    printf("realloc(ptr, size):  Resize allocation to size bytes\n");
    printf("free(ptr):           Deallocate memory\n\n");
    
    printf("Always:\n");
    printf("  1. Check if allocation succeeded (ptr != NULL)\n");
    printf("  2. Free allocated memory when done\n");
    printf("  3. Don't use pointer after free()\n");
    printf("  4. Don't free() the same pointer twice\n");
    
    return 0;
}

