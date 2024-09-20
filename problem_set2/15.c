/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
15. Write a simple program to send some data from parent to the child process.

==================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char write_buff[80];
    char read_buff[80];
    char read_buff1[80];
    int fd[2];
    int x;
    pipe(fd);
    if (fork()) {
        close(fd[0]);
        while(1)
        {
            printf("Inside parent\n");
            printf("Enter \n1 : to send message \n0 : to exit\n");
            scanf("%d",&x);
            if(x==0)
            {
                break;
            }
            else
            {
                printf("Enter message to the child('q' for exit): ");
                scanf(" %[^\n]", write_buff);
                write(fd[1], write_buff, sizeof(write_buff));
                sleep(2);
            }

        }

    }
    else {
        close(fd[1]);
        int pid = getppid();
        while(1)
        {
            if(getppid()!=pid)
            {
                break;
            }
            read(fd[0], read_buff, sizeof(read_buff));
            printf("Inside child\n");
            printf("Message from parent: %s\n", read_buff);


        }
    }
    return 0;
}
