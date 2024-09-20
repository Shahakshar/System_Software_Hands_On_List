/*
============================================================================
Author : Akshar Shah
Roll No: MT2024014
Date: 20/09/24
19. Create a FIFO file by
                d. mknod system call

============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    
    char name[20];

    printf("Enter the name of pipe : ");
    scanf("%s",name);

    mknod(name, S_IFIFO | 0666,0);
    


    return 0;
}
