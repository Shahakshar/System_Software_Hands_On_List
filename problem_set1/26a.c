// Akshar Shah
// MT2024014
/*
26. Write a program to execute an executable program.
a. use some executable program
DATE: 31/08/24
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int arg, char* argv[]) {
	execv(argv[1], &argv[1]);
	return 0;
}
