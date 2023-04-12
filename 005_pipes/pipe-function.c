#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
int fd[2],n;
char buffer[100];
pid_t p;
pipe(fd);
p=fork();
if(p>0){//parent
	printf("passing value to child\n");
	write(fd[1],"Hello\n",6);
}
else{
	printf("Child recieved the data\n");
	n=read(fd[0],buffer,100);
	write(1,buffer,n);
}

}

