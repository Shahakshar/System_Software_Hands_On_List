// Akshar Shah
// MT2024014
/*
Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
*/
// Date: 22/08/24

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

int main(int arg, char *args[]) {
	struct stat ak;

	stat(args[1], &ak);
	printf("id of device=%ld\n", ak.st_dev);
	printf("inode=%ld\n", ak.st_ino);
	printf("file type and mode=%d\n", ak.st_mode);
	printf("number hardlink=%ld\n", ak.st_nlink);
	printf("user id=%d\n", ak.st_uid);
	printf("group id=%d\n", ak.st_gid);
	printf("device id=%ld\n", ak.st_rdev);
	printf("total size in byte=%ld\n", ak.st_size);
	printf("block size of fileSystem=%ld\n", ak.st_blksize);
	printf("Last Access time=%s", ctime(&(ak.st_atim).tv_sec));
	printf("Last modified time=%s", ctime(&(ak.st_mtim).tv_sec));
	printf("Last status change time=%s", ctime(&(ak.st_ctim).tv_sec));
	return 0;
}
