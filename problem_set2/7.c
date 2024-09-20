/*
==================================================
Author: Akshar Shah
Date: 20/09/24
Roll No: MT2024014
7. Write a simple program to print the created thread ids.

==================================================
*/

#include <stdio.h>    
#include <pthread.h>   

void* threadFunction(void* arg) {
    pthread_t thread_id = pthread_self();

    printf("Thread %ld created with ID: %lu\n", (long)arg, thread_id);

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

