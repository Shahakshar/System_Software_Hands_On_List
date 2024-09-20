/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24

==================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    switch (signum) {
        case SIGALRM:
            printf("Caught SIGALRM: Alarm signal received\n");
            break;
    }
}

int main() {
    signal(SIGALRM, signal_handler);

    alarm(3); 
    printf("Waiting for alarm signal...\n");
    pause(); 

    return 0;
}

