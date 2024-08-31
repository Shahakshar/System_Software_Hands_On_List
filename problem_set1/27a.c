// Akshar Shah
// MT2024014
/*
27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date: 31/08/24
*/

#include<stdio.h>
#include <unistd.h>

int main() {
	printf("Executable ls -Rl via execl.\n");
	execl("/bin/ls", "ls", "-Rl", NULL);
	perror("execl mai aa rahi hai error");
	return 1;
}
