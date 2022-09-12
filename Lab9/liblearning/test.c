
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include "MyMath.h"

int add(int, int);
int sub(int, int);
int div1(int, int);

int main(int argc, char* argv[])
{
	int a = 10, b = 5;
	printf("%d + %d = %d \n", a, b, add(a, b)); 
	printf("%d - %d = %d \n", a, b, sub(a, b)); 
	printf("%d / %d = %d \n", a, b, div1(a, b)); 
	return 0;
}