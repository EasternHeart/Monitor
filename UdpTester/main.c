#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

#define SERVER_PORT 9741

int GetServerAddr(char * addrname)
{
printf("please input server addr:");
scanf("%s",addrname);
return 1;
}
int main(int argc,char **argv)
{
int cli_sockfd;
int len;
socklen_t addrlen;
char seraddr[14];
struct sockaddr_in cli_addr;
char buffer[256];
GetServerAddr(seraddr);
/* 建立socket*/
cli_sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(cli_sockfd<0)
{
        printf("I cannot socket success\n");
        return 1;
}
/* 填写sockaddr_in*/
addrlen=sizeof(struct sockaddr_in);
bzero(&cli_addr,addrlen);
cli_addr.sin_family=AF_INET;
cli_addr.sin_addr.s_addr=inet_addr(seraddr);
//cli_addr.sin_addr.s_addr=htonl(INADDR_ANY);
cli_addr.sin_port=htons(SERVER_PORT);
bzero(buffer,sizeof(buffer));
/* 从标准输入设备取得字符串*/
len=read(STDIN_FILENO,buffer,sizeof(buffer));
/* 将字符串传送给server端*/
sendto(cli_sockfd,buffer,len,0,(struct sockaddr*)&cli_addr,addrlen);
close(cli_sockfd);
}
