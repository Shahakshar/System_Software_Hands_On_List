/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
8. Write a separate program using signal system call to catch the following signals.
	e. SIGALRM(use setitimer system call)

==================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void signal_handler(int signum) {
    switch (signum) {
        case SIGALRM:
            printf("Caught SIGALRM: Alarm signal using setitimer\n");
            break;
    }
}

int main() {
    signal(SIGALRM, signal_handler);  // Catch SIGALRM

    struct itimerval timer;
    timer.it_value.tv_sec = 2;    // First timer will go off in 2 seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; // No repeating interval
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);  // Set the timer

    // Wait for signal
    printf("Waiting for setitimer alarm signal...\n");
    pause();  // Pause the program until a signal is received

    return 0;
}

