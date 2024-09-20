/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
d. remove the shared memory

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shm_id = shmget(key, 1024, 0666);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }

    char *shared_memory = (char *) shmat(shm_id, NULL, 0);
    if (shared_memory == (char *) -1) {
        perror("shmat failed");
        exit(1);
    }

    printf("Data read from shared memory: %s\n", shared_memory);
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

