/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 19/09/24



==================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
	long ticks_per_sec = sysconf(_SC_CLK_TCK);

	if (ticks_per_sec == -1) {
		printf("Error: while getting number of click ticks per second\n");
	} else {
		printf("Number of clock ticks per second is: %ld\n", ticks_per_sec);
	}
	return 0;
}
