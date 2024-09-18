/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date-19/09/24

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
