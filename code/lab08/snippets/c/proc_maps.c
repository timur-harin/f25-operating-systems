#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_proc_maps(void) {
    pid_t pid = getpid();
    char maps_path[256];
    snprintf(maps_path, sizeof(maps_path), "/proc/%d/maps", pid);
    
    printf("=== Process Memory Map (/proc/%d/maps) ===\n\n", pid);
    
    FILE *fp = fopen(maps_path, "r");
    if (fp == NULL) {
        perror("fopen maps");
        printf("\nNote: /proc filesystem not available on macOS\n");
        printf("Use 'vmmap %d' on macOS instead\n", pid);
        return;
    }
    
    char line[1024];
    int count = 0;
    
    printf("%-20s %-6s %-10s %s\n", "Address Range", "Perms", "Offset", "Path");
    printf("%-20s %-6s %-10s %s\n", "----------------", "-----", "--------", "----");
    
    while (fgets(line, sizeof(line), fp) != NULL && count < 20) {
        printf("%s", line);
        count++;
    }
    
    if (count >= 20) {
        printf("... (showing first 20 mappings)\n");
    }
    
    fclose(fp);
    
    printf("\n=== Map Legend ===\n");
    printf("r: readable\n");
    printf("w: writable\n");
    printf("x: executable\n");
    printf("p: private (copy-on-write)\n");
    printf("s: shared\n");
}

void allocate_and_display(void) {
    // Allocate memory to see it appear in maps
    printf("\n=== Allocating Memory ===\n\n");
    
    size_t size = 1024 * 1024;  // 1 MB
    char *heap_mem = (char *)malloc(size);
    
    if (heap_mem == NULL) {
        perror("malloc");
        return;
    }
    
    // Touch the memory to ensure it's mapped
    memset(heap_mem, 0, size);
    
    printf("Allocated %zu bytes on heap at: %p\n", size, (void *)heap_mem);
    printf("PID: %d\n\n", getpid());
    
    printf("Check with:\n");
    printf("  cat /proc/%d/maps | grep heap\n", getpid());
    printf("  pmap %d\n", getpid());
    printf("\nPress Enter to continue...");
    getchar();
    
    free(heap_mem);
}

int main(void) {
    printf("Process Memory Mappings Demonstration\n");
    printf("======================================\n\n");
    
    printf("PID: %d\n\n", getpid());
    
    print_proc_maps();
    
    allocate_and_display();
    
    printf("\n=== Summary ===\n\n");
    printf("Each process has its own virtual address space\n");
    printf("/proc/[pid]/maps shows memory regions:\n");
    printf("  - Text (code) segments\n");
    printf("  - Data segments\n");
    printf("  - Heap\n");
    printf("  - Stack\n");
    printf("  - Shared libraries\n");
    printf("  - Memory-mapped files\n");
    
    return 0;
}

