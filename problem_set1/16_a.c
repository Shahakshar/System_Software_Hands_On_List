#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int arg, char *args[]) {
	int fd = open(args[1], O_WRONLY);
	if (fd == -1) {
		printf("Error While Opening File");
		return 0;
	}
	struct flock lock = {F_WRLCK,0,0,0,0};
	fcntl(fd, F_SETLKW, &lock);
	printf("File is locked.\n press enter to unlock file\n");
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLKW, &lock);
	return 0;
}
