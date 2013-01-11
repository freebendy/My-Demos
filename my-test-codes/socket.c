/*
*本文内容提到的套接字都是Berkely socket.

*实用套接字的四个步骤:
*1 分配空间和初始化
*2 连接
*3 传送数据
*4 关闭
*
*具体算法:
*/

//服务器端:

#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
int socket_descriptor = socket(AF_INET,SOCK_STREAM,0) ;

int port = 8000 ;
struct sockaddr_in sin ;
sin.sin_family = AF_INET ;
sin.sin_addr.s_addr = INADDR_ANY ;
sin.sin_port = htons(port) ;

bind(socket_descriptor,(struct socketaddr*)&sin ,sizeof(sin));

listen(socket_descriptor,1024);

struct sockaddr_in pin ;
int address_size ;
int temp_socket_descriptor ;

while(1)
{
    temp_socket_descriptor = accept(socket_descriptor,(struct socketaddr*)&pin,sizeof(address_size)) ;
	//......
    close(temp_socket_descriptor) ;
}
return 0;
}




//客户端：
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> //直接影响sockaddr_in.sin_addr的填写


int main()
{
char *host_name = "127.0.0.1" ;
struct hostent *server_host_name ;
server_host_name = gethostbyname(host_name) ;

int port  = 8000 ;
struct sockaddr_in pin ;
pin.sin_family = AF_INET ;
pin.sin_addr.s_addr = INADDR_ANY ;
pin.sin_addr.s_addr = ((struct in_addr *)(server_host_name->h_addr))->s_addr ;
server_host_name->h_addr ;
pin.sin_port = htons(port) ;

int socket_descriptor ;
socket_descriptor = socket(AF_INET,SOCK_STREAM,0) ;
connect(socket_descriptor,(void *)&pin, sizeof(pin)) ;
//.......
close(socket_descriptor); 
return 0;
}
