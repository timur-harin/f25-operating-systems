#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

typedef struct {
    int thread_num;
    int compute_time;
} thread_data_t;

void *worker_thread(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    
    printf("[thread %d] Starting work (will take %d seconds)...\n", 
           data->thread_num, data->compute_time);
    fflush(stdout);
    
    sleep(data->compute_time); // Simulate computation
    
    int *result = malloc(sizeof(int));
    *result = data->thread_num * 10; // Some computed result
    
    printf("[thread %d] Work completed, returning result: %d\n", 
           data->thread_num, *result);
    fflush(stdout);
    
    return (void *)result;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];
    
    printf("[main  ] Creating %d threads...\n", NUM_THREADS);
    fflush(stdout);

    // Create threads with different work durations
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_num = i + 1;
        thread_data[i].compute_time = NUM_THREADS - i; // 3, 2, 1 seconds
        
        if (pthread_create(&threads[i], NULL, worker_thread, &thread_data[i]) != 0) {
            perror("pthread_create");
            return 1;
        }
        printf("[main  ] Thread %d created\n", i + 1);
        fflush(stdout);
    }

    printf("\n[main  ] All threads created. Now waiting for them to finish...\n\n");
    fflush(stdout);

    // Join threads and collect results
    int total = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        void *result_ptr;
        
        printf("[main  ] Waiting for thread %d...\n", i + 1);
        fflush(stdout);
        
        if (pthread_join(threads[i], &result_ptr) != 0) {
            perror("pthread_join");
            return 1;
        }
        
        int *result = (int *)result_ptr;
        printf("[main  ] Thread %d joined, returned: %d\n", i + 1, *result);
        fflush(stdout);
        
        total += *result;
        free(result);
    }

    printf("\n[main  ] All threads completed!\n");
    printf("[main  ] Total sum of results: %d\n", total);

    return 0;
}

