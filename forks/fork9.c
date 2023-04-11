#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

#define MAX_COUNT 3

void childProcess(void);
void parentProcess(void);
 
void main(void){
	pid_t pid;
	pid=fork();	
	if(pid==0){
		childProcess();	
	}
	else{
		parentProcess();
	}
}
void childProcess(){
	int i;
	for(i=1;i<=MAX_COUNT;i++){
		printf("This line is from child,value: %d\n",i);
		printf("  ***Child process is done  ***\n");
	}
}
void parentProcess(){
	int i;
	for(i=1;i<=MAX_COUNT;i++){
		printf("This line is from parent,value: %d\n",i);
		printf("  ***parent process is done  ***\n");
	}
}

