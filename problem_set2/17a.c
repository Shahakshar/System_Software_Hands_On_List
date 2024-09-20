/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
17. Write a program to execute ls -l | wc.
	a. use dup

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pid_t pid;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process: run `ls -l`
        close(pipefd[0]);  // Close the read end of the pipe

        // Redirect stdout to the write end of the pipe using dup()
        dup(pipefd[1]);
        close(pipefd[1]);

        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");  // execlp only returns if there's an error
        exit(EXIT_FAILURE);
    } else {
        // Parent process: run `wc`
        close(pipefd[1]);  // Close the write end of the pipe

        // Redirect stdin to the read end of the pipe using dup()
        dup(pipefd[0]);
        close(pipefd[0]);

        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(EXIT_FAILURE);
    }

    return 0;
}

