/*
name: 1.b
Author: Akshar Shah
Description: HardLink(link system call)
Date: 13/08/24
*/
#include<unistd.h>
#include<stdio.h>

int main() {
	const char *oldPath = "aksharHard.txt";
	const char *newPath = "pointerToHard";

	if (link(oldPath, newPath) == 0) {
		printf("HardLink Created Successfully");
	} else {
		perror("link failed");
	}
}
