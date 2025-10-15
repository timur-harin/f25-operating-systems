#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Global initialized variable (data segment)
int g_vari = 100;

// Global uninitialized variable (bss segment)
int g_varu;

// Global constant (read-only data segment)
const int g_const = 42;

void print_addresses(void) {
    // Local variables (stack)
    int local_var = 5;
    int local_array[10];
    
    // Dynamic allocation (heap)
    int *heap_var = (int *)malloc(sizeof(int));
    *heap_var = 20;
    
    printf("=== Memory Layout Visualization ===\n\n");
    
    printf("Text Segment (Code):\n");
    printf("  Function address:        %p\n\n", (void *)print_addresses);
    
    printf("Data Segment (Initialized):\n");
    printf("  g_vari (global init):    %p  value = %d\n", (void *)&g_vari, g_vari);
    printf("  g_const (read-only):     %p  value = %d\n\n", (void *)&g_const, g_const);
    
    printf("BSS Segment (Uninitialized):\n");
    printf("  g_varu (global uninit):  %p  value = %d\n\n", (void *)&g_varu, g_varu);
    
    printf("Heap Segment (Dynamic):\n");
    printf("  heap_var:                %p  value = %d\n\n", (void *)heap_var, *heap_var);
    
    printf("Stack Segment (Local):\n");
    printf("  local_var:               %p  value = %d\n", (void *)&local_var, local_var);
    printf("  local_array:             %p\n\n", (void *)local_array);
    
    printf("Memory grows:\n");
    printf("  Stack: ↓ (high to low addresses)\n");
    printf("  Heap:  ↑ (low to high addresses)\n");
    
    free(heap_var);
}

int main(void) {
    printf("Memory Layout of C Program\n");
    printf("PID: %d\n\n", getpid());
    
    print_addresses();
    
    printf("\n=== Memory Segment Order (typical) ===\n");
    printf("High Address: Command-line args & environment\n");
    printf("             ↓ Stack (local variables)\n");
    printf("             ↓ Heap (dynamic allocation)\n");
    printf("             ↓ BSS (uninitialized data)\n");
    printf("             ↓ Data (initialized data)\n");
    printf("Low Address:  Text (program code)\n");
    
    printf("\nUse 'size <binary>' to see segment sizes\n");
    printf("Use 'cat /proc/%d/maps' to see memory mappings\n", getpid());
    
    return 0;
}

