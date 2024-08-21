// Akshar Shah
// MT2024014
/*
Write a program to open a file with read write mode, write 10 bytes, move the file pointerby 10 bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int arg, char *args[]) {
	int fd = open(args[1],O_RDWR |  O_CREAT, S_IRWXU);
	if (fd == -1) {
		perror("ERROR While opening file");
		close(fd);
		return 0;
	}
	char s[10] = "ABCDEFGHIJ";
	write(fd, s, 10);
	int o = lseek(fd, 10, SEEK_CUR);
	printf("%d\n", o);
	write(fd, s, 10);
	o = lseek(fd, 0, SEEK_CUR);
	printf("%d\n", o);
	return 0;
}
