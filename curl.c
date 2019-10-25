#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <netdb.h>


int main(int argc , char *argv[])
{
	int buffersize=864000;
	char stringg[1000];
	char *p1;
	char *p2;
	char *p3;
	char *p4;
	char *p5;
	char *p6;
	int sct;
	int port=80;
	struct hostent *hosts;
	ssize_t sizes;
	
	struct sockaddr_in srv;
	char *buffer , srv_reply[buffersize];
	
	printf("\e[0;47;34m\n");	
	sct = socket(AF_INET , SOCK_STREAM , 0);
	if (sct == -1)
	{
		printf("Could not create socket");
		return 1;
	}
	
	
	if (argc<1){
		printf("must give a address\n");
		return 1;
	}
	p1=argv[1];
	p4=strstr(p1,"http://");
	if (p4!=NULL){
		p1=p4+7;
	}
	p4=strstr(p1,"HTTP://");
	if (p4!=NULL){
		p1=p4+7;
	}

	
	printf("%s\n",p1);
	p2=strstr(p1,":");
	if(p2!=NULL){
		p3=p2+1;
		port=atoi(p3);
		p2[0]=0;
	}else{
		p3=p1;
	}
	p2=strstr(p3,"/");
	if(p2!=NULL){
		p3=p2+1;
		p2[0]=0;
	}else{
		p3="";
	}
	
	
	
	hosts=gethostbyname(p1);
	bcopy((char *)hosts->h_addr,&srv.sin_addr.s_addr,hosts->h_length);
	//srv.sin_addr.s_addr = inet_addr("127.0.0.1");
	srv.sin_family = AF_INET;
	srv.sin_port = htons( port );

	
	if (connect(sct , (struct sockaddr *)&srv , sizeof(srv)) < 0)
	{
		printf("connect error");
		return 1;
	}
	
	
	
	sprintf(stringg,"GET /%s HTTP/1.1\r\n\r\n",p3);
	buffer =stringg;
	if( send(sct , buffer , strlen(buffer) , 0) < 0)
	{
		printf("Send failed");
		return 1;
	}
	

	do{
		sizes=read(sct, srv_reply , buffersize) ;
		if(sizes>1) printf("%s\n",srv_reply);
	}while(sizes>1);

	close(sct);
	return 0;
}
