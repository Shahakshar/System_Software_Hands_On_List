/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date-19/09/24
5. Write a program to print the system limitation of
	b. maximum number of simultaneous process per user id.

==================================================
*/

#include<stdio.h>
#include<unistd.h>

int main() {
	long max_proc = sysconf(_SC_CHILD_MAX);

	if (max_proc == -1) {
		printf("ERROR while getting maximum number of process per user");
	} else {
		printf("Maximum number of process per user is: %ld\n", max_proc);
	}
	return 0;
}
