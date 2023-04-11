#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
/*make two process which run same program after this instruction*/
	fork();
	printf("Hello world\n");
return 0;
}
