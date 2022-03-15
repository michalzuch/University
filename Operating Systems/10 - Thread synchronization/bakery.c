#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// MACROS
#define NUMBER_OF_THREADS 8
#define NUMBER_OF_ITERATIONS 20

// GLOBAL VARIABLES
volatile int tickets[NUMBER_OF_THREADS];
volatile int choosing[NUMBER_OF_THREADS];
volatile int counter = 0;  // Counts entering to critical section

// FUNCTIONS
void lock(int thread);
void unlock(int thread);
void* thread_function(void* iteration);

// MAIN
int main(void) {
    printf("\033c");  // Clear screen

    pthread_t threadID[NUMBER_OF_THREADS];  // Array for IDs assigned to threads
    
    // Header
    printf("\033[%d;%dHTHREAD NR    PRIVATE SECTION    CRITICAL SECTION\n", 1, 1);

    // Creating threads
    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        pthread_create(&threadID[i], NULL, &thread_function, (void*)((long)i));
        printf("\033[%d;%dH\033[0mthread %2d\n", i + 2, 0, i + 1);  // Print thread and number
    }

    // Waiting for threads
    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        pthread_join(threadID[i], NULL);
    }

    printf("\033[%d;%dH\033[0mCounter: %d\n", 2 * NUMBER_OF_THREADS, 0, counter);  // Print counter
    sleep(5);
    printf("\033c");  // Clear screen
    return 0;
}

void lock(int thread) {

    choosing[thread] = 1;  // Lock choosing operation
    int max_ticket = 0;

    // Asigning tickets
    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        int ticket = tickets[i];
        max_ticket = ticket > max_ticket ? ticket : max_ticket;
    }

    tickets[thread] = max_ticket + 1;
    choosing[thread] = 0;  // Unlock choosing operation

    // Providing access to critical section via tickets
    for (int j = 0; j < NUMBER_OF_THREADS; j++) {
        // Wait until thread receive its number
        while (choosing[j]);
        // Wait until all threads that are first in queue finish their work
        // Comparing (a1, b1) and (a2, b2), where a is ticket's number and b is thread's ID
        while(tickets[j] != 0 && ((tickets[j] < tickets[thread]) || (tickets[j] == tickets[thread] && j < thread)));
    }
}

void unlock(int thread) {
    tickets[thread] = 0;
}

void* thread_function(void* iteration) {
    long thread = (long)iteration;

    for(int i = 0; i < NUMBER_OF_ITERATIONS; i++) {
        // Waiting
        printf("\033[%ld;%dH\033[K\033[32mWaiting\n", thread + 2, 14);

        lock(thread);
        
        // Critical section
        printf("\033[%ld;%dH\033[K", thread + 2, 14);
        printf("\033[%ld;%dH\033[K\033[31mCritical section\n", thread + 2, 33);
        counter++;

        usleep(100000);
        unlock(thread);

        // Sleeping
        printf("\033[%ld;%dH\033[K\033[36mSleeping\n", thread + 2, 14);
        usleep(100000);
    }
    // Finished
    printf("\033[%ld;%dH\033[K\033[33mFinished\n", thread + 2, 14);
    pthread_exit(NULL);
    return NULL;
}