#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEMORY_SIZE 1000
#define MAX_BLOCKS 50

typedef struct {
    int start;
    int size;
    int allocated;  // 1 if allocated, 0 if free
} Block;

unsigned int memory[MEMORY_SIZE] = {0};
Block blocks[MAX_BLOCKS];
int block_count = 0;

void init_memory(void) {
    memset(memory, 0, sizeof(memory));
    block_count = 1;
    blocks[0].start = 0;
    blocks[0].size = MEMORY_SIZE;
    blocks[0].allocated = 0;
}

int allocate_first_fit(unsigned int adrs, int size) {
    // First Fit: Find first free block that fits
    for (int i = 0; i < block_count; i++) {
        if (!blocks[i].allocated && blocks[i].size >= size) {
            // Found suitable block
            int start = blocks[i].start;
            
            // Mark memory
            for (int j = start; j < start + size; j++) {
                memory[j] = adrs;
            }
            
            // Split block if needed
            if (blocks[i].size > size) {
                // Create new free block for remainder
                if (block_count < MAX_BLOCKS) {
                    blocks[block_count].start = start + size;
                    blocks[block_count].size = blocks[i].size - size;
                    blocks[block_count].allocated = 0;
                    block_count++;
                }
                blocks[i].size = size;
            }
            
            blocks[i].allocated = 1;
            return 1;  // Success
        }
    }
    return 0;  // Failed to allocate
}

void clear_memory(unsigned int adrs) {
    // Find and free block with this address
    for (int i = 0; i < block_count; i++) {
        if (blocks[i].allocated && memory[blocks[i].start] == adrs) {
            int start = blocks[i].start;
            int size = blocks[i].size;
            
            // Clear memory
            for (int j = start; j < start + size; j++) {
                memory[j] = 0;
            }
            
            blocks[i].allocated = 0;
            
            // Try to coalesce with adjacent free blocks
            // (simplified - just mark as free)
            return;
        }
    }
}

void print_memory_status(void) {
    int allocated = 0, free = 0;
    
    for (int i = 0; i < block_count; i++) {
        if (blocks[i].allocated) {
            allocated += blocks[i].size;
        } else {
            free += blocks[i].size;
        }
    }
    
    printf("Memory Status: Allocated=%d, Free=%d, Blocks=%d\n", 
           allocated, free, block_count);
}

int main(void) {
    printf("First Fit Memory Allocator Simulation\n");
    printf("======================================\n\n");
    
    init_memory();
    
    printf("Memory size: %d units\n", MEMORY_SIZE);
    printf("Algorithm: First Fit (find first suitable free block)\n\n");
    
    // Example allocations
    printf("=== Example Allocations ===\n\n");
    
    clock_t start = clock();
    
    printf("1. allocate 1001 100\n");
    if (allocate_first_fit(1001, 100)) {
        printf("   ✓ Allocated 100 units at address 1001\n");
    }
    print_memory_status();
    printf("\n");
    
    printf("2. allocate 2002 50\n");
    if (allocate_first_fit(2002, 50)) {
        printf("   ✓ Allocated 50 units at address 2002\n");
    }
    print_memory_status();
    printf("\n");
    
    printf("3. allocate 3003 200\n");
    if (allocate_first_fit(3003, 200)) {
        printf("   ✓ Allocated 200 units at address 3003\n");
    }
    print_memory_status();
    printf("\n");
    
    printf("4. clear 1001\n");
    clear_memory(1001);
    printf("   ✓ Freed address 1001\n");
    print_memory_status();
    printf("\n");
    
    printf("5. allocate 4004 80\n");
    if (allocate_first_fit(4004, 80)) {
        printf("   ✓ Allocated 80 units at address 4004 (uses freed space)\n");
    }
    print_memory_status();
    printf("\n");
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("=== Performance ===\n\n");
    printf("Operations: 5\n");
    printf("Time: %.6f seconds\n", time_spent);
    printf("Throughput: %.2f ops/sec\n", 5.0 / time_spent);
    
    printf("\n=== First Fit Characteristics ===\n\n");
    printf("Advantages:\n");
    printf("  - Fast: stops at first suitable block\n");
    printf("  - Simple to implement\n\n");
    
    printf("Disadvantages:\n");
    printf("  - May create small fragments at beginning of memory\n");
    printf("  - Not optimal for memory utilization\n");
    
    return 0;
}

