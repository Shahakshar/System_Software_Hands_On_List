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

    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    int fd = open(fifo_path, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char message[] = "Hello from the writer program!\n";
    write(fd, message, sizeof(message));

    printf("Writer: Message sent to FIFO.\n");

    close(fd);
    return 0;
}

