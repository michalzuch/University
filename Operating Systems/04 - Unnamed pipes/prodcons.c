#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/param.h>
#define COPY_SIZE 5

// to compare files: diff -s

// FUNCTIONS IMPLEMENTATIONS
void producer (int, const char*);
void consumer (int, const char*);
void arguments_error (int);

// MAIN BODY
int main(int argc, const char* argv[]) {

    // Check to see if the correct number of arguments is given - 3.
    arguments_error(argc);
    
    // A two-element int array as a file descriptor
    // file_descriptor[0] - read
    // file_descriptor[1] - write
    int file_descriptor[2];

    // Create an unnamed pipe
    if (pipe(file_descriptor) == -1) {
        perror("pipe() error");
        exit(EXIT_FAILURE);
    }

    switch (fork()) {
        case -1:    // ERROR
            printf("fork() error\n");
            exit(EXIT_FAILURE);
        case 0:     // PRODUCER
            close(file_descriptor[0]);
            producer(file_descriptor[1], argv[1]);
            close(file_descriptor[1]);
            break;
        default:    // CONSUMER
            usleep(rand() % 100);
            close(file_descriptor[1]);
            consumer(file_descriptor[0], argv[2]);
            close(file_descriptor[0]);
            break;
    }
    wait(NULL);
}

// FUNCTIONS DECLARATIONS
void arguments_error(int arguments) {
    if (arguments != 3) {
        printf("Incorrect use of the program prodkons");
        printf("Pattern: ./prodkons.x <storage> <clipboard>\n");
        exit(EXIT_FAILURE);
    }
}

void producer(int file_descriptor, const char* file) {

    int fd_storage = open(file, O_RDONLY);
    if (fd_storage == -1) {
        printf("Error while opening file %s\n", file);
        exit(EXIT_FAILURE);
    }

    void *buffer = malloc(COPY_SIZE);

    int reading_from_file;
    int writing_to_stream;

    while ( (reading_from_file = read(fd_storage, buffer, COPY_SIZE)) > 0 ) {
        printf("\nWriting into pipe:\n");
        writing_to_stream = write(file_descriptor, buffer, reading_from_file);
        if ((write(STDOUT_FILENO, buffer, writing_to_stream)) == -1) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    }
    close(fd_storage);
    free(buffer);
}

void consumer(int file_descriptor, const char* file) {
    int fd_clipboard = open(file, O_WRONLY);
    if (fd_clipboard == -1) {
        printf("Error while opening file %s\n", file);
        exit(EXIT_FAILURE);
    }

    void *buffer = malloc(COPY_SIZE);

    int reading_from_stream;
    int writing_to_file;

    while ( (reading_from_stream = read(file_descriptor, buffer, COPY_SIZE)) > 0 ) {
        printf("\nWriting from pipe:\n");
        writing_to_file = write(fd_clipboard, buffer, reading_from_stream);
        if ((write(STDOUT_FILENO, buffer, writing_to_file)) == -1) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    }
    close(fd_clipboard);
    free(buffer);
}