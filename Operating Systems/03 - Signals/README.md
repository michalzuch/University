# Signals

Kraków 27 April 2021

---

## Task instructions

### Task 1. Handling

Write a signal handling program that can perform the default operation for the signal, ignore the signal and intercept and handle the signal itself (write the signal number).

---

### Task 2. Send

Run `handling.x` once via the `execl()` function in a child process (switch + fork + execl) and send signals to it via the `kill()` system call from the parent process.

---

### Task 3. Group

In the parent process, create a child process and make it the leader of a new process group, and then run several child processes in it to execute the signal handler. Send signals from the first parent process to an entire group of child processes after checking for its existence. Obtain the id of this process group using `getpgid()`. Let the process group leader ignore signals and finally wait for all of its child processes to terminate and print their termination status as returned by `wait()`.
