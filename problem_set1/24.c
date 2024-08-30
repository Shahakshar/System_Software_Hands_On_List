// Akshar Shah
// MT2024014
/*
Write a program to create an orphan process.
*/
// Date: 28/08/24

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
	int pid;
	pid = fork();
	if (pid == 0) {
		sleep(10);
		printf("i am in child process having pid=%d\n",getpid());
		printf("i am in child but printing prarent id=%d\n",getppid());
	} else {
		sleep(5);
		printf("i am in parent process having pid=%d\n",getpid());
		printf("i am in parent but child cid=%d\n",pid);
	}
	return 0;
}
