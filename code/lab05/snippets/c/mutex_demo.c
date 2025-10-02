#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define INCREMENTS 100000

// Global shared counter
long counter = 0;

// Mutex to protect the counter
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment_counter_safe(void *arg) {
    long thread_num = (long)arg;
    
    printf("[thread %ld] Starting increments with mutex protection...\n", thread_num);
    fflush(stdout);
    
    for (int i = 0; i < INCREMENTS; i++) {
        // Lock mutex before accessing critical section
        pthread_mutex_lock(&counter_mutex);
        
        // CRITICAL SECTION: Now protected by mutex
        counter++;
        
        // Unlock mutex after modifying shared data
        pthread_mutex_unlock(&counter_mutex);
    }
    
    printf("[thread %ld] Finished increments\n", thread_num);
    fflush(stdout);
    
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    
    printf("[main  ] Initial counter value: %ld\n", counter);
    printf("[main  ] Expected final value: %d\n", NUM_THREADS * INCREMENTS);
    printf("[main  ] Creating %d threads with mutex protection...\n", NUM_THREADS);
    fflush(stdout);

    // Create threads
    for (long i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, increment_counter_safe, (void *)i) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n[main  ] Final counter value: %ld\n", counter);
    printf("[main  ] Expected: %d, Got: %ld\n",
           NUM_THREADS * INCREMENTS, counter);
    
    if (counter == NUM_THREADS * INCREMENTS) {
        printf("[main  ] ✓ SUCCESS! Mutex prevented race condition.\n");
    } else {
        printf("[main  ] ⚠️  ERROR: Values don't match (difference: %ld)\n",
               (NUM_THREADS * INCREMENTS) - counter);
    }

    // Cleanup
    pthread_mutex_destroy(&counter_mutex);

    return 0;
}

