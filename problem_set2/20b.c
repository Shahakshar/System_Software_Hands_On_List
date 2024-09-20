/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
20. Write two programs so that both can communicate by FIFO -Use one way communication.

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const char *fifo_path = "/tmp/myfifo";

    int fd = open(fifo_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    int num_bytes = read(fd, buffer, sizeof(buffer) - 1);
    if (num_bytes == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buffer[num_bytes] = '\0';
    printf("Reader: Message received from FIFO: %s\n", buffer);

    close(fd);
    return 0;
}

