/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signa use sigaction system call.

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("SIGINT ignored...\n");
}

int main() {
    struct sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    printf("Ignoring SIGINT for 5 seconds. Try pressing Ctrl+C...\n");
    sleep(5);

    printf("Resetting SIGINT to default action.\n");
    sa.sa_handler = SIG_DFL; 
    sigaction(SIGINT, &sa, NULL);

    sleep(5);
    printf("Program ends, now Ctrl+C works as usual.\n");

    return 0;
}

