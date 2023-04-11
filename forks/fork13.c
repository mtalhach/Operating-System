//zombie process 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	pid_t p;
	p=fork();

if(p==0){  //child part

	printf("I am child having id: %d\n",getpid());	
	printf("My parent id is: %d\n",getppid());
}

else{  //parent part
	
	wait(NULL);
	sleep(5);
	printf("I am parent having id: %d\n",getpid());
	printf("My Child id is: %d\n",p);
}
return 0;
}
