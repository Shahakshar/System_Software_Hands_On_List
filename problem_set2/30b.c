/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
b. attach with O_RDONLY and check whether you are able to overwrite.

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shm_id;
    char *shared_memory;

    shm_id = shmget(key, 1024, 0666);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }

    shared_memory = (char *) shmat(shm_id, NULL, SHM_RDONLY); 
    if (shared_memory == (char *) -1) {
        perror("shmat failed");
        exit(1);
    }

    printf("Data read from shared memory: %s\n", shared_memory);

    printf("Attempting to write to shared memory in read-only mode...\n");
    strcpy(shared_memory, "Trying to overwrite!");
    if (shmdt(shared_memory) == -1) {
        perror("shmdt failed");
        exit(1);
    }

    printf("Shared memory detached.\n");

    return 0;
}

