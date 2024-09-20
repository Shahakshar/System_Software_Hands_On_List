/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Child process (PID: %d) started.\n", getpid());
        sleep(1); 
        printf("Child process sending SIGKILL to parent (PID: %d).\n", getppid());
        kill(getppid(), SIGKILL);

        printf("Child process (orphan) is now adopted by 'init' (PID: 1).\n");
        sleep(5);

        printf("Child process (orphan) exiting.\n");
        exit(EXIT_SUCCESS);

    } else {
        printf("Parent process (PID: %d) waiting for child process.\n", getpid());
        while (1) {
            sleep(1);
        }
    }

    return 0;
}

