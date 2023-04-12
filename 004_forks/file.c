/*C program to get a process id and parent process id*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
int p_id,p_pid;
p_id=getpid();  /*process id*/
p_pid=getppid();  /*parent process id*/

printf("Process ID: %d\n",p_id);
printf("Parent Process ID: %d\n",p_pid);

printf("Process PID: %d \t Process PPID: %d\n",getpid(),getppid());
return 0;
}
