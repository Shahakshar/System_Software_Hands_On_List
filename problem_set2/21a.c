/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24


==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"

int main() {
    int fd_write, fd_read;
    char message[256], buffer[256];

    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    fd_write = open(FIFO1, O_WRONLY);
    if (fd_write == -1) {
        perror("open write FIFO1");
        exit(EXIT_FAILURE);
    }

    fd_read = open(FIFO2, O_RDONLY);
    if (fd_read == -1) {
        perror("open read FIFO2");
        exit(EXIT_FAILURE);
    }

    strcpy(message, "Hello from parent");
    write(fd_write, message, strlen(message) + 1);

    read(fd_read, buffer, sizeof(buffer));
    printf("Parent received: %s\n", buffer);

    close(fd_write);
    close(fd_read);

    return 0;
}
