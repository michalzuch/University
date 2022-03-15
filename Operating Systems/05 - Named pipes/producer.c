#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define COPY_SIZE 5

int main(int argc, const char* argv[]) {
    
    // File descriptor 'storage'
    int fd_storage = open(argv[1], O_RDONLY);
    if (fd_storage == -1) {
        printf("Error while opening file '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // The pipe descriptor
    int stream = open(argv[2], O_WRONLY);
    if (stream == -1) {
        printf("Error while opening pipe '%s'\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    void *buffer = malloc(COPY_SIZE);
    int reading_from_file;
    int writing_to_stream;

    while ( (reading_from_file = read(fd_storage, buffer, COPY_SIZE)) > 0 ) {
        printf("\nAmount of bytes read: %d\n", reading_from_file);
        printf("\nWriting into the pipe:\n");
        writing_to_stream = write(stream, buffer, reading_from_file);
        // Printing data on screen
        if ((write(STDOUT_FILENO, buffer, writing_to_stream)) == -1) {
            perror("Error while writing to terminal\n");
            exit(EXIT_FAILURE);
        }
        printf("\n");
    }
    close(fd_storage);
    free(buffer);
}