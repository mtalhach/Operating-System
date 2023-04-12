#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	int newly_created;
	newly_created=fork();

if(newly_created==0){  //child part

	//sleep(3);
	printf("I am child having id: %d\n",getpid());	
	printf("My parent id is: %d\n",getppid());
}

else{  //parent part

	//wait(NULL);
	printf("My Child id is: %d\n",newly_created);	
	printf("I am parent having id: %d\n",getpid());
}
printf("Common\n");
return 0;
}
