# Thread synchronization

Kraków 8 June 2021

---

## Task instructions

### Task 1. Bakery algorithm

Implement the bakery algorithm using POSIX threads. Demonstrate the correctness of the program as in set 8.

---

### Task 2. Bakery algorithm with counter

Modify previous task adding counter. The program should run according to the following pseudocode:

```c
volatile int counter = 0 // Global counter

thread() { // Thread function

    for(i = 1, ..., 1000000) {
        lock()  // Entrance to the critical section
                // according to the bakery algorithm

        counter = counter + 1

        unlock() // Exit from the critical section
    }
}
```
