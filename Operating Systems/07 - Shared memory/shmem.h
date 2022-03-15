#ifndef SHMEM_H
#define SHMEM_H

const char name[] = "/shared_memory";
const int size;

int shmCreate(const char* name, int size);
int shmOpen(const char* name);
void shmRm(const char* name);
void* shmMap(int fd, int size);
void shmClose(void *ptr, int fd, int size);
int shmSize(int fd);
void shmInfo(int fd);

#endif /* SHMEM_H */
