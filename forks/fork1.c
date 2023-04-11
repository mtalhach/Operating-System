#include<stdio.h>
#include<unistd.h>
int main(){
	int newly_created;
	newly_created=fork();

if(newly_created==0){
	
	printf("Child PID: %d\n",newly_created);	
	printf("My parent id is: %d\n",getpid());
}
else if(newly_created==-1){
	printf("error");
}
else{
	printf("My Child id is: %d\n",newly_created);	
	printf("I am parent having id: %d\n",getpid());
}
return 0;
}
