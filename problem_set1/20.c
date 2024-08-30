// Akshar Shah
// MT2024014
/*
Find out the priority of your running program. Modify the priority 
with nice command. 
*/
// Date: 26/08/24

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
	pid_t pid;
	int priority;
	
	pid = getpid();
	priority = getpriority(PRIO_PROCESS, pid);
	printf("Current priority: %d\n", priority);
	int increment = 5;
	int priority2 = nice(increment);
	printf("new priority after nice(%d): %d\n", increment, priority2);
	priority = getpriority(PRIO_PROCESS, pid);
	if (priority == -1 && errno != 0) {
		perror("getpriority");
		return 1;
	}
	printf("Verified new priority: %d\n", priority);
	return 0;
}
