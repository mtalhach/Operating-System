#include<stdio.h>
#include<unistd.h>
int main(){
	int p;
	p=fork();
	printf("Hello world\n");
	printf("value of p is %d\n",p);
return 0;
}
