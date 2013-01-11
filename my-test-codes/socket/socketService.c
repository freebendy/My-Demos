#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	int socket_descriptor = socket(AF_INET,SOCK_STREAM,0) ;

    int port = 8000 ;
	struct sockaddr_in sin ;
	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET ;
	sin.sin_addr.s_addr = INADDR_ANY ;
	sin.sin_port = htons(port) ;
	
	bind(socket_descriptor,(struct sockaddr*)&sin ,sizeof(sin));

	listen(socket_descriptor,1024);

	struct sockaddr_in pin ;
	int address_size ;
	int temp_socket_descriptor ;

	while(1)
	{
		address_size = sizeof(struct sockaddr_in);
    	temp_socket_descriptor = accept(socket_descriptor,(struct sockaddr*)&pin,&address_size) ;
		if(temp_socket_descriptor==-1)
		{
			printf("accept");
			exit(1);
		}
		printf("server : got connection from %s\n",inet_ntoa(pin.sin_addr));
		if(!fork())
		{
			if(send(temp_socket_descriptor,"hello,client!",14,0)==-1)
				printf("send");
			close(temp_socket_descriptor);
			exit(0);
		}
	}
    close(temp_socket_descriptor) ;
	return 0;

}

