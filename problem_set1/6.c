// Akshar Shah
// MT2024014

/* 
Write a program to take input from STDIN and display on STDOUT. 
Use only read/write system calls.
*/

#include<stdio.h>
#include<unistd.h>

int main() {
	char input_bf[50];

	int n = read(0, input_bf, 50);
	write(1, input_bf, n);
}
