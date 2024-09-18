/*
Author: Akshar Shah
Roll No: MT2024014
Date: 18/09/2024

4. Write a program to measure how much time is taken to execute 100 getppid() system call. Use time stamp counter.

*/

#include <stdio.h>
#include <unistd.h>

unsigned long long rdtsc() {
	unsigned int lo, hi;
	asm volatile("rdtsc": "=a" (lo), "=d"(hi));
	return ((unsigned long long) hi<<32) | lo;
}

int main() {
	unsigned long long start, end;
	int i;

	start = rdtsc();

	for (int i=0; i<100; i++) {
		getpid();
	}

	end = rdtsc();

	unsigned long long cycles_taken = end - start;
	printf("CPU Cycle taken: %llu\n", cycles_taken);
	return 0;
}
