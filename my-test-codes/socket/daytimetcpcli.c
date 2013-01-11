#include	"../unp.h"

int
main(int argc, char **argv)
{
	int					sockfd, n;
	char				recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr;

	if (argc != 2)
		printf("usage: a.out <IPaddress>");

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		printf("socket error");
	//使用add注释的代码是通过输入域名的发送，注释掉的是通过ip来发送
	struct hostent *server_host_name ; //add
    server_host_name = gethostbyname(argv[1]) ;//add
	
	bzero(&servaddr, sizeof(servaddr));//必须
	printf("host address before exchanged: %s\n",argv[1]);
	
	servaddr.sin_addr.s_addr = INADDR_ANY ;//add
    servaddr.sin_addr.s_addr = ((struct in_addr *)(server_host_name->h_addr))->s_addr ;//add
    server_host_name->h_addr ;//add
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(13);	/* daytime server */
	//if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	//	printf("inet_pton error for %s", argv[1]);

	printf("host address : %d\n",servaddr.sin_addr);//add 转换成网络字节顺序的地址

	printf("host address after exchanged: %s\n",inet_ntoa(servaddr.sin_addr));//本地字节顺序
	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		printf("connect error");

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		recvline[n] = 0;	/* null terminate */
		if (fputs(recvline, stdout) == EOF)
			printf("fputs error");
	}
	if (n < 0)
		printf("read error");

	exit(0);
}
