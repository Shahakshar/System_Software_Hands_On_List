// Akshar Shah
// MT2024014
/*
Write a program to get maximum and minimum real time priority.
Date: 31/08/24
*/

#include<stdio.h>
#include<sched.h>
#include<errno.h>

int main() {
	int max_priority, min_priority;

	max_priority = sched_get_priority_max(SCHED_FIFO);
	if (max_priority == -1) {
		perror("Error max_priority");
		return 1;
	}

	min_priority = sched_get_priority_min(SCHED_FIFO);
	if (min_priority == -1) {
		perror("Error getting minimum priority");
		return 1;
	}
	printf("Maximum Real-Time Priority: %d\n", max_priority);
	printf("Minimum Real-Time Priority: %d\n", min_priority);
	return 0;
}
