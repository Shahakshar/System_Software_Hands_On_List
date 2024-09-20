/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24

==================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void signal_handler(int signum) {
    switch (signum) {
        case SIGVTALRM:
            printf("Caught SIGVTALRM: Virtual timer alarm\n");
            break;
    }
}

int main() {
    signal(SIGVTALRM, signal_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 2;   
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL); 
    printf("Waiting for virtual timer alarm signal...\n");
    pause(); 

    return 0;
}

