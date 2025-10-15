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

int allocate_best_fit(unsigned int adrs, int size) {
    // Best Fit: Find smallest free block that fits
    int best_idx = -1;
    int best_size = MEMORY_SIZE + 1;
    
    for (int i = 0; i < block_count; i++) {
        if (!blocks[i].allocated && blocks[i].size >= size) {
            if (blocks[i].size < best_size) {
                best_size = blocks[i].size;
                best_idx = i;
            }
        }
    }
    
    if (best_idx == -1) {
        return 0;  // No suitable block found
    }
    
    // Allocate in best fit block
    int start = blocks[best_idx].start;
    
    for (int j = start; j < start + size; j++) {
        memory[j] = adrs;
    }
    
    if (blocks[best_idx].size > size) {
        if (block_count < MAX_BLOCKS) {
            blocks[block_count].start = start + size;
            blocks[block_count].size = blocks[best_idx].size - size;
            blocks[block_count].allocated = 0;
            block_count++;
        }
        blocks[best_idx].size = size;
    }
    
    blocks[best_idx].allocated = 1;
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
    printf("Best Fit Memory Allocator Simulation\n");
    printf("=====================================\n\n");
    
    init_memory();
    
    printf("Memory size: %d units\n", MEMORY_SIZE);
    printf("Algorithm: Best Fit (find smallest suitable free block)\n\n");
    
    printf("=== Example Allocations ===\n\n");
    
    clock_t start = clock();
    
    printf("1. allocate 1001 100\n");
    if (allocate_best_fit(1001, 100)) {
        printf("   ✓ Allocated 100 units\n");
    }
    print_memory_status();
    printf("\n");
    
    printf("2. allocate 2002 200\n");
    if (allocate_best_fit(2002, 200)) {
        printf("   ✓ Allocated 200 units\n");
    }
    print_memory_status();
    printf("\n");
    
    printf("3. clear 1001\n");
    clear_memory(1001);
    printf("   ✓ Freed address 1001 (100 units available)\n");
    print_memory_status();
    printf("\n");
    
    printf("4. allocate 3003 50\n");
    if (allocate_best_fit(3003, 50)) {
        printf("   ✓ Allocated 50 units (best fit in 100-unit gap)\n");
    }
    print_memory_status();
    printf("\n");
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("=== Performance ===\n\n");
    printf("Operations: 4\n");
    printf("Time: %.6f seconds\n", time_spent);
    printf("Throughput: %.2f ops/sec\n", 4.0 / time_spent);
    
    printf("\n=== Best Fit Characteristics ===\n\n");
    printf("Advantages:\n");
    printf("  - Better memory utilization\n");
    printf("  - Minimizes wasted space in allocated blocks\n");
    printf("  - Keeps fragments small\n\n");
    
    printf("Disadvantages:\n");
    printf("  - Slower: must search entire free list\n");
    printf("  - May create many tiny unusable fragments\n");
    
    return 0;
}

