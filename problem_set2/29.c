/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
29. Write a program to remove the message queue.

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    key = ftok(".", 'b');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}
/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24

==================================================
*/
