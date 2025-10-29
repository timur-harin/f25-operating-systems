#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

void demonstrate_anonymous_mapping(void) {
    printf("=== Anonymous Memory Mapping ===\n\n");
    
    size_t size = 4096 * 10;  // 10 pages
    
    // Create anonymous mapping (not backed by file)
    void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    
    if (addr == MAP_FAILED) {
        perror("mmap");
        return;
    }
    
    printf("Mapped %zu bytes at address: %p\n", size, addr);
    printf("Flags: MAP_PRIVATE | MAP_ANONYMOUS\n");
    printf("Protection: PROT_READ | PROT_WRITE\n\n");
    
    // Use the memory
    char *mem = (char *)addr;
    strcpy(mem, "Hello from mmap!");
    printf("Data written: '%s'\n", mem);
    printf("Address: %p\n\n", (void *)mem);
    
    // Unmap
    if (munmap(addr, size) == -1) {
        perror("munmap");
    } else {
        printf("Memory unmapped successfully\n");
    }
}

void demonstrate_shared_mapping(void) {
    printf("\n=== Shared Memory Mapping ===\n\n");
    
    size_t size = 4096;
    
    // Create shared anonymous mapping
    void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE,
                      MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    
    if (addr == MAP_FAILED) {
        perror("mmap");
        return;
    }
    
    char *shared_mem = (char *)addr;
    printf("Shared memory at: %p\n", addr);
    
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        sleep(1);  // Wait for parent to write
        printf("[child ] Read from shared memory: '%s'\n", shared_mem);
        strcpy(shared_mem, "Modified by child");
        _exit(0);
    } else if (pid > 0) {
        // Parent process
        strcpy(shared_mem, "Hello from parent");
        printf("[parent] Wrote to shared memory: '%s'\n", shared_mem);
        
        int status;
        waitpid(pid, &status, 0);
        
        printf("[parent] Read after child: '%s'\n", shared_mem);
        
        munmap(addr, size);
    } else {
        perror("fork");
    }
}

void demonstrate_file_mapping(void) {
    printf("\n=== File-Backed Memory Mapping ===\n\n");
    
    const char *filename = "/tmp/mmap_test.txt";
    const char *data = "This data is memory-mapped from a file!";
    size_t size = strlen(data) + 1;
    
    // Create and write to file
    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return;
    }
    
    // Set file size
    if (ftruncate(fd, size) == -1) {
        perror("ftruncate");
        close(fd);
        return;
    }
    
    // Map file to memory
    void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    
    if (addr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return;
    }
    
    printf("File '%s' mapped at: %p\n", filename, addr);
    
    // Write to mapped memory (writes to file)
    char *file_mem = (char *)addr;
    strcpy(file_mem, data);
    printf("Wrote to mmap: '%s'\n", file_mem);
    
    // Synchronize (ensure written to disk)
    if (msync(addr, size, MS_SYNC) == -1) {
        perror("msync");
    }
    
    printf("Data synchronized to disk\n");
    
    munmap(addr, size);
    close(fd);
    
    // Verify by reading file normally
    fd = open(filename, O_RDONLY);
    char buffer[256];
    read(fd, buffer, sizeof(buffer));
    printf("Reading file normally: '%s'\n", buffer);
    close(fd);
    
    unlink(filename);
}

int main(void) {
    printf("Memory Mapping (mmap) Demonstration\n");
    printf("====================================\n\n");
    
    printf("Page size: %ld bytes\n", sysconf(_SC_PAGESIZE));
    printf("PID: %d\n\n", getpid());
    
    demonstrate_anonymous_mapping();
    demonstrate_shared_mapping();
    demonstrate_file_mapping();
    
    printf("\n=== Summary ===\n\n");
    printf("mmap() maps files or devices into memory\n");
    printf("MAP_ANONYMOUS: Memory not backed by file\n");
    printf("MAP_SHARED: Changes visible to other processes\n");
    printf("MAP_PRIVATE: Copy-on-write, private changes\n");
    printf("File mapping: Efficient file I/O via memory access\n");
    
    return 0;
}

