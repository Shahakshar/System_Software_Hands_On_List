// Akshar Shah
// MT2024014

/*
Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
*/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main() {

	int f1 = creat("a1.txt", 0766);
	int f2 = creat("a2.txt", 0766);
	int f3 = creat("a3.txt", 0766);
	int f4 = creat("a4.txt", 0766);
	int f5 = creat("a5.txt", 0766);

	while (1) {
		printf("akshar");
	}

	return 0;
}
