#include <stdio.h>
#include <string.h>

#define MAX_FRAMES 10

// Simple implementations for comparison
int simulate_fifo(int pages[], int n, int frames[], int nframes);
int simulate_lru(int pages[], int n, int frames[], int nframes);
int simulate_optimal(int pages[], int n, int frames[], int nframes);

int main(void) {
    printf("Page Replacement Algorithm Comparison\n");
    printf("======================================\n\n");
    
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int n = sizeof(pages) / sizeof(pages[0]);
    
    printf("Reference String: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");
    printf("Length: %d references\n\n", n);
    
    printf("%-15s", "Frames");
    printf("%-12s", "FIFO");
    printf("%-12s", "LRU");
    printf("%-12s", "Optimal");
    printf("\n");
    printf("%-15s%-12s%-12s%-12s\n", "------", "----", "---", "-------");
    
    for (int nframes = 1; nframes <= 7; nframes++) {
        int frames[MAX_FRAMES];
        
        int fifo_faults = simulate_fifo(pages, n, frames, nframes);
        int lru_faults = simulate_lru(pages, n, frames, nframes);
        int optimal_faults = simulate_optimal(pages, n, frames, nframes);
        
        printf("%-15d%-12d%-12d%-12d\n", nframes, fifo_faults, lru_faults, optimal_faults);
    }
    
    printf("\n=== Observations ===\n\n");
    printf("1. Optimal always has lowest faults (theoretical minimum)\n");
    printf("2. LRU often close to optimal in practice\n");
    printf("3. FIFO may show Belady's Anomaly (more frames → more faults)\n");
    printf("4. Performance depends on reference pattern\n");
    
    return 0;
}

// Simplified implementations
int simulate_fifo(int pages[], int n, int frames[], int nframes) {
    for (int i = 0; i < nframes; i++) frames[i] = -1;
    int faults = 0, next = 0;
    
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < nframes; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frames[next] = pages[i];
            next = (next + 1) % nframes;
            faults++;
        }
    }
    return faults;
}

int simulate_lru(int pages[], int n, int frames[], int nframes) {
    for (int i = 0; i < nframes; i++) frames[i] = -1;
    int faults = 0;
    int last_used[MAX_FRAMES] = {0};
    
    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < nframes; j++) {
            if (frames[j] == pages[i]) {
                found = j;
                break;
            }
        }
        
        if (found != -1) {
            last_used[found] = i;
        } else {
            int lru = 0;
            for (int j = 1; j < nframes; j++) {
                if (frames[j] == -1) {
                    lru = j;
                    break;
                }
                if (last_used[j] < last_used[lru]) lru = j;
            }
            frames[lru] = pages[i];
            last_used[lru] = i;
            faults++;
        }
    }
    return faults;
}

int simulate_optimal(int pages[], int n, int frames[], int nframes) {
    for (int i = 0; i < nframes; i++) frames[i] = -1;
    int faults = 0;
    
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < nframes; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            int replace = -1;
            int farthest = i;
            for (int j = 0; j < nframes; j++) {
                if (frames[j] == -1) {
                    replace = j;
                    break;
                }
                int next_use = n;
                for (int k = i + 1; k < n; k++) {
                    if (pages[k] == frames[j]) {
                        next_use = k;
                        break;
                    }
                }
                if (next_use > farthest) {
                    farthest = next_use;
                    replace = j;
                }
            }
            frames[replace] = pages[i];
            faults++;
        }
    }
    return faults;
}

