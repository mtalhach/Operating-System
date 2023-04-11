#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){	
	int i;
	printf("Process PID: %6d\tPPID: %6d\n\n",getpid(),getppid());
	for(i=0;i<2;i++){
		if(fork()==0){
		printf("Process PID: %6d\tPPID: %6d\n",getpid(),getppid());
		}		
		//wait(NULL);
	}
	return 0;
}
