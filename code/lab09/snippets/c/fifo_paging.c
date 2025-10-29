#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10
#define MAX_PAGES 20

int frames[MAX_FRAMES];
int frame_count;

void init_frames(int n) {
    frame_count = n;
    for (int i = 0; i < n; i++) {
        frames[i] = -1;  // Empty frame
    }
}

int is_in_frame(int page) {
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == page) return 1;
    }
    return 0;
}

void print_frames(void) {
    printf("Frames: [");
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frames[i]);
        }
    }
    printf("]\n");
}

int fifo_replace(int pages[], int n) {
    int page_faults = 0;
    int next_frame = 0;  // FIFO pointer
    
    printf("=== FIFO Page Replacement ===\n\n");
    printf("Reference String: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");
    printf("Frames: %d\n\n", frame_count);
    
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        printf("Page %d: ", page);
        
        if (is_in_frame(page)) {
            printf("HIT  ");
            print_frames();
        } else {
            printf("MISS ");
            frames[next_frame] = page;
            next_frame = (next_frame + 1) % frame_count;
            page_faults++;
            print_frames();
        }
    }
    
    return page_faults;
}

int main(void) {
    printf("FIFO (First-In-First-Out) Page Replacement\n");
    printf("===========================================\n\n");
    
    int pages[] = {1, 2, 3, 4, 5, 1, 3, 1, 6, 3, 2, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames_num = 4;
    
    init_frames(frames_num);
    int faults = fifo_replace(pages, n);
    
    printf("\n=== Results ===\n\n");
    printf("Total References: %d\n", n);
    printf("Page Faults (Misses): %d\n", faults);
    printf("Page Hits: %d\n", n - faults);
    printf("Hit Rate: %.2f%%\n", (n - faults) * 100.0 / n);
    printf("Fault Rate: %.2f%%\n", faults * 100.0 / n);
    
    printf("\n=== FIFO Characteristics ===\n\n");
    printf("Advantages:\n");
    printf("  - Simple to implement\n");
    printf("  - Low overhead\n");
    printf("  - Fair (oldest page replaced)\n\n");
    
    printf("Disadvantages:\n");
    printf("  - Suffers from Belady's Anomaly\n");
    printf("  - Doesn't consider page usage frequency\n");
    printf("  - May replace frequently used pages\n");
    
    return 0;
}

