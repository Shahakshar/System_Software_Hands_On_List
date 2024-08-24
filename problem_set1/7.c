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
	int file_d = open(args[1], O_RDONLY);
	if (file_d == -1) {
		printf("Error while opening source file");
		close(file_d);
	}
	int file_d1 = open(args[2], O_WRONLY | O_CREAT, S_IRWXU);
	if (file_d1 == -1) {
		printf("Error While Creating And Opening");
		close(file_d1);
	}
	char content;
	while (read(file_d, &content, 1)) {
		write(file_d1, &content,1);
	}
	printf("Copy Successfully");
	close(file_d);
	close(file_d1);
	return 0;
}


