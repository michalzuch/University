#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 8192
#define SERVER_NAME "/server"

typedef struct message {
    int pid;
    int a;
    int o;
    int b;
    int result;
} message;

unsigned int priority = 1;

// Creates a message queue named name and returns a descriptor to it.
int msgCreate(const char *name) {
    mqd_t mqdes = mq_open(name, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR, NULL);
    if (mqdes == (mqd_t)-1) {
        perror("Error while opening queue");
        exit(EXIT_FAILURE);
    }
    printf("Queue %s created.\n", name);

    return mqdes;
}

// Opens the message queue named name and returns the descriptor to it.
int msgOpen(const char *name) {
    mqd_t mqdes = mq_open(name, O_RDWR);
    if (mqdes == (mqd_t)-1) {
        perror("Error while opening queue");
        exit(EXIT_FAILURE);
    }
    printf("Queue %s opened.\n", name);

    return mqdes;
}

// Closes access to the queue with the msgid descriptor.
void msgClose(mqd_t mqdes){
    if (mq_close(mqdes) == -1) {
        perror("Erorr while closing queue");
        exit(EXIT_FAILURE);
    }
    printf("Queue %d closed.\n", mqdes);
}

// Deletes the message queue named name.
void msgRm(const char *name) {
    if (mq_unlink(name) == -1) {
        perror("Error while removing queue");
        exit(EXIT_FAILURE);
    }
    printf("Queue %s removed.\n", name);
}

// Sends the message pointed to by msg to the queue with id msgid.
void msgSend(int msgid, message *msg) {
    if (mq_send(msgid,(const char *)msg, sizeof(message) + 1, priority) == -1) {
        perror("Error while sending to queue");
        exit(EXIT_FAILURE);
    }
}

// Receives a message from the msgid queue and writes it to msg.
void msgRecv(int msgid, message *msg) {
    if (mq_receive(msgid,(char *)msg, BUFSIZE, NULL) == -1) {
        perror("Error while receiving from queue");
        exit(EXIT_FAILURE);
    }
}

// Prints all message queue information obtained with mq_getattr ().
void msgInfo(int msgid) {
    struct mq_attr attr;

    if(mq_getattr(msgid, &attr) == -1) {
        perror("Error while gathering information about queue");
        exit(EXIT_FAILURE);
    }

    printf(
        "mq_flags   :%10lX\n"
        "mq_maxmsg  :%10ld\n"
        "mq_msgsize :%10ld\n"
        "mq_curmsg  :%10ld\n",
        attr.mq_flags,
        attr.mq_maxmsg,
        attr.mq_msgsize,
        attr.mq_curmsgs
    );
}