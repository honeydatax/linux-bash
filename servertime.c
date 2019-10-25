#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h> 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <netdb.h>


int main(int argc, char *argv[])
{
    int fd = 0, cfd = 0;
    struct sockaddr_in address; 
	int buffersize=860000;
    char buff[buffersize];
    char buff2[buffersize];
	char *p1;
	char *p2;
	char *p3;
	char *p4;
	char *p5;
	char *p6;
    time_t ticks;
    ssize_t t;
    
    printf("\e[0;47;34m\n"); 

    fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&address, '0', sizeof(address));
    memset(buff, '0', sizeof(buff)); 

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(8080); 

    bind(fd, (struct sockaddr*)&address, sizeof(address)); 

    listen(fd, 10); 

    while(1)
    {
		printf("startserver \n");
        cfd = accept(fd, (struct sockaddr*)NULL, NULL); 
		t=read(cfd,buff2,buffersize);
		p1=strstr(buff2,"GET / HTTP/1.1\r\n");
		if (p1!=NULL){
		printf("*****\n");
		printf("%s\n",buff2);
		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		strcpy(buff2,"HTTP/1.0 200 OK\r\n");
		write(cfd,buff2,strlen(buff2));
		strcpy(buff2,"Server: TIME SERVER HTML\r\n\r\n");
		write(cfd,buff2,strlen(buff2));
		sprintf(buff2,"Date: %s\r\n\r\n",buff);
		write(cfd,buff2,strlen(buff2));
		strcpy(buff2,"Content-type: text/html\r\n\r\n");
		write(cfd,buff2,strlen(buff2));
        sprintf(buff2,":%s\r\n\r\n",buff);
        write(cfd,buff2,strlen(buff2));
        sprintf(buff2,"Content-Length: %d\r\n\r\n",strlen(buff+4));
        write(cfd,buff2,strlen(buff2));
        sprintf(buff2,":%s\r\n\r\n",buff);
        write(cfd,buff2,strlen(buff2));
        sprintf(buff2,"Last-Modified: %s\r\n\r\n",buff);
        write(cfd,buff2,strlen(buff2));
        sprintf(buff2,"st-Modified: %s\r\n\r\n",buff);
        write(cfd,buff2,strlen(buff2));
        sprintf(buff2,"%s\r\n\r\n",buff);
        write(cfd,buff2,strlen(buff2));

		}else{
		strcpy(buff2,"HTTP/1.0 400 OK\r\n");
		printf("%s\n",buff2);
		write(cfd,buff2,strlen(buff2));
		}
        close(cfd);
        //sleep(1);
     }
}
