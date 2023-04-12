#include <unistd.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
typedef struct msg {
    long type;
    char mess[100];
} message;
int main(int argc, char const *argv[])
{
    message msg;
    key_t key;
    int msgid;

    key = ftok("abc",123);

    msgid = msgget(key, 0666 | IPC_CREAT);

    printf("Reading Data");

    msgrcv(msgid, &msg,sizeof(message),1,IPC_NOWAIT); //HERE 2nd last is message type specified in sender, and last argument clg IPC_NOWAIT specifies in case message doesn't exist in queue.
    
    printf("The message is = %s",msg.mess);

    msgctl(msgid,IPC_RMID,NULL); //Removing from the messsage queue.
    return 0;
}
