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

    key = ftok("abc",123); //Generates Unique key
    msgid = msgget(key, 0666 | IPC_CREAT); //Allocates memeory for the message with key as it's identifiier

    msg.type = 1; //set the type of message
    strcpy(msg.mess, "HELLO"); //add the message
    printf("Writing Data");

    msgsnd(msgid, &msg,sizeof(message),0); //Send data, the last argument specifies behavior in case queue is full, 0 returns, IPC_NOWAIT will suspend it's execution
    
    return 0;
}
