#include <stdio.h>
#include <stdint.h>
#include <math.h>

void calculate_pages(uint64_t address_bits, uint64_t page_size_kb) {
    printf("=== Page Calculation ===\n\n");
    
    uint64_t page_size_bytes = page_size_kb * 1024;
    uint64_t offset_bits = (uint64_t)log2(page_size_bytes);
    uint64_t page_number_bits = address_bits - offset_bits;
    
    uint64_t total_pages = (uint64_t)1 << page_number_bits;
    uint64_t total_addressable_space = (uint64_t)1 << address_bits;
    
    printf("Address Space: %lu-bit\n", address_bits);
    printf("Page Size: %lu KB (%lu bytes)\n", page_size_kb, page_size_bytes);
    printf("\n");
    
    printf("Virtual Address Breakdown:\n");
    printf("  Total bits: %lu\n", address_bits);
    printf("  Page number bits: %lu\n", page_number_bits);
    printf("  Offset bits: %lu\n", offset_bits);
    printf("\n");
    
    printf("Number of pages: 2^%lu = ", page_number_bits);
    if (total_pages >= 1024*1024*1024) {
        printf("%.2f billion\n", total_pages / (1024.0*1024.0*1024.0));
    } else if (total_pages >= 1024*1024) {
        printf("%.2f million\n", total_pages / (1024.0*1024.0));
    } else if (total_pages >= 1024) {
        printf("%.2f thousand\n", total_pages / 1024.0);
    } else {
        printf("%lu\n", total_pages);
    }
    
    printf("Total addressable space: ");
    if (total_addressable_space >= 1024ULL*1024*1024*1024*1024) {
        printf("%.2f PB\n", total_addressable_space / (1024.0*1024*1024*1024*1024));
    } else if (total_addressable_space >= 1024ULL*1024*1024*1024) {
        printf("%.2f TB\n", total_addressable_space / (1024.0*1024*1024*1024));
    } else if (total_addressable_space >= 1024ULL*1024*1024) {
        printf("%.2f GB\n", total_addressable_space / (1024.0*1024*1024));
    } else {
        printf("%lu bytes\n", total_addressable_space);
    }
}

void demonstrate_address_translation(void) {
    printf("\n=== Address Translation Example ===\n\n");
    
    // 32-bit address with 4KB pages
    uint32_t virtual_addr = 0x12345678;  // Example virtual address
    uint32_t page_size = 4096;  // 4KB = 2^12 bytes
    uint32_t offset_bits = 12;
    
    uint32_t page_number = virtual_addr >> offset_bits;
    uint32_t offset = virtual_addr & ((1 << offset_bits) - 1);
    
    printf("Virtual Address: 0x%08X\n", virtual_addr);
    printf("Page Size: %u bytes (2^%u)\n", page_size, offset_bits);
    printf("\n");
    
    printf("Translation:\n");
    printf("  Page Number: 0x%05X (%u)\n", page_number, page_number);
    printf("  Offset: 0x%03X (%u bytes)\n", offset, offset);
    printf("\n");
    
    // Simulate page table lookup
    uint32_t frame_number = 0x1AB;  // Example frame from page table
    uint32_t physical_addr = (frame_number << offset_bits) | offset;
    
    printf("Page Table Lookup:\n");
    printf("  Frame Number: 0x%03X (%u)\n", frame_number, frame_number);
    printf("\n");
    
    printf("Physical Address: 0x%08X\n", physical_addr);
    printf("  = (Frame %u << %u) | Offset %u\n", frame_number, offset_bits, offset);
}

int main(void) {
    printf("Virtual Memory Address Calculation\n");
    printf("===================================\n\n");
    
    // Example 1: 32-bit system with 4KB pages
    calculate_pages(32, 4);
    
    printf("\n---\n");
    
    // Example 2: 64-bit system with 4KB pages
    calculate_pages(64, 4);
    
    printf("\n---\n");
    
    // Example 3: 36-bit system with 8KB pages (from lecture)
    calculate_pages(36, 8);
    
    demonstrate_address_translation();
    
    printf("\n=== Key Concepts ===\n\n");
    printf("- Virtual address = Page number + Offset\n");
    printf("- Page table maps: Virtual page → Physical frame\n");
    printf("- Physical address = Frame number + Offset\n");
    printf("- Offset stays the same in translation\n");
    printf("- Page size determines offset bits\n");
    
    return 0;
}

