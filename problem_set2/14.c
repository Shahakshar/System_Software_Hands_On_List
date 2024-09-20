/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2]; 
    char buffer[100]; 
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    const char *message = "Hello from the main process!";
    write(pipefd[1], message, strlen(message) + 1); 
    close(pipefd[1]); 

    read(pipefd[0], buffer, sizeof(buffer));  
    printf("Received: %s\n", buffer);
    close(pipefd[0]); 

    return 0;
}

