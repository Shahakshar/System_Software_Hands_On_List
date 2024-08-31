// Akshar Shah
// MT2024014
/*
27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execlei
d. execv
e. execvp
*/

#include<stdio.h>
#include<unistd.h>

int main() {
	printf("executing ls -Rl via execvp.\n");
	char *args[] = {"ls", "-Rl", NULL};
	execvp("ls", args);
	perror("execvp error");
	return 1;
}
