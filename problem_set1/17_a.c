#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void) {
	int file_des;
	struct {
		int ticket_no;
	}db;
	db.ticket_no = 10;
	file_des = open("db", O_CREAT|O_RDWR, 0744);
	write(file_des, &db, sizeof(db));
	close(file_des);
	file_des = open("db", O_RDONLY);
	read(file_des, &db, sizeof(db));
	printf("ticket No: %d\n", db.ticket_no);
	close(file_des);
}
