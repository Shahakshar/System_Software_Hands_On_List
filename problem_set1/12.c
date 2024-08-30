//Akshar Shah
// MT2024014
/*
Write a program to find out the opening mode of a file. Use fcntl.
*/
// Date: 23/08/24
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int argv, char *argc[]) {
	int fd = open(argc[1], O_RDONLY);
	int f_mode = fcntl(fd, F_GETFL);
	printf("%d\n", f_mode);
	int accessMode = f_mode & O_ACCMODE;
	printf("%d\n", accessMode);
	switch(accessMode) {
		case O_RDWR:
			printf("O_RDWR\n");
			break;
		case O_WRONLY:
			printf("O_WRONLY\n");
			break;
		case O_RDONLY:
			printf("O_RDONLY\n");
			break;
		deafult:
			break;
	}
	close(fd);
	close(f_mode);
	return 0;
}

