// Akshar Shah
// Mt2024014
/*
Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
*/
// Date: 24/08/24
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
#include<stdlib.h>
#include<sys/sysmacros.h>

int main(int arg, char *args[]) {
	struct stat s;
	int a = lstat(args[1], &s);
	printf("file type:");
	switch (s.st_mode & S_IFMT) {
		case S_IFBLK:
			printf("block device\n");
			break;
		case S_IFCHR:
			printf("character device\n");
			break;
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFIFO:
			printf("FIfi/pipe\n");
			break;
		case S_IFLNK:
			printf("symlink\n");
			break;
		case S_IFREG:
			printf("regular file\n");
			break;
		case S_IFSOCK:
			printf("socket\n");
			break;
		default:
			printf("unknown?\n");
			break;
		}
}
