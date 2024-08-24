// Akshar Shah
// MT2024014

/*
Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or 
not.
a. use dup
b. use dup2
c. use fcntl
*/

#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>

int main(int arg, char *args[]) {

	int file_d=open(args[1],O_WRONLY|O_APPEND|O_CREAT,S_IRWXU);
	printf("initial fd:%d\n", file_d);
	int a1=dup(file_d);
	printf("dup() calling:%d\n",a1);
	int a2=dup2(file_d,10);
	printf("Hi, USER written using dup2() file descriptor: %d\n",a2);
	int a3 = fcntl(file_d, F_DUPFD, 5);
	printf("Hi, USER written using fcntl() file descriptor:%d\n",a3);
	close(file_d);
	close(a1);
	close(a2);
	close(a3);
	return 0;

}
