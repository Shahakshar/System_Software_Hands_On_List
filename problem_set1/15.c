// Akshar Shah
// MT2024014
/*
Write a program to display the environmental variable of the user (use environ).
*/
#include<stdio.h>
#include<unistd.h>
extern char **environ;

void main() {
	printf("%s\n", *environ);
	environ += 36;
	printf("%s\n", *environ);
	int count = 0;
	while (environ[count] != NULL) {
		count++;
	}
	printf("number of envirnoment variable: %d\n", count);
}
