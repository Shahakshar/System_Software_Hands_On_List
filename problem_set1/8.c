// Akshar shah
// MT2024014
/*
Write a program to open a file in read only mode, read line by line and display each line as it is read.Close the file when end of file is reached.
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(int arg, char *args[]) {
	char buffer[1024];
	int fd1;
	fd1 = open("source", O_RDONLY);

	while (read(fd1, &buffer, 1)) {
		if (buffer[0] == '\n') 
			getchar();
		else 
			printf("%c", buffer[0]);
	}
	close(fd1);
	return 0;
}
