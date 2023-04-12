#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
void forkexample(){
	
	//child process because return value zero
	if(fork()==0){
		printf("Hello from child\n");
	}
	//parent process because return non zero value
	else{
	//sleep(1);
		printf("Hello from parent\n");
	}
}

int main(){
	forkexample();
	return 0;
}
