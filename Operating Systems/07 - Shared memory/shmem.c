#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char name[] = "/shared_memory";
const int size;

// The function creates shared memory named name and size size.
// The function returns the shared memory object descriptor.
int shmCreate(const char* name, int size) {

    // Create zero-size shared memory
    printf("Creating shared memory...\n");
    int fd = shm_open(name, O_RDWR | O_CREAT | O_EXCL, 0660);
    if (fd == -1) {
        printf("Error while creating shared memory");
        exit(EXIT_FAILURE);
    }

    printf("Shared memory created.\n");

    // Shared memory size setting
    if (ftruncate(fd, size) == -1) {
        perror("Error while setting memory's size");
        exit(EXIT_FAILURE);
    }

    return fd;
}

// The function opens a shared memory object and returns its descriptor.
int shmOpen(const char* name) {
    
    printf("Opening shared memory...\n");

    int fd = shm_open(name, O_RDWR, 000);
    if (fd == -1) {
        printf("Error while opening sharer memory");
        exit(EXIT_FAILURE);
    }

    printf("Shared memory opened.\n");

    return fd;
}

// Removes the shared memory object named name.
void shmRm(const char* name) {
    printf("Removing shared memory...\n");

    if (shm_unlink(name) == -1) {
        printf("Error while removing shared memory\n");
        exit(EXIT_FAILURE);
    }
    printf("Shared memory removed.\n");
}

// Maps a shared memory object with file descriptor 'fd' and 'size' size to the process address space.
// The function returns the address of the beginning of the mapped area of shared memory.
void* shmMap(int fd, int size) {
    char *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (*ptr == -1) {
        perror("Error while mapping memory");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

// Removes the mapping of a shared memory object and closes its associated descriptor.
void shmClose(void *ptr, int fd, int size) {
    //Usunięcie odwzorowania
    if (munmap(ptr, size) == -1) {
        perror("Removing mapping failed");
        exit(EXIT_FAILURE);
    }

    // Closing the descriptor
    if (close(fd) == -1) {
        perror("Error while closing file descriptor");
        exit(EXIT_FAILURE);
    }
}

// Returns the shared memory size specified by fd.
int shmSize(int fd) {
    struct stat status;

    if (fstat(fd, &status) == -1) {
        perror("Error while getting file staus");
        exit(EXIT_FAILURE);
    }

    return status.st_size;
}

// Prints information about shared memory: access rights, size, owner, etc.
void shmInfo(int fd) {
    struct stat status;

    if (fstat(fd, &status) == -1) {
        perror("Error while getting file staus");
        exit(EXIT_FAILURE);
    }

    printf(
        "Resident of device: %ld\n"
        "Inode number: %ld\n"
        "File type and mode: %d\n"
        "Number of hard links: %ld\n"
        "User ID: %d\n"
        "Group ID: %d\n"
        "Device ID: %ld\n"
        "Total size: %ld byes\n"
        "Block size for filesystem I/O: %ld\n"
        "Number of 512B blocks allocated: %ld\n"
        "File last accessed: %ld\n"
        "File last modified: %ld\n"
        "File last changed: %ld\n",
        status.st_dev,
        status.st_ino,
        status.st_mode,
        status.st_nlink,
        status.st_uid,
        status.st_gid,
        status.st_rdev,
        status.st_size,
        status.st_blksize,
        status.st_blocks,
        status.st_atime,
        status.st_mtime,
        status.st_ctime
        );
}