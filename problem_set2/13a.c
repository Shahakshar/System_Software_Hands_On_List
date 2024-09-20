/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Program 1 (PID: %d) is running. Waiting for SIGSTOP...\n", getpid());

    // Infinite loop to keep the program running
    while (1) {
        pause();  // Wait for signals
    }

    return 0;
}


