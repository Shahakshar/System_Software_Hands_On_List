/*
Author: Akshar Shah
Roll No: MT2024014
Date: 18/09/2024

1. Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second.

a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF

*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

void virtual_timer_handler(int signum) {
	printf("Virtual timer expired!\n");
}

int main() {
	struct itimerval timer;
	signal(SIGVTALRM, virtual_timer_handler);

	timer.it_value.tv_sec = 10;
	timer.it_value.tv_usec = 10;
	timer.it_interval.tv_sec = 10;
	timer.it_interval.tv_usec = 10;

	if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
		perror("ERROR setting timer");
		exit(1);
	}

	while (1) {}
	return 0;
}
