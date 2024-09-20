/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24

==================================================
*/

#include <stdio.h>
#include <signal.h>

void signal_handler(int signum) {
    switch (signum) {
        case SIGFPE:
            printf("Caught SIGFPE: Floating-point exception (e.g., division by zero)\n");
            break;
    }
}

int main() {
    signal(SIGFPE, signal_handler);

    int a = 1 / 0; 

    return 0;
}

