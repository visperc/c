/*
 * =====================================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  client side
 *
 *        Version:  1.0
 *        Created:  04/06/2017 14:03:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jimmy Chen (JC), visperc@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main(int argc , char** argv)
{
		int sockfd , n;
		char sendline[100];
		char recvline[100];
		struct sockaddr_in serveraddr;

		sockfd=socket(AF_INET , SOCK_STREAM , 0);
		bzero(&serveraddr , sizeof(serveraddr));
		serveraddr.sin_family = AF_INET;
		serveraddr.sin_port = htons(22000);
		inet_pton(AF_INET , "127.0.0.1",&(serveraddr.sin_addr));

		connect(sockfd , (struct sockaddr *)&serveraddr , sizeof(serveraddr));

		while(1)
		{
			bzero(sendline, 100);
			bzero(recvline, 100);

			fgets(sendline , 100 , stdin);
			write(sockfd , sendline , strlen(sendline)+1);
			read(sockfd, recvline , 100);
			printf("%s", recvline);

		}
}
