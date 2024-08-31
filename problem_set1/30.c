// Akshar Shah
// MT2024014
/*
30. Write a program to run a script at a specific time using a Daemon process.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
int main(){
	if (!fork()){
		setsid();
		chdir("/");
		umask(0);
		while(1){
			sleep(5);
			printf("daemon is running");
		}
	}
	else
		exit(0);
}
