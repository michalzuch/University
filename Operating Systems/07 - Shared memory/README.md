# Shared memory

Kraków 25 May 2021

---

## Task instructions

### Task 1. Dynamic library

Write the `libshmem.so` dynamic (shared) library that implements the following functions for supporting POSIX shared memory:

```c
// The function creates shared memory named name and size size.
// The function returns the shared memory object descriptor.
int shmCreate(const char* name, int size);

// The function opens a shared memory object and returns its descriptor.
int shmOpen(const char* name);

// Deletes the shared memory object named name.
void shmRm(const char* name);

// Maps a shared memory object with fd and size size to the process address space.
// The function returns the address of the beginning of the mapped area of shared memory.
void* shmMap(int fd, int size);

// Removes the mapping of a shared memory object and closes its associated descriptor.
void shmClose(void *ptr, int fd, int size);

// Returns the shared memory size specified by fd.
// Please use the fstat system call.
int shmSize(int fd);

// Prints information about shared memory: access rights, size, owner, etc.
void shmInfo(int fd);
```

---

## Task 2. Shmuse

Write a program that manages shared memory using the `libshmem.so` library.

---

## Task 3. Producer and Consumer

Using shared memory and POSIX semaphores, implement the "Producer and Consumer" problem for an N-element cyclic buffer placed in shared memory, where the buffer element is a certain portion of bytes. To demonstrate that there has been no loss or multiplication of the goods, let the Producer take the "raw material" (e.g. portions of bytes or int numbers) from the text file storage.txt and insert it as goods into the buffer, and let the Consumer place the downloaded from item buffer in clipboard.txt.
