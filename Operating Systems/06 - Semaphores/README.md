# Semaphores

Kraków 11 May 2021

---

## Task instructions

### Task 1. Sem library

Create your own static sem library with implementations of the following functions to support a generic POSIX named semaphore:

```c
 // Creates a semaphore with initial value val.
semid semCreate(const char *name, int val);

// Removes a semaphore.
void semRemove(const char *name);

// Accesses an existing semaphore.
semid semOpen(const char *name);

// Closes the semaphore on the given process.
void semClose(semid sem);

// Lower semaphore: decrease the value of the semaphore by 1 or wait.
void semP(semid sem);

// Raise the semaphore: Increase the value of the semaphore by 1 or resume the waiting process.
void semV(semid sem);

// Print information about the value of the semaphore, possibly, if the system allows such a possibility, also about the number of waiting processes.
void semInfo(semid sem);
```

---

### Task 2. Semuse

Write a program that performs actions on semaphore:

* Initialize the semaphore and prints information about it.
* Remove the semaphore.
* Lower the semaphore and print information about it.
* Raise a semaphore and prints information about it.
* Print information about a semaphore.

---

### Task 3. Prog & Multiplier

Implement a mutual exclusion task for processes using your own sem library using POSIX named semaphores.
