# Message queues

Kraków 1 June 2021

---

## Task instructions

### Task 1. Static library

As with semaphores and shared memory, create your own library (dynamic and static) containing functions for handling POSIX message queues.
Implement the following functions:

```c
// Creates the message queue named name and returns the descriptor to it.
int msgCreate(const char *name);

// Opens the message queue named name and returns the descriptor to it.
int msgOpen(const char *name);

// Closes access to the queue from msgid.
void msgClose(const char *name);

// Removes the message queue named name.
void msgRm(const char *name);

// Sends the message pointed to by msg to the queue with the identifier msgid.

// Create your own message data type.
void msgSend(int msgid, komunikat *msg);

// Receives a message from the msgid queue and writes it to msg.
void msgRecv(int msgid, komunikat *msg);

// Prints all message queue information obtained with mq_getattr ().
void msgInfo(int msgid);
```

---

### Task 2. Server and Client

The client's process sends a request to the server process to perform an arithmetic operation on two numbers of the form: a ⊙ b, where a and b are numbers and the operator ⊙ ∈ {+, -, *, /}, e.g. 2 + 3. The server performs the appropriate action and sends back result to the client. The client receives this result and writes it to the screen. Using the mechanism of POSIX message queues, implement the above client-server task with the ability to handle many clients simultaneously by the server.
