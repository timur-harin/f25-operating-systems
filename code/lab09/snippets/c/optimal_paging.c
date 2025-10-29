#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_FRAMES 10

int frames[MAX_FRAMES];
int frame_count;

void init_frames(int n) {
    frame_count = n;
    for (int i = 0; i < n; i++) {
        frames[i] = -1;
    }
}

int find_page(int page) {
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == page) return i;
    }
    return -1;
}

int predict_future(int pages[], int n, int current, int page) {
    // Find when this page will be used next
    for (int i = current + 1; i < n; i++) {
        if (pages[i] == page) return i;
    }
    return INT_MAX;  // Not used again
}

int find_optimal(int pages[], int n, int current) {
    int farthest = -1;
    int replace_idx = 0;
    
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == -1) return i;  // Empty frame
        
        int next_use = predict_future(pages, n, current, frames[i]);
        if (next_use > farthest) {
            farthest = next_use;
            replace_idx = i;
        }
    }
    return replace_idx;
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

int optimal_replace(int pages[], int n) {
    int page_faults = 0;
    
    printf("=== Optimal Page Replacement ===\n\n");
    printf("Reference String: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");
    printf("Frames: %d\n\n", frame_count);
    
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        printf("Page %d: ", page);
        
        if (find_page(page) != -1) {
            printf("HIT  ");
            print_frames();
        } else {
            printf("MISS ");
            int idx = find_optimal(pages, n, i);
            frames[idx] = page;
            page_faults++;
            print_frames();
        }
    }
    
    return page_faults;
}

int main(void) {
    printf("Optimal Page Replacement Algorithm\n");
    printf("===================================\n\n");
    
    int pages[] = {1, 2, 3, 4, 5, 1, 3, 1, 6, 3, 2, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames_num = 4;
    
    init_frames(frames_num);
    int faults = optimal_replace(pages, n);
    
    printf("\n=== Results ===\n\n");
    printf("Total References: %d\n", n);
    printf("Page Faults (Misses): %d\n", faults);
    printf("Page Hits: %d\n", n - faults);
    printf("Hit Rate: %.2f%%\n", (n - faults) * 100.0 / n);
    printf("Fault Rate: %.2f%%\n", faults * 100.0 / n);
    
    printf("\n=== Optimal Characteristics ===\n\n");
    printf("Theoretical Algorithm (Belady's Algorithm):\n");
    printf("  - Lowest possible page fault rate\n");
    printf("  - Replaces page not needed for longest time\n");
    printf("  - Used as benchmark for other algorithms\n\n");
    
    printf("Limitation:\n");
    printf("  - Requires future knowledge (impossible in practice)\n");
    printf("  - Used only for comparison/analysis\n");
    
    return 0;
}

