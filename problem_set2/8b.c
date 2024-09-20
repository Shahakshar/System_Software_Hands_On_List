/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24

==================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signum) {
    switch (signum) {
        case SIGINT:
            printf("Caught SIGINT: Program interrupted by user (Ctrl+c)\n");
            break;
    }
}

int main() {
	signal(SIGINT, signal_handler);
	while (1) {
        	printf("Running... Press Ctrl+C to stop.\n");
        	sleep(1);
    	}

    	return 0;
}

