/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
23. Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).

==================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    long max_files = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files: %ld\n", max_files);

    return 0;
}
