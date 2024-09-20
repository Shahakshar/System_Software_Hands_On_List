/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
28. Write a program to change the exiting message queue permission. 
(use msqid_ds structure)

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

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

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    printf("Current permissions: %o\n", buf.msg_perm.mode);

    buf.msg_perm.mode = 0666;

    if (msgctl(msgid, IPC_SET, &buf) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    printf("Updated permissions: %o\n", buf.msg_perm.mode);

    return 0;
}
