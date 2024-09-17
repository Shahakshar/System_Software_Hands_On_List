/*
Author: Akshar Shah
Roll No: MT2024014
Date: 18/09/2024

3. Write a program to set (any one) system resource limit. Use setrlimit system call.

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main() {
    struct rlimit limit;

    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("Current soft limit for open files: %lu\n", limit.rlim_cur);
        printf("Current hard limit for open files: %lu\n", limit.rlim_max);
    } else {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    limit.rlim_cur = 1024; 
    limit.rlim_max = 2048; 

    if (setrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("New limits set successfully!\n");
    } else {
        perror("setrlimit");
        exit(EXIT_FAILURE);
    }

    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("New soft limit for open files: %lu\n", limit.rlim_cur);
        printf("New hard limit for open files: %lu\n", limit.rlim_max);
    } else {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    return 0;
}

