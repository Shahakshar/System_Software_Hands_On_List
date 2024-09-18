/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 19/09/2024


==================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
	long max_open_files = sysconf(_SC_OPEN_MAX);

	if (max_open_files == -1) {
		printf("Error: While getting Maximum number of files\n");
	} else {
		printf("Maximum no. of open files is: %ld\n", max_open_files);
	}
	return 0;
}
