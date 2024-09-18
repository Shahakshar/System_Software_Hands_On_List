/*
========================================================
Author: Akshar Shah
Roll No: MT2024014
Date- 19/09/2024


========================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
	long arg_max = sysconf(_SC_ARG_MAX);

	if (arg_max == -1) {
		printf("Error while getting ARG_MAX\n");
	} else {
		printf("The maximum length of argument of exec family:%ld\n", arg_max);
	}
	return 0;
}
