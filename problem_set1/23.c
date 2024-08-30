// Akshar Shah
// MT2024014
/*
Write a program to create a Zombie state of the running program
*/
// Date: 26/08/24

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
	int fd;
	fd = fork();
	if (fd == 0) {
		sleep(2);
		printf("i am in child process pid = %d\n", getpid());
		printf("parent id %d\n", getppid());
	}
	else {
		sleep(5);
		printf("i am in parent pid = %d\n", getpid());
		printf("child cid = %d\n", fd);
	}
	return 0;
}
