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
#include<unistd.h>

int main() {
	printf("Executing ls -Rl via execlp\n");
	execlp("ls", "ls", "-Rl", NULL);
	perror("execlp error");
	return 1;
}
