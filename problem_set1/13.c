// Akshar Shah
// MT2024014
/*
Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not(check in $man 2 select).
*/
// Date: 24/08/24
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
	struct timeval t;
	fd_set file_d;
	FD_SET(0, &file_d);
	t.tv_sec = 10;
	t.tv_usec = 0;
	int o = select(1, &file_d, NULL, NULL, &t);
	printf("%d\n", o);
	if (o == -1) {
		printf("ERROR OCCURED");
	}
	else if (o == 0) {
		printf("TIME OUT");
	} else {
		printf("DATA ENTERED");
	}
	return 0;
}
