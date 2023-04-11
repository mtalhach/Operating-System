#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	int p,q;
	p=fork();

if(p==0){  //child part

	//sleep(3);
	printf("I am child having id: %d\n",getpid());	
	printf("My parent id is: %d\n",getppid());
}

else{  //parent part
	
	q=fork();
	if(q==0){  //child 2
		printf("I am Second Child having PID: %d\n",getpid());
		printf("Second Child's Parent PID: %d\n",getppid());
	}
	else{
		//waitpid(p,NULL,0);
		//wait(NULL);	
		printf("I am parent having id: %d\n",getpid());
		printf("My First Child PID is: %d\n",p);
		printf("My Second Child PID is: %d\n",q);
	}
}
return 0;
}
