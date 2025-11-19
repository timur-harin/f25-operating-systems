#define _XOPEN_SOURCE 700
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
static pthread_t workers[2];

static void lock_and_hold(pthread_mutex_t *first, pthread_mutex_t *second, const char *name) {
	printf("[%s] locking first mutex...\n", name);
	pthread_mutex_lock(first);
	sleep(1);
	printf("[%s] locking second mutex...\n", name);
	pthread_mutex_lock(second);
	printf("[%s] acquired both mutexes (should never happen if deadlock triggered)\n", name);
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
}

static void *worker0(void *arg) {
	(void)arg;
	lock_and_hold(&m1, &m2, "T0");
	return NULL;
}

static void *worker1(void *arg) {
	(void)arg;
	lock_and_hold(&m2, &m1, "T1");
	return NULL;
}

static void *watchdog(void *arg) {
	(void)arg;
	sleep(3);
	if (pthread_mutex_trylock(&m1) != 0 && pthread_mutex_trylock(&m2) != 0) {
		puts("[watchdog] Deadlock detected! Both threads are waiting on each other.");
		puts("[watchdog] Breaking deadlock by cancelling workers...");
		pthread_cancel(workers[0]);
		pthread_cancel(workers[1]);
		pthread_mutex_unlock(&m1);
		pthread_mutex_unlock(&m2);
	}
	return NULL;
}

int main(void) {
	pthread_t wd;
	puts("Deadlock simulator: T0 locks (m1 -> m2), T1 locks (m2 -> m1).");
	puts("A watchdog thread tries to detect the circular wait.");
	pthread_create(&workers[0], NULL, worker0, NULL);
	pthread_create(&workers[1], NULL, worker1, NULL);
	pthread_create(&wd, NULL, watchdog, NULL);
	pthread_join(wd, NULL);
	pthread_join(workers[0], NULL);
	pthread_join(workers[1], NULL);
	puts("Simulation finished.");
	return 0;
}


