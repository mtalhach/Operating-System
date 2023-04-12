#include<stdio.h>
#include<unistd.h>
int main(){
	int p;
	printf("original process, pid: %d\n",getpid());
	
	p=fork();
	if(p==0){
		printf("Child ID: %d,Parent ID: %d\n",getpid(),getppid());
		//sleep(20);
	}
	else{
		printf("process id, PID: %d,parent id, PPID: %d\n",getpid(),getppid());
		//sleep(20);
	}
return 0;
}
