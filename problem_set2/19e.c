/*
============================================================================
Author : Akshar Shah
Roll No: MT2024014
Date: 20/09/24
19. Create a FIFO file by
                e. mkfifo library function

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

    mkfifo(name, 0666);
    


    return 0;
}

