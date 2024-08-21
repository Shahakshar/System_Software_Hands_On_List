// MT2024014
// Akshar Shah
/*
Write a program to copy file1 into file2 ($cp file1 file2).
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int arg, char *args[]) {
	int fd1 = open(args[1], O_RDONLY);
	if (fd1 == -1) {
		printf("Error while opening source file");
		close(fd1);
	}
	int fd2 = open(args[2], O_WRONLY | O_CREAT, S_IRWXU);
	if (fd2 == -1) {
		printf("Error While Creating And Opening");
		close(fd2);
	}
	char content;
	while (read(fd1, &content, 1)) {
		write(fd2, &content,1);
	}
	printf("Copy Successfully");
	close(fd1);
	close(fd2);
	return 0;
}


