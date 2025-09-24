#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    long iterations;
    int use_mutex;
} WorkerArgs;

static long shared_counter = 0;
static pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

static void *worker(void *arg) {
    WorkerArgs *args = (WorkerArgs *)arg;
    for (long i = 0; i < args->iterations; i++) {
        if (args->use_mutex) {
            pthread_mutex_lock(&counter_mutex);
            shared_counter++;
            pthread_mutex_unlock(&counter_mutex);
        } else {
            shared_counter++;
        }
    }
    // Print thread info
    printf("[thread] PID=%d pthread_self=%lu done\n", getpid(), (unsigned long)pthread_self());
    fflush(stdout);
    return NULL;
}

int main(int argc, char **argv) {
    int num_threads = 8;
    long iterations_per_thread = 500000;
    int use_mutex = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i] && argv[i][0] == '-') {
            if (!strcmp(argv[i], "--threads") && i + 1 < argc) {
                num_threads = atoi(argv[++i]);
            } else if (!strcmp(argv[i], "--iters") && i + 1 < argc) {
                iterations_per_thread = atol(argv[++i]);
            } else if (!strcmp(argv[i], "--mutex")) {
                use_mutex = 1;
            }
        }
    }

    printf("[main  ] PID=%d starting %d threads; iters=%ld; mutex=%s\n",
           getpid(), num_threads, iterations_per_thread, use_mutex ? "on" : "off");
    fflush(stdout);

    pthread_t *threads = (pthread_t *)calloc((size_t)num_threads, sizeof(pthread_t));
    WorkerArgs args = { .iterations = iterations_per_thread, .use_mutex = use_mutex };

    for (int t = 0; t < num_threads; t++) {
        int rc = pthread_create(&threads[t], NULL, worker, &args);
        if (rc != 0) {
            fprintf(stderr, "pthread_create failed: %d\n", rc);
            return 1;
        }
    }

    for (int t = 0; t < num_threads; t++) {
        pthread_join(threads[t], NULL);
    }
    free(threads);

    long expected = num_threads * iterations_per_thread;
    printf("[main  ] shared_counter=%ld expected=%ld %s\n", shared_counter, expected,
           (use_mutex && shared_counter == expected) ? "(OK)" : (!use_mutex ? "(race likely)" : "(mismatch)"));
    fflush(stdout);
    return 0;
}


