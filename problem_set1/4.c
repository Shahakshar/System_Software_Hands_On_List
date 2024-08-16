// Akshar Shah
// MT2024014

/* write a program to open an existing file with read write mode. try O_EXCL flag also.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(int arg, char *args[]) {
	int o = open(args[1], O_CREAT | O_WRONLY | O_EXCL);
	printf("%d\n",o);
	// int e = open(args[1], O_EXCL);
	// printf("%d\n", e);
	return 0;
}
