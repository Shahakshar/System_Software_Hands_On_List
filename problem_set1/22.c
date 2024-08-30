// Akshar Shah
// MT2024014
/*
Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.
*/
// Date: 26/08/24
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int arg, char *args[]) {
	fork();
	int fd = open(args[1], O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
	char buffer[40];
	sprintf(buffer, "file written by = %d\n", getpid());
	write(fd, &buffer, sizeof(buffer));
	return 0;
}
