/*
 * =====================================================================================
 *
 *       Filename:  server.c
 *
 *    Description:  simple c socket server
 *
 *        Version:  1.0
 *        Created:  04/06/2017 12:50:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jimmy Chen (JC), visperc@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc , char** argv)
{
	char str[100];
	int listen_fd , comm_fd;

	struct sockaddr_in serveraddr;

	listen_fd = socket(AF_INET , SOCK_STREAM , 0);
	
	bzero(&serveraddr , sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htons(INADDR_ANY);
	serveraddr.sin_port = htons(22000);
	bind(listen_fd, (struct sockaddr*) &serveraddr , sizeof(serveraddr));

	listen(listen_fd , 10);

	comm_fd = accept(listen_fd , (struct sockaddr*)NULL , NULL);

	while(1)
	{
			bzero(str , 100);
			read(comm_fd , str , 100);
			printf("Echo back - %s", str);
			write(comm_fd , str , strlen(str) + 1);
	}



}
