/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
6. Write a simple program to create three threads.

==================================================
*/

#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    printf("Hello from thread %ld\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t threads[3];

    for (long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, threadFunction, (void*)i);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
