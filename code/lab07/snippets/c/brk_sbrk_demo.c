#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_program_break(const char *msg) {
    void *current_brk = sbrk(0);
    printf("%s: %p\n", msg, current_brk);
}

int main(void) {
    printf("Program Break (brk/sbrk) Demonstration\n");
    printf("======================================\n\n");
    
    printf("The program break marks the end of the heap segment\n");
    printf("sbrk(0) returns current break without changing it\n");
    printf("sbrk(n) increases heap by n bytes\n\n");
    
    // Initial program break
    print_program_break("Initial program break");
    
    // Allocate using sbrk
    printf("\nAllocating 1024 bytes using sbrk(1024)...\n");
    void *old_brk = sbrk(0);
    void *ptr = sbrk(1024);
    
    if (ptr == (void *)-1) {
        perror("sbrk failed");
        return 1;
    }
    
    print_program_break("After sbrk(1024)");
    printf("  Heap grew by: %ld bytes\n", (char *)sbrk(0) - (char *)old_brk);
    
    // Use the allocated memory
    printf("\nWriting data to allocated memory...\n");
    int *int_array = (int *)ptr;
    for (int i = 0; i < 10; i++) {
        int_array[i] = i * 10;
    }
    
    printf("Array values: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", int_array[i]);
    }
    printf("\n");
    
    // Demonstrate malloc (which may use sbrk internally)
    printf("\n=== Comparing with malloc ===\n\n");
    print_program_break("Before malloc");
    
    void *malloc_ptr = malloc(2048);
    if (malloc_ptr == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }
    
    print_program_break("After malloc(2048)");
    printf("Note: malloc may use sbrk, mmap, or both depending on size\n");
    
    free(malloc_ptr);
    print_program_break("After free");
    printf("Note: free() may not immediately return memory to OS\n");
    
    // Check heap limit
    printf("\n=== Heap Limits ===\n\n");
    printf("Check limits: cat /proc/%d/limits\n", getpid());
    printf("Data segment limit (soft): typically 'unlimited' in modern systems\n");
    printf("Actual limit determined by: ulimit -d (in KB)\n");
    
    printf("\nHistorical Note:\n");
    printf("  - brk/sbrk are old mechanisms from pre-virtual-memory era\n");
    printf("  - Modern malloc often uses mmap for large allocations\n");
    printf("  - sbrk still used for small allocations in some implementations\n");
    
    return 0;
}

