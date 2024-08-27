#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	struct {
		int ticket_no;
	} db;
	struct flock lock;
	int fd;
	fd = open("db", O_RDWR);
	read(fd, &db, sizeof(db));
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("Before entering into critical section\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Current Ticket No: %d\n", db.ticket_no);
	db.ticket_no++;
	lseek(fd, 0L, SEEK_SET);
	printf("Eenter into critical section....\n");
	printf("Enter to unlock...\n");
	write(fd, &db, sizeof(db));
	getchar();
	lock.l_type = F_UNLCK;
	printf("unlocked\n");
	fcntl(fd, F_SETLK, &lock);
	printf("finish\n");
}

