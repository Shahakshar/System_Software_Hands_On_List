/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE

==================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int signalNo) {
	if(signalNo == SIGFPE){
		printf("Caught SIGFE \n");
		exit(1);
	}
	else if(signalNo == SIGINT){
		printf("Caught SIGINT (Ctrl+C)\n");
		exit(1);
	}
	else if(signalNo == SIGSEGV){
		printf("Caught SIGSEGV (segmentation fault)\n");
		exit(1);
	}
}

int main(){
	struct sigaction action_a;

	action_a.sa_handler = handler;
	sigemptyset(&action_a.sa_mask);
	action_a.sa_flags = 0;

	sigaction(SIGFPE,&action_a,NULL);
	sigaction(SIGINT,&action_a,NULL);
	sigaction(SIGSEGV,&action_a,NULL);

	while(1){
	//	printf("press ctrl+c for sigint\n ");
	//	sleep(1);
	
	// int x = 5/0; this is to get SIGFPE trigger
		int *ptr = NULL;
		*ptr = 42;
	}
	return 0;
}
