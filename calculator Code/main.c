#include<stdio.h>
#include <stdbool.h>

#include "myheader.h"
int main()
{
int n1,n2;
int sum,multiply,divide,substract;
int choice;
while(true){
printf("\nEnter Your First Number: ");
scanf("%d",&n1);
printf("Enter Your Second Number: ");
scanf("%d",&n2);

printf("\nEnter Your Choice\nPress 1 for Add\nPress 2 for Multiply\nPress 3 for Substract\nPress 4 for Divide\n");
scanf("%d",&choice);

switch(choice){
	case 1:
	sum=addition(n1,n2);
	printf("\nThe Addition of two numbers are: %d",sum);
	break;
	case 2:
	multiply=multiplication(n1,n2);
	printf("\nThe Multiplication of two numbers are: %d",multiply);
	break;
	case 3:
	substract=Substraction(n1,n2);
	printf("\nThe substraction of two numbers are: %d",substract);
	break;
	case 4:
	divide=division(n1,n2);
	printf("\nThe division of two numbers are: %d",divide);
	break;
	default:
	printf("Plz Enter The Right Command");
}
}
}
