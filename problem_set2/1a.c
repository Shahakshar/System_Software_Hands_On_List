/*
Author: Akshar Shah
Roll No: MT2024014
Date: 18/09/2024

1. Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second.

a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF

*/

// REAL_ITIME = user-mode(cpu+i/o) + kernal-mode time
// VIRTUAL_ITIME = user-mode(cpu) time do not include i/o
// PROF_ITIME = user-mode(cpu) + kernel-mode(cpu) time do not include i/o

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

void real_timer_handler(int signum) {
	printf("Real timer expired!\n");
}

int main() {
	struct itimerval timer;
	signal(SIGALRM, real_timer_handler);

	timer.it_value.tv_sec = 10;
	timer.it_value.tv_usec = 10;
	timer.it_interval.tv_sec = 10;
	timer.it_interval.tv_usec = 10;

	if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
		perror("ERROR setting timer");
		exit(1);
	}

	while (1) {}
	return 0;
}
