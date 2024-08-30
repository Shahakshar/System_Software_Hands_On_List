// Akshar Shah
// MT2024014
/*
Write a program, call fork and print the parent and child process id.
*/
// Date: 26/08/24

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main() {
	printf("parent id = %d\n", getpid());
	int cid = fork();
	if (cid)
		printf("child id =%d\n", cid);
	return 0;
}
