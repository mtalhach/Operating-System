#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void){
	pid_t childpid;
	printf("I am parent, my PID is %d, and I am going to call fork\n",getpid());
	childpid=fork();
	
	if(childpid==0){		/*child code*/
		printf("I am child my PID is %d and my PPID is %d\n",getpid(),getppid());
		execl("/bin/ls","vi",NULL);
		perror("child failed to exec is");
		return 1;
	}
	if(childpid !=wait(NULL)){       /*parent code*/
		perror("Parent failed to wait due to signal or error");
		return 1;
	}
	printf("I am so sad, my child just died\n");
	return 0;
}
