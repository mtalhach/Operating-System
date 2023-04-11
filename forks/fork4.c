#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
void forkexample(){	
	int x=1;
	//child process because return value zero
	if(fork()==0){
		printf("child has x: %d\n",++x);
	}
	//parent process because return non zero value
	else{
	//sleep(1);
		printf("parent has x: %d\n",--x);
	}
}

int main(){
	forkexample();
	return 0;
}
