#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// MACROS
#define NUMBER_OF_ITERATIONS 10

// GLOBAL VARIABLES
int counter = 0;
int n_of_threads;
pthread_mutex_t mutex;

// FUNCTIONS
void* thread(void* ptr);
void arguments_check(int arguments);

// MAIN
int main(int argc, const char* argv[]) {
    printf("\033c");  // Clear the screen
    arguments_check(argc);

    n_of_threads = atoi(argv[1]);
    int i;
    pthread_t threadID[n_of_threads];
    
    // Header
    printf("\033[%d;%dHTHREAD NR    PRIVATE SECTION    CRITICAL SECTION\n", 1, 1);

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);
    printf("\033[%d;%dH\033[0m** Mutex inicialized at address %p\n",5 * (n_of_threads), 0, (void *)&mutex);

    // Creating threads
    for (i = 0; i < n_of_threads; i++) {
        int *iteration = malloc(sizeof(int));
        *iteration = i + 1;
        pthread_create(&threadID[i], NULL, thread, iteration);
        printf("\033[%d;%dH\033[0mthread %2d\n", i + 2, 0, i + 1);  // Print thread and number, below thread initialization
        printf("\033[%d;%dH\033[0m-- Thread number %d inicialized at address %ld\n", 5 * (n_of_threads) + i + 1, 0, i + 1 , threadID[i]);
    }
    // Waiting for threads
    for (i = 0; i < n_of_threads; i++) {
        pthread_join(threadID[i], NULL);
        printf("\033[%d;%dH\033[K", 5 * (n_of_threads) + i + 1, 0);
        printf("\033[%d;%dH\033[0m-- Thread number %d finished at address %ld\n", 5 * (n_of_threads) + i + 1, 0, i + 1 , threadID[i]);
    }

    printf("\033[0mCounter: %d\n", counter);  // Print counter (counts entering to critical section)
    pthread_mutex_destroy(&mutex);  // Remove mutex
    sleep(5);
    printf("\033c");  // Clear screen
    return 0;
}

// FUNCTIONS
void* thread(void* ptr) {

    int iteration = *(int *)ptr;
    int i;

    for (i = 0; i < NUMBER_OF_ITERATIONS; i++) {
        // Waiting
        printf("\033[%d;%dH\033[K\033[32mWaiting\n", iteration + 1, 14);
        usleep(10);

        pthread_mutex_lock(&mutex);

        // Critical section
        printf("\033[%d;%dH\033[K", iteration + 1, 14);
        printf("\033[%d;%dH\033[K\033[31mCritical section\n", iteration + 1, 33);
        counter++;

        usleep(100000);
        pthread_mutex_unlock(&mutex);

        // Sleeping
        printf("\033[%d;%dH\033[K\033[36mSleeping\n", iteration + 1, 14);
        usleep(100000);
    }
    // Finished
    printf("\033[%d;%dH\033[K\033[33mFinished\n", iteration + 1, 14);
    pthread_exit(NULL);
    return NULL;
}

void arguments_check(int arguments) {
    if (arguments != 2) {
        printf("Invalid arguments.\nType the amount of threads.\n");
        exit(EXIT_FAILURE);
    }
}