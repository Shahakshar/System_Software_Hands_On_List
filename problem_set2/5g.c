/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 19/09/2024
5. Write a program to print the system limitation of
	g. number of currently available pages in the physical memory.

==================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
	long available_pages = sysconf(_SC_AVPHYS_PAGES);

	if (available_pages == -1) {
		printf("Error: While getting Maximum number of available physical pages\n");
	} else {
		printf("Maximum no. of open files is: %ld\n", available_pages);
	}
	return 0;
}
