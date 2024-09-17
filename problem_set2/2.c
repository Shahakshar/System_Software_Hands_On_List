/*
Author: Akshar Shah
Roll No: MT2024014
Date: 18/09/2024

2. Write a program to print the system resource limits. Use getrlimit system 
call.

*/

// getrlimit and setrlimit are system call interfaces for getting and setting 
// resource limits.

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void print_limit(int resource, const char *resource_name) {
    struct rlimit limit;

    if (getrlimit(resource, &limit) == 0) {
        printf("%s:\n", resource_name);
        printf("  Soft limit: ");
        if (limit.rlim_cur == RLIM_INFINITY)
            printf("Unlimited\n");
        else
            printf("%lu\n", limit.rlim_cur);

        printf("  Hard limit: ");
        if (limit.rlim_max == RLIM_INFINITY)
            printf("Unlimited\n");
        else
            printf("%lu\n", limit.rlim_max);

    } else {
        perror("getrlimit");
    }
}

int main() {
    print_limit(RLIMIT_CPU, "CPU time (seconds)");
    print_limit(RLIMIT_FSIZE, "File size (bytes)");
    print_limit(RLIMIT_DATA, "Data segment size (bytes)");
    print_limit(RLIMIT_STACK, "Stack size (bytes)");
    print_limit(RLIMIT_CORE, "Core file size (bytes)");
    print_limit(RLIMIT_RSS, "Resident set size (bytes)");
    print_limit(RLIMIT_NOFILE, "Number of open files");
    print_limit(RLIMIT_NPROC, "Number of processes");

    return 0;
}

