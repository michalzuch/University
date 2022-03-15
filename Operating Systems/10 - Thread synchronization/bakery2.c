#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// MACROS
#define NUMBER_OF_THREADS 80
#define NUMBER_OF_ITERATIONS 100

// GLOBAL VARIABLES
volatile int tickets[NUMBER_OF_THREADS];
volatile int choosing[NUMBER_OF_THREADS];
volatile int counter = 0;  // Counts entering to critical section
int expected_counter = NUMBER_OF_ITERATIONS * NUMBER_OF_THREADS;

// FUNCTIONS
void lock(int thread);
void unlock(int thread);
void* thread_function(void* iteration);

// MAIN
int main(void) {

    pthread_t threadID[NUMBER_OF_THREADS];  // Array for IDs assigned to threads

    // Creating threads
    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        pthread_create(&threadID[i], NULL, &thread_function, (void*)((long)i));
    }

    // Waiting for threads
    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        pthread_join(threadID[i], NULL);
    }

    printf("Counter: %d\nExpected counter: %d\n", counter, expected_counter);  // Print counter and expected counter
    return 0;
}

void lock(int thread) {
    __sync_synchronize();
    choosing[thread] = 1;  // Lock choosing operation
    int max_ticket = 0;

    // Asigning tickets
    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        int ticket = tickets[i];
        max_ticket = ticket > max_ticket ? ticket : max_ticket;
    }

    tickets[thread] = max_ticket + 1;
    __sync_synchronize();
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
        lock(thread);
        counter++;
        unlock(thread);
    }
    pthread_exit(NULL);
    return NULL;
}
