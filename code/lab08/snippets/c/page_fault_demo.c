#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

void print_page_faults(struct rusage *usage, const char *msg) {
    printf("%s:\n", msg);
    printf("  Minor faults (no I/O): %ld\n", usage->ru_minflt);
    printf("  Major faults (I/O required): %ld\n", usage->ru_majflt);
}

void demonstrate_page_faults(void) {
    struct rusage usage_start, usage_end;
    
    printf("=== Page Fault Demonstration ===\n\n");
    
    // Get initial stats
    getrusage(RUSAGE_SELF, &usage_start);
    print_page_faults(&usage_start, "Initial state");
    
    // Allocate large memory (1 GB)
    size_t size = 1024 * 1024 * 1024;  // 1 GB
    printf("\nAllocating %zu MB...\n", size / (1024*1024));
    
    char *mem = (char *)malloc(size);
    if (mem == NULL) {
        fprintf(stderr, "malloc failed, trying smaller size\n");
        size = 100 * 1024 * 1024;  // 100 MB
        mem = (char *)malloc(size);
        if (mem == NULL) {
            perror("malloc");
            return;
        }
    }
    
    getrusage(RUSAGE_SELF, &usage_end);
    printf("\n");
    print_page_faults(&usage_end, "After malloc");
    printf("  New minor faults: %ld\n", usage_end.ru_minflt - usage_start.ru_minflt);
    
    printf("\nNote: malloc() allocates virtual memory but doesn't touch physical pages\n");
    printf("Pages are allocated on-demand (lazy allocation)\n");
    
    // Now actually touch the memory
    printf("\nTouching memory (writing to every page)...\n");
    
    size_t page_size = 4096;
    for (size_t i = 0; i < size; i += page_size) {
        mem[i] = 1;  // Touch each page
    }
    
    getrusage(RUSAGE_SELF, &usage_start);
    printf("\n");
    print_page_faults(&usage_start, "After touching memory");
    printf("  New minor faults: %ld\n", usage_start.ru_minflt - usage_end.ru_minflt);
    printf("  (One fault per page as memory is actually allocated)\n");
    
    free(mem);
}

void demonstrate_copy_on_write(void) {
    printf("\n\n=== Copy-on-Write (COW) ===\n\n");
    
    struct rusage usage;
    
    // Allocate and initialize memory
    size_t size = 10 * 1024 * 1024;  // 10 MB
    char *mem = (char *)malloc(size);
    if (mem == NULL) {
        perror("malloc");
        return;
    }
    
    memset(mem, 'A', size);
    
    getrusage(RUSAGE_SELF, &usage);
    long faults_before = usage.ru_minflt;
    
    printf("Before fork: %ld minor faults\n", faults_before);
    
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        getrusage(RUSAGE_SELF, &usage);
        printf("[child ] After fork: %ld minor faults\n", usage.ru_minflt - faults_before);
        
        // Read from memory (no new pages needed - COW)
        volatile char c = mem[0];
        (void)c;
        
        getrusage(RUSAGE_SELF, &usage);
        printf("[child ] After read: %ld minor faults\n", usage.ru_minflt - faults_before);
        
        // Write to memory (triggers COW - new pages allocated)
        for (size_t i = 0; i < size; i += 4096) {
            mem[i] = 'B';
        }
        
        getrusage(RUSAGE_SELF, &usage);
        printf("[child ] After write: %ld minor faults (COW triggered)\n", 
               usage.ru_minflt - faults_before);
        
        free(mem);
        _exit(0);
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        
        printf("[parent] Child completed\n");
    } else {
        perror("fork");
    }
    
    free(mem);
    
    printf("\nCopy-on-Write: Child shares parent's pages until write occurs\n");
    printf("Writing triggers page fault and creates new physical page\n");
}

int main(void) {
    printf("Page Fault and Demand Paging Demonstration\n");
    printf("===========================================\n\n");
    
    printf("Page Size: %ld bytes\n", sysconf(_SC_PAGESIZE));
    printf("PID: %d\n\n", getpid());
    
    demonstrate_page_faults();
    demonstrate_copy_on_write();
    
    printf("\n=== Summary ===\n\n");
    printf("Minor page faults: Page not in memory, no disk I/O\n");
    printf("Major page faults: Page must be loaded from disk\n");
    printf("Demand paging: Pages allocated only when accessed\n");
    printf("Copy-on-Write: Shared pages until write operation\n");
    
    return 0;
}

