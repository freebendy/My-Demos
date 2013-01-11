//把指定的信息发送到指定的客户端，并接受客户端发回的信息
#include "unpv13e/unp.h"

#define PORT 13490

#define MAXDATASIZE 100

int main(int argc,char *argv[])
{
	int sockfd,numbytes,new_fd;
	char buf[MAXDATASIZE];
	struct hostent *he;
	struct sockaddr_in their_addr;

	if(argc <2)
	{
		fprintf(stderr,"usage:client hostname\n");
		exit(1);
	}

	if((he=gethostbyname(argv[1]))==NULL)
	{
		printf("gethostbyname");
		exit(1);
	}

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		printf("socket");
		exit(1);
	}

	//bzero(&their_addr,sizeof(their_addr));
	their_addr.sin_family=AF_INET;
	their_addr.sin_port=htons(PORT);
	their_addr.sin_addr=*((struct in_addr*)he->h_addr);
	bzero(&(their_addr.sin_zero),sizeof(their_addr.sin_zero));

	if((new_fd=connect(sockfd,(struct sockaddr*)&their_addr,sizeof(struct sockaddr)))==-1)
	{
		printf("connect");
		exit(1);
	}
	printf("get connection to %s\n",argv[1]);
//	if(!fork())
//	{
		if(send(sockfd,argv[2],14,0)==-1)
		{
			printf("send");
			exit(1);
		}
		printf("I Send: %s\n",argv[2]);
		//close(new_fd);
//	}


	if((numbytes=recv(sockfd,buf,MAXDATASIZE,0))==-1)
	{
		printf("recv");
		exit(1);
	}

	buf[numbytes]='\0';
	printf("I Received : %s\n",buf);
	close(sockfd);
	close(new_fd);
//	while(waitpid(-1,NULL,WNOHANG)>0);
	return 0;
}



