// Akshar Shah
// MT2024014

/* 
write a program to create a file and print the file descriptor value. 
use creat() system call.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
	const char *file_ka_name = "creat.txt";
	int fd_ka_value = creat(file_ka_name, 0744);

	if (fd_ka_value < 0) {
		perror("creat failed");
		return 1;
	}
	printf("File descriptor: %d\n", fd_ka_value);

	if (close(fd_ka_value) < 0) {
		perror("close failed");
		return 1;
	}
	return 0;
}
