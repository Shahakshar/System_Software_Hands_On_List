#include<unistd.h>
#include<stdio.h>

int main() {
	const char *target = "aksharSoft.txt";
	const char *linkPath = "../pointer1";

	if (symlink(target, linkPath) == 0) {
		printf("Symbolic link created successfully. \n");
	} else {
		perror("symlink failed");
	}

	return 0;
}
