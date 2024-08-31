// Akshar Shah
// MT2024014
/*
Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular 
record, first lock it then modify/access to avoid race condition.
*/
// Date: 25/08/24

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	struct db {
		int train_num;
		int ticket_count;
	} db[3];
	int fd, input;
	fd = open("record.txt", O_RDWR);
	printf("select train number (1,2,3): \n");
	scanf("%d", &input);
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_start = (input-1)*sizeof(db);
	lock.l_len = sizeof(db);
	lock.l_pid = getpid();

	// reading value of ticket number
	lseek(fd, (input-1)*sizeof(db), SEEK_SET);
	read(fd, &db, sizeof(db));
	printf("Before entering into the critical section \n");

	fcntl(fd, F_SETLKW, &lock);
	printf("Before Ticket Book Ticket number: %d\n", db[input-1].ticket_count);
	db[input-1].ticket_count++;
	printf("After Ticket book  Ticket number: %d\n", db[input-1].ticket_count);
	lseek(fd, -1*sizeof(db), SEEK_CUR);
	write(fd, &db, sizeof(db));
	printf("To Book Ticket, press Enter: \n");
	getchar();
	getchar();
	lock.l_type=F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("Booked\n");
}

// doubt regarding reading jab koi read kar raha hai tab write allow nahi hoga 
// and jab koi write kar raha hoga to vo read nahi kar payega 
// and at same time more than 1 person can read the db ye ho sakta hai.
