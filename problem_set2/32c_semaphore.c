/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24


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
	key = ftok(".",'f');
	semid=semget(key,1,IPC_CREAT |0644);
	arg.val=2;
	semctl(semid,0,SETVAL, arg);
}
