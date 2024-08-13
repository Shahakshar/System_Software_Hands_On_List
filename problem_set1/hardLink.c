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
