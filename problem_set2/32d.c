/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
d. remove the created semaphore

==================================================
*/

#include<stdio.h>
#include<sys/sem.h>
#include<unistd.h>

union semun {
	int val;
	struct semid_ds *buff;
	unsigned short int *array;
};

int main(void) {
	union semun arg;
	int key , semid;
	key = ftok(".",'a');
	semid=semget(key,1,0);
	semctl(semid, 0, IPC_RMID);
}
