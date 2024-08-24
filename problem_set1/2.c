// Akshar shah
// MT2024014

/* 
Write a simple program to execute in an infinite loop at the background. 
Go to /proc directory and identify all the process related information in the corresponding proc director.
*/

#include<stdio.h>
#include<unistd.h>

int main() {
	while (1) {
		printf("this is akshar\n");
		sleep(5);
	}
	return 0;
}

