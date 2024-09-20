/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 19/09/2024
5. Write a program to print the system limitation of
	e. size of a page.

==================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
	long page_size = sysconf(_SC_PAGESIZE);

	if (page_size == -1) {
		printf("Error: While getting Maximum number of pages\n");
	} else {
		printf("Maximum no. of open files is: %ld\n", page_size);
	}
	return 0;
}
