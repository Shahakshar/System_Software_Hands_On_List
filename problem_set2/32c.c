/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
c. protect multiple pseudo resources ( may be two) using counting semaphore

==================================================
*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

int main(void) {

	int shmkey,shmid,semkey,semid;
	char *data;
	shmkey = ftok(".",'g');
	shmid=shmget(shmkey,1024,IPC_CREAT|0744);
	data =shmat(shmid,0,0);
	semkey=ftok(".",'f');
	semid=(semkey,1,0);
	struct sembuf buf={0,-1,0};
	semid=semget(semkey,1,0);
	semop(semid,&buf, 1);
	printf("critical section\n");
	printf("enter text:");
	scanf("%[^\n]",data);
	printf("data from shared memory : %s\n", data);

	printf("press enter to exit cs\n");
	getchar();
	buf.sem_op=1;
	semop(semid,&buf,1);
	printf("exited cs\n");
}
