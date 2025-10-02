#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define INCREMENTS 1000000

// Global shared counter (critical section data)
long counter = 0;

void *increment_counter(void *arg) {
    long thread_num = (long)arg;
    
    printf("[thread %ld] Starting increments...\n", thread_num);
    fflush(stdout);
    
    for (int i = 0; i < INCREMENTS; i++) {
        // CRITICAL SECTION: Reading and writing shared variable
        counter++;  // This is NOT atomic!
    }
    
    printf("[thread %ld] Finished increments\n", thread_num);
    fflush(stdout);
    
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    
    printf("[main  ] Initial counter value: %ld\n", counter);
    printf("[main  ] Expected final value: %d\n", NUM_THREADS * INCREMENTS);
    printf("[main  ] Creating %d threads...\n", NUM_THREADS);
    fflush(stdout);

    // Create threads
    for (long i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, increment_counter, (void *)i) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n[main  ] Final counter value: %ld\n", counter);
    printf("[main  ] Expected: %d, Got: %ld, Difference: %ld\n",
           NUM_THREADS * INCREMENTS, counter, (NUM_THREADS * INCREMENTS) - counter);
    
    if (counter != NUM_THREADS * INCREMENTS) {
        printf("[main  ] ⚠️  RACE CONDITION DETECTED! Values don't match.\n");
    } else {
        printf("[main  ] ✓ Values match (but race condition still exists!)\n");
    }

    return 0;
}

