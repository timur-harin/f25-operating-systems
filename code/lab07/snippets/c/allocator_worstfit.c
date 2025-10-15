#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEMORY_SIZE 1000
#define MAX_BLOCKS 50

typedef struct {
    int start;
    int size;
    int allocated;
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

int allocate_worst_fit(unsigned int adrs, int size) {
    // Worst Fit: Find largest free block
    int worst_idx = -1;
    int worst_size = -1;
    
    for (int i = 0; i < block_count; i++) {
        if (!blocks[i].allocated && blocks[i].size >= size) {
            if (blocks[i].size > worst_size) {
                worst_size = blocks[i].size;
                worst_idx = i;
            }
        }
    }
    
    if (worst_idx == -1) {
        return 0;  // No suitable block found
    }
    
    // Allocate in worst fit (largest) block
    int start = blocks[worst_idx].start;
    
    for (int j = start; j < start + size; j++) {
        memory[j] = adrs;
    }
    
    if (blocks[worst_idx].size > size) {
        if (block_count < MAX_BLOCKS) {
            blocks[block_count].start = start + size;
            blocks[block_count].size = blocks[worst_idx].size - size;
            blocks[block_count].allocated = 0;
            block_count++;
        }
        blocks[worst_idx].size = size;
    }
    
    blocks[worst_idx].allocated = 1;
    return 1;
}

void clear_memory(unsigned int adrs) {
    for (int i = 0; i < block_count; i++) {
        if (blocks[i].allocated && memory[blocks[i].start] == adrs) {
            int start = blocks[i].start;
            int size = blocks[i].size;
            
            for (int j = start; j < start + size; j++) {
                memory[j] = 0;
            }
            
            blocks[i].allocated = 0;
            return;
        }
    }
}

void print_memory_status(void) {
    int allocated = 0, free = 0, largest_free = 0;
    
    for (int i = 0; i < block_count; i++) {
        if (blocks[i].allocated) {
            allocated += blocks[i].size;
        } else {
            free += blocks[i].size;
            if (blocks[i].size > largest_free) {
                largest_free = blocks[i].size;
            }
        }
    }
    
    printf("Memory Status: Allocated=%d, Free=%d, Largest Free Block=%d\n", 
           allocated, free, largest_free);
}

int main(void) {
    printf("Worst Fit Memory Allocator Simulation\n");
    printf("======================================\n\n");
    
    init_memory();
    
    printf("Memory size: %d units\n", MEMORY_SIZE);
    printf("Algorithm: Worst Fit (find largest free block)\n");
    printf("Goal: Leave large enough fragments for future allocations\n\n");
    
    printf("=== Example Allocations ===\n\n");
    
    clock_t start = clock();
    
    printf("1. allocate 1001 100\n");
    if (allocate_worst_fit(1001, 100)) {
        printf("   ✓ Allocated 100 units from largest block\n");
    }
    print_memory_status();
    printf("\n");
    
    printf("2. allocate 2002 50\n");
    if (allocate_worst_fit(2002, 50)) {
        printf("   ✓ Allocated 50 units from largest remaining block\n");
    }
    print_memory_status();
    printf("\n");
    
    printf("3. allocate 3003 150\n");
    if (allocate_worst_fit(3003, 150)) {
        printf("   ✓ Allocated 150 units\n");
    }
    print_memory_status();
    printf("\n");
    
    printf("4. clear 2002\n");
    clear_memory(2002);
    printf("   ✓ Freed address 2002\n");
    print_memory_status();
    printf("\n");
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("=== Performance ===\n\n");
    printf("Operations: 4\n");
    printf("Time: %.6f seconds\n", time_spent);
    printf("Throughput: %.2f ops/sec\n", 4.0 / time_spent);
    
    printf("\n=== Worst Fit Characteristics ===\n\n");
    printf("Advantages:\n");
    printf("  - Leaves larger remaining fragments\n");
    printf("  - Fragments more likely to be usable\n");
    printf("  - Can reduce fragmentation in some scenarios\n\n");
    
    printf("Disadvantages:\n");
    printf("  - Slower: must search entire free list\n");
    printf("  - Quickly breaks up large free blocks\n");
    printf("  - Generally poor performance in practice\n");
    
    return 0;
}

