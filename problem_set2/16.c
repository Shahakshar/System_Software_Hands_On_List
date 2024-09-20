/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
16. Write a program to send and receive data from parent to child vice versa. 
Use two way communication.

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
    int parent_fd[2],child_fd[2];
    int x;
    pipe(parent_fd);
    pipe(child_fd);
    if (fork()) {
        close(parent_fd[0]);
        close(child_fd[1]);
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
                printf("Enter message to the child: ");
                scanf(" %[^\n]", write_buff);
                write(parent_fd[1], write_buff, sizeof(write_buff));
                read(child_fd[0], read_buff, sizeof(read_buff));
                printf("CHILD: %s\n", read_buff);
            }

        }

    }
    else {
        close(parent_fd[1]);
        close(child_fd[0]);
        int pid = getppid();
        while(1)
        {
            read(parent_fd[0], read_buff, sizeof(read_buff));
            if(getppid()!=pid)
            {
                break;
            }
            else
            {
                printf("Inside child\n");
                printf("PARENT: %s\n", read_buff);
                printf("Enter message to the parent: ");
                scanf(" %[^\n]", write_buff);
                write(child_fd[1], write_buff, sizeof(write_buff));
            }



        }
    }
    return 0;
}
