/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal use sigaction system call.

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("SIGINT signal ignored. Press Ctrl+C again after reset.\n");
}

int main() {
    struct sigaction sa;

    sa.sa_handler = sigint_handler;  
    sigemptyset(&sa.sa_mask);       
    sa.sa_flags = 0;                
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error setting signal handler for SIGINT");
        exit(EXIT_FAILURE);
    }
    printf("SIGINT ignore evenif ctrl+c u press.(nothing is happen)");

    sa.sa_handler = SIG_IGN;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
	    perror("Error while set SIGINT to ignore");
	    exit(EXIT_FAILURE);
    }
    printf("SIGINT signal behavior reset to default. Press Ctrl+C to terminate the program.\n");
    sleep(10);

    sa.sa_handler = SIG_DFL; 
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error resetting SIGINT to default");
        exit(EXIT_FAILURE);
    }
    sleep(10);
    printf("Program finished execution.\n");
    return 0;
}

