// Akshar Shah
// MT2024014
/*
Write a program to get scheduling policy and modify the scheduling policy 
(SCHED_FIFO, SCHED_RR).
Date: 31/08/24
*/

#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

void policies(int policy) {
	switch(policy) {
		case SCHED_OTHER:
			printf("policy is : SCHED_OTHER\n");
			break;
		case SCHED_FIFO:
			printf("policy is : SCHED_FIFO\n");
			break;
		case SCHED_RR:
			printf("policy is : SCHED_RR\n");
			break;
		default:
			printf("policy not define\n");
	}
}

int main() {
	pid_t pid;
	int policy;
	struct sched_param param;

	pid = 0;

	policy = sched_getscheduler(pid);
	if(policy == -1) {
		perror("Error in policy");
		return 1;
	}
	policies(policy);

	param.sched_priority = 10;
	if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
		perror("Error in FIFO policy\n");
	       	return 1;
	}
	printf("Scheduling policy changed to SCHED_FIFO %d\n", param.sched_priority);
	policy = sched_getscheduler(pid);
	if (policy == -1) {
		perror("Error getting new Scheduling policy");
		return 1;
	}

	policies(policy);
	return 0;
}
