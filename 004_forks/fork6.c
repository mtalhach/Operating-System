#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	fork();
	printf("Hello\n");
	fork();
	printf("Hy\n");
	fork();
	printf("AOA\n");
return 0;
}
