#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main() {
	const char *fifo_name = "dumpFifoC";
	if (mkfifo(fifo_name, 0666) == -1) {
		perror("mkfifo failed");
		return 1;
	}

	printf("FIFO created Successfully.\n");
	return 0;
}
