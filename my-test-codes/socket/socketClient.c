#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> //直接影响sockaddr_in.sin_addr的填写


int main()
{
	char *host_name = "127.0.0.1" ;
	struct hostent *server_host_name ;
	server_host_name = gethostbyname(host_name) ;
	int numbytes;
	char buf[100];
	
	int port  = 8000 ;
	struct sockaddr_in pin ;
	bzero(&pin, sizeof(pin));
	pin.sin_family = AF_INET ;
	pin.sin_addr.s_addr = INADDR_ANY ;
	pin.sin_addr.s_addr = ((struct in_addr *)(server_host_name->h_addr))->s_addr ;
	server_host_name->h_addr ;
	pin.sin_port = htons(port) ;

	int socket_descriptor ;
	socket_descriptor = socket(AF_INET,SOCK_STREAM,0) ;
	if(connect(socket_descriptor,(void *)&pin, sizeof(pin))==-1)
	{
		printf("connetc\n");
		exit(1);
	}
	if((numbytes=recv(socket_descriptor,buf,100,0))==-1)
	{
		printf("recv");
		exit(1);
	}

    buf[numbytes]='\0';
	printf("numbytes: %d\n",numbytes);
	printf("I Received : %s\n",buf);
	
	close(socket_descriptor); 
	return 0;
}

