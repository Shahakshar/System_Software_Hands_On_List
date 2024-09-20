/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 19/09/2024
5. Write a program to print the system limitation of
	f. total number of pages in the physical memory.

==================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
	long total_pages = sysconf(_SC_PHYS_PAGES);

	if (total_pages == -1) {
		printf("Error: While getting Maximum number of physical pages\n");
	} else {
		printf("Maximum no. of open files is: %ld\n", total_pages);
	}
	return 0;
}
