#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "sem.h"
#include "shmem.h"

#define CAPACITY 20
#define SIZE 5
#define COPY_SIZE 1

typedef int towar;
typedef struct {
    int size;
    int beg;
    int end;
    char buf[SIZE][CAPACITY];
} Circular;

void push(int fileDescriptor, Circular *ptr, int reading);

const char* sem_prod = "/sem_prod";
const char* sem_cons = "/sem_cons";
const char* shared_memory = "/shared_memory";

semid semaphoreProd;
semid semaphoreCons;
int sharedMemory;
int fileDescriptor;
int reading = 1;
int writing = 1;

int main(void) {

    // Opening ceremony
    semaphoreProd = semOpen(sem_prod);
    semaphoreCons = semOpen(sem_cons);
    sharedMemory = shmOpen(shared_memory);
    fileDescriptor = open("storage.txt", O_RDONLY);

    int size = shmSize(sharedMemory);

    Circular *ptr = (Circular *) shmMap(sharedMemory, size);

    ptr->end = 0;

    push(fileDescriptor, ptr, reading);

    strcpy(ptr->buf[ptr->end], "\0");

    semClose(semaphoreCons);
    semClose(semaphoreProd);
    shmClose(ptr, sharedMemory, size);

    return 0;
}

void push(int fileDescriptor, Circular *ptr, int reading) {
    while (reading > 0) {
        semP(semaphoreProd);
        
        reading = read(fileDescriptor, ptr->buf[ptr->end], COPY_SIZE);
        if (reading == -1) {
            perror("Error while reading files");
            exit(EXIT_FAILURE);
        }
        if (reading == 0) {
            break;
        }
        printf("Producer: %s\n", ptr->buf[ptr->end]);
        printf("\n");

        // Cyclicity of the buffer
        ptr->end++;
        if (ptr->end == SIZE) {
            ptr->end = 0;
        }

        semV(semaphoreCons);
    }
}