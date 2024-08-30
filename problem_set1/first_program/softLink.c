/*
name: 1.a
Author: Akshar Shah
Description: SoftLink(Symlink system Call)
Date: 13/08/24
*/
#include<unistd.h>
#include<stdio.h>

int main() {
	const char *target = "aksharSoft.txt";
	const char *linkPath = "softPeLink.txt";

	if (symlink(target, linkPath) == 0) {
		printf("Symbolic link created successfully. \n");
	} else {
		perror("symlink failed");
	}

	return 0;
}
