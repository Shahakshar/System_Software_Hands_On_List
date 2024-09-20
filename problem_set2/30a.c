/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
30. Write a program to create a shared memory.
a. write some data to the shared memory

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("akshar", 65);
    int shm_id;
    char *shared_memory;

    shm_id = shmget(key, 1024, 0666 | IPC_CREAT); // 1024 bytes of shared memory
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }

    shared_memory = (char *) shmat(shm_id, NULL, 0);
    if (shared_memory == (char *) -1) {
        perror("shmat failed");
        exit(1);
    }

    printf("Writing data to shared memory...\n");
    strcpy(shared_memory, "Hello, this is a shared memory message!");
    printf("Data written: %s\n", shared_memory);

    if (shmdt(shared_memory) == -1) {
        perror("shmdt failed");
        exit(1);
    }

    printf("Shared memory detached.\n");

    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl (IPC_RMID) failed");
        exit(1);
    }

    printf("Shared memory segment removed successfully.\n");

    return 0;
}

