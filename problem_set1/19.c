// Akshar Shah
// MT2024014
/*
Write a program to find out time taken to execute getpid system call.Use time stamp counter.
*/
// Date: 25/08/24

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

static inline uint64_t rdtsc() {
	unsigned int low, high;
	asm volatile ("rdtsc" : "=a" (low), "=d" (high));
	return ((uint64_t)high << 32) | low;
}

int main() {
	uint64_t start, end;
	pid_t pid;

	start = rdtsc();
	pid = getpid();
	end = rdtsc();
	uint64_t cycles_taken = end - start;
	printf("PID: %d\n", pid);
	printf("Time taken for getpid() in cpu cycles: %llu\n", (unsigned long long) cycles_taken);
	return 0;
}
