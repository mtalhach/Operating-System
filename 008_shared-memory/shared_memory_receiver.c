#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(int argc, char const *argv[])
{
    key_t key = ftok("abc",123);
    int shmid = shmget(key,1024, 0666 | IPC_CREAT); //middle is size
    char* memory = (char*) shmat(shmid, (void* ) 0, 0); //middle 0 represents any area of memory to be attached with
    
    printf("%s",memory);

    shmdt(memory);

    shmctl(shmid, IPC_RMID, NULL); //To remove from memory
    return 0;
}
