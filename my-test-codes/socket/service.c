//实现把客户端发送过来的信息转发回去，未解决线程问题

#include "unpv13e/unp.h"

#define MYPORT 13490
#define BACKLOG 10
#define MAXDATASIZE 100

int main()
{
	char buf[MAXDATASIZE];
	int sockfd,new_fd,numbytes;
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;
	int sin_size;

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		printf("socket");
		exit(1);
	}

	//bzero(&my_addr,sizeof(my_addr));
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(MYPORT);
	my_addr.sin_addr.s_addr=INADDR_ANY;
	bzero(&(my_addr.sin_zero),sizeof(my_addr.sin_zero));


	if(bind(sockfd,(struct sockadd*)&my_addr,sizeof(struct sockaddr))==-1)
	{
		printf("bind");
		exit(1);
	}

	if(listen(sockfd,BACKLOG)==-1)
	{
		printf("listen");
		exit(1);
	}

	while(1)
	{
		sin_size=sizeof(struct sockaddr_in);
		if((new_fd=accept(sockfd,(struct sockaddr*)&their_addr,&sin_size))==-1)
		{
			printf("accept");
			continue;
		}

		printf("server : got connection from %s\n",inet_ntoa(their_addr.sin_addr));
		if((numbytes=recv(new_fd,buf,MAXDATASIZE,0))==-1)
		{
			printf("recv");
			exit(0);
		}
		buf[numbytes]='\0';
		printf("I Received from client: %s\n",buf);

		if(!fork())
		{
			if(send(new_fd,buf,14,0)==-1)
				printf("send");
		close(new_fd);
		exit(0);
		}
		close(new_fd);
		while(waitpid(-1,NULL,WNOHANG)>0);
	}
}








