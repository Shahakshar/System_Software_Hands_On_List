/*
==================================================
Author: Akshar Shah
Roll No: MT2024014
Date: 20/09/24
34. Write a program to create a concurrent server.
a. use fork
b. use pthread_create

==================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<sys/types.h>
int main() {
	int sd,nsd,sz;
	struct sockaddr_in serv, cli;
	char buff[80];
	sd = socket (AF_UNIX, SOCK_STREAM, 0);

	serv.sin_family = AF_UNIX;
	serv.sin_addr.s_addr = INADDR_ANY;
	serv.sin_port = htons (5080);

	bind (sd, (void*)(&serv), sizeof (serv));
	listen (sd, 5);
	sz=sizeof(cli);
	while(1) {
		nsd = accept (sd,(void*)( &cli), &sz);
		if(!(fork())) {
			close(sd);
			read(nsd,buff,sizeof (buff));
			printf("message from client:%s\n",buff);
			write(nsd,"hi i am server\n",16);
			exit(0);
		}
		else
			close(nsd);
	}
}
