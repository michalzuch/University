#define SERVER_NAME "/server"
#ifndef MSG_H
#define MSG_H

#include <mqueue.h>
typedef struct message {
    int pid;
    int a;
    int o;
    int b;
    int result;
} message;

int msgCreate(const char *name);
int msgOpen(const char *name);
void msgClose(mqd_t mqdes);
void msgRm(const char *name);
void msgSend(int msgid, message *msg);
void msgRecv(int msgid, message *msg);
void msgInfo(int msgid);

#endif /* MSG_H */
