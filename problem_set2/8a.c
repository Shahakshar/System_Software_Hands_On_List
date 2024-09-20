/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24


==================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signum) {
    switch (signum) {
        case SIGSEGV:
            printf("Caught SIGSEGV: Invalid memory access!\n");
            exit(1);
            break;
    }
}

int main() {
    signal(SIGSEGV, signal_handler); 
    int *ptr = NULL;
    *ptr = 42; 
    return 0;
}

