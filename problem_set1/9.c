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

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

int main(int arg, char *args[]) {
	struct stat s;

	stat(args[1], &s);
	printf("id of device=%ld\n", s.st_dev);
	printf("inode=%ld\n", s.st_ino);
	printf("file type and mode=%d\n", s.st_mode);
	printf("number hardlink=%ld\n", s.st_nlink);
	printf("user id=%d\n", s.st_uid);
	printf("group id=%d\n", s.st_gid);
	printf("device id=%ld\n", s.st_rdev);
	printf("total size in byte=%ld\n", s.st_size);
	printf("block size of fileSystem=%ld\n", s.st_blksize);
	printf("Last Access time=%s", ctime(&(s.st_atim).tv_sec));
	printf("Last modified time=%s", ctime(&(s.st_mtim).tv_sec));
	printf("Last status change time=%s", ctime(&(s.st_ctim).tv_sec));
	return 0;
}
