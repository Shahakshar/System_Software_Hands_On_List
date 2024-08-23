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
	int fd=open(args[1],O_WRONLY|O_APPEND|O_CREAT,S_IRWXU);
	int d1=dup(fd);
	write(fd,"Hi, written using original file descriptor\n",45);
	write(d1,"Hi, USER Written using dup() file descriptor\n",47);
	int d2=dup2(fd,10);
	write(d2,"Hi, USER written using dup2() file descriptor\n",48);
	int d3 = fcntl(fd, F_DUPFD, 5);
	write(d3,"Hi, USER written using fcntl() file descriptor\n",49);
	close(fd);
	close(d1);
	close(d2);
	close(d3);
	return 0;
}
