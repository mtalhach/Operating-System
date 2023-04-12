/*
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	printf("Before\n");
	execl("/bin/ls","ls","-l",NULL);
	printf("After\n");
return 0;
}
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
	pid_t p;
	p=fork();

if(p==0){  //child part
	//execl("/bin/ps","ps",NULL);
	printf("I am child having id: %d\n",getpid());	
	execl("/bin/ps","ps",NULL);
}

else{  //parent part
	wait(NULL);
	printf("I am parent having id: %d\n",getpid());
}
return 0;
}
