#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_FRAMES 10

typedef struct {
    int page;
    int last_used;
} Frame;

Frame frames[MAX_FRAMES];
int frame_count;

void init_frames(int n) {
    frame_count = n;
    for (int i = 0; i < n; i++) {
        frames[i].page = -1;
        frames[i].last_used = 0;
    }
}

int find_page(int page) {
    for (int i = 0; i < frame_count; i++) {
        if (frames[i].page == page) return i;
    }
    return -1;
}

int find_lru(void) {
    int lru_idx = 0;
    int min_time = INT_MAX;
    
    for (int i = 0; i < frame_count; i++) {
        if (frames[i].page == -1) return i;  // Empty frame
        if (frames[i].last_used < min_time) {
            min_time = frames[i].last_used;
            lru_idx = i;
        }
    }
    return lru_idx;
}

void print_frames(void) {
    printf("Frames: [");
    for (int i = 0; i < frame_count; i++) {
        if (frames[i].page == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frames[i].page);
        }
    }
    printf("]\n");
}

int lru_replace(int pages[], int n) {
    int page_faults = 0;
    
    printf("=== LRU Page Replacement ===\n\n");
    printf("Reference String: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");
    printf("Frames: %d\n\n", frame_count);
    
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        printf("Page %d: ", page);
        
        int idx = find_page(page);
        
        if (idx != -1) {
            // Page hit - update last used time
            printf("HIT  ");
            frames[idx].last_used = i;
            print_frames();
        } else {
            // Page fault - find LRU and replace
            printf("MISS ");
            int lru_idx = find_lru();
            frames[lru_idx].page = page;
            frames[lru_idx].last_used = i;
            page_faults++;
            print_frames();
        }
    }
    
    return page_faults;
}

int main(void) {
    printf("LRU (Least Recently Used) Page Replacement\n");
    printf("===========================================\n\n");
    
    int pages[] = {1, 2, 3, 4, 5, 1, 3, 1, 6, 3, 2, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames_num = 4;
    
    init_frames(frames_num);
    int faults = lru_replace(pages, n);
    
    printf("\n=== Results ===\n\n");
    printf("Total References: %d\n", n);
    printf("Page Faults (Misses): %d\n", faults);
    printf("Page Hits: %d\n", n - faults);
    printf("Hit Rate: %.2f%%\n", (n - faults) * 100.0 / n);
    printf("Fault Rate: %.2f%%\n", faults * 100.0 / n);
    
    printf("\n=== LRU Characteristics ===\n\n");
    printf("Advantages:\n");
    printf("  - Optimal among practical algorithms\n");
    printf("  - Considers recent usage pattern\n");
    printf("  - No Belady's Anomaly (stack algorithm)\n\n");
    
    printf("Disadvantages:\n");
    printf("  - Higher overhead to track usage\n");
    printf("  - Expensive to implement perfectly\n");
    printf("  - Requires hardware support or approximation\n");
    
    return 0;
}

