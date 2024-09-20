/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
17. Write a program to execute ls -l | wc.
	c. use fcntl

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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

        // Redirect stdout to the write end of the pipe using fcntl()
        fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO);
        close(pipefd[1]);

        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(EXIT_FAILURE);
    } else {
        // Parent process: run `wc`
        close(pipefd[1]);  // Close the write end of the pipe

        // Redirect stdin to the read end of the pipe using fcntl()
        fcntl(pipefd[0], F_DUPFD, STDIN_FILENO);
        close(pipefd[0]);

        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(EXIT_FAILURE);
    }

    return 0;
}

