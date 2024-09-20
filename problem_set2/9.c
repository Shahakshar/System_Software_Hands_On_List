/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24

==================================================
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handler(int sig) {
    printf("Caught SIGINT (Ctrl+C)\n");
}

int main(void) {
    signal(SIGINT, handler);
    printf("Catching SIGINT\n");
    sleep(10);
    printf("No SIGINT within 10 seconds\n");

    signal(SIGINT, SIG_IGN);
    printf("Ignoring SIGINT\n");
    sleep(10);
    printf("No SIGINT within 10 seconds\n");

    signal(SIGINT, SIG_DFL);
    printf("Default action for SIGINT\n");
    sleep(10);
    printf("No SIGINT within 10 seconds\n");

    return 0;
}
