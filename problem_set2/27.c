/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
27. Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag

==================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>
#define MAX_TEXT 100

struct msg_buffer {
    long msg_type;
    char msg_text[MAX_TEXT];
};

void receive_message(int msgid, long msg_type, int flags) {
    struct msg_buffer message;

    if (msgrcv(msgid, &message, sizeof(message.msg_text), msg_type, flags) == -1) {
        if (flags & IPC_NOWAIT && errno == ENOMSG) {
            printf("No message in queue (with IPC_NOWAIT flag).\n");
        } else {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Received message: %s\n", message.msg_text);
    }
}

int main() {
    key_t key;
    int msgid;

    key = ftok(".", 'b');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for a message with flag 0 (blocking)...\n");
    receive_message(msgid, 1, 0);

    printf("Trying to receive a message with IPC_NOWAIT flag (non-blocking)...\n");
    receive_message(msgid, 1, IPC_NOWAIT);

    return 0;
}
