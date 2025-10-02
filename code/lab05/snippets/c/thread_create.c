#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    long thread_num = (long)arg;
    pthread_t tid = pthread_self();
    
    printf("[thread %ld] pthread_self()=%lu, starting...\n", thread_num, (unsigned long)tid);
    fflush(stdout);
    
    sleep(1); // Simulate some work
    
    printf("[thread %ld] pthread_self()=%lu, finishing\n", thread_num, (unsigned long)tid);
    fflush(stdout);
    
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    
    printf("[main  ] PID=%d: Creating threads...\n", getpid());
    fflush(stdout);

    // Create first thread
    if (pthread_create(&thread1, NULL, thread_function, (void *)1) != 0) {
        perror("pthread_create");
        return 1;
    }
    printf("[main  ] Created thread 1 (pthread_t=%lu)\n", (unsigned long)thread1);
    fflush(stdout);

    // Create second thread
    if (pthread_create(&thread2, NULL, thread_function, (void *)2) != 0) {
        perror("pthread_create");
        return 1;
    }
    printf("[main  ] Created thread 2 (pthread_t=%lu)\n", (unsigned long)thread2);
    fflush(stdout);

    // Wait for both threads to complete
    pthread_join(thread1, NULL);
    printf("[main  ] Thread 1 joined\n");
    fflush(stdout);

    pthread_join(thread2, NULL);
    printf("[main  ] Thread 2 joined\n");
    fflush(stdout);

    printf("[main  ] All threads completed. Exiting.\n");
    return 0;
}

