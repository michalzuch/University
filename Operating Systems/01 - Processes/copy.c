#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char* argv[]) {

    /* Check to see if the correct number of arguments is given - 3.
    1 - program name (copy.x)
    2 - name of the file to be copied
    3 - name of the target file to which the content is to be copied */
    if (argc != 3) {
        printf("Incorrect use of the program %s.\n", argv[0]);
        printf("Pattern: %s <file_to_be_copied> <destination_file>\n", argv[0]);
        exit(-1);
    }
    /* Opening the file for reading and checking if it was opened correctly.
    file_read is the read file descriptor. */
    int file_read = open(argv[1], O_RDONLY);
    if (file_read == -1) {
        perror("Error while opening file to copy");
        exit(-1);
    }

    /*  Creating a buffer of 1024 bytes and checking if the memory was allocated correctly */
    void *buffer = malloc(1024);
    if (buffer == NULL){
        perror("Alocating memory for buffer failed");
        exit(-1);
    }

    /*  Open a file for writing (with permissions to open and edit by the user) and check if the opening was successful.
    file_write is the file descriptor to write. */
    int file_write = open(argv[2], O_WRONLY | O_CREAT, S_IRWXU);
    if (file_write == -1) {
        perror("Error while opening file for writing");
        exit(-1);
    }
    /*  Integer type variables that store information about the number of read and written bytes. */
    int reading;
    int writing;

    /*  A loop that executes as long as any data from the descriptor is read. */
    while ((reading = read(file_read, buffer, 1024)) > 0) {
        if (reading == -1) {
            perror("Reading file failed");
        }
        /* Writing data from the read file to the target file */
        writing = write(file_write, buffer, reading);
        if (writing == -1) {
            perror("Writing files fialed");
        }
    }

    /*  Exiting the program - closing files and freeing the buffer. */
    close(file_read);
    close(file_write);
    free(buffer);
}