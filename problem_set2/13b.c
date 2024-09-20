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
    pid_t target_pid;

    printf("Enter the PID of Program 1 to send SIGSTOP: ");
    scanf("%d", &target_pid);  
    if (kill(target_pid, SIGSTOP) == -1) {
        perror("Error sending SIGSTOP signal");
        exit(EXIT_FAILURE);
    }

    printf("SIGSTOP signal sent to process %d.\n", target_pid);
    return 0;
}

