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

void pop(int fileDescriptor, Circular *ptr, int writing);

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
    fileDescriptor = open("clipboard.txt", O_WRONLY | O_TRUNC);

    int size = shmSize(sharedMemory);

    Circular *ptr = (Circular *) shmMap(sharedMemory, size);

    ptr->beg = 0;

    pop(fileDescriptor, ptr, writing);

    semClose(semaphoreCons);
    semClose(semaphoreProd);
    shmClose(ptr, sharedMemory, size);

    return 0;
}

void pop(int fileDescriptor, Circular *ptr, int writing) {
    while (writing > 0) {
        semP(semaphoreCons);
        
        writing = write(fileDescriptor, ptr->buf[ptr->beg], COPY_SIZE);
        if (writing == -1) {
            perror("Error while reading files");
            exit(EXIT_FAILURE);
        }
        if (strcmp(ptr->buf[ptr->beg], "\0") == 0) {
            break;
        }
        printf("Consumer: %s\n", ptr->buf[ptr->beg]);
        printf("\n");

        // Cyclicity of the buffer
        ptr->beg++;
        if (ptr->beg == SIZE) {
            ptr->beg = 0;
        }

        if(strcmp(ptr->buf[ptr->beg], "\0") == 0) break;

        semV(semaphoreProd);
    }
}