#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char ** argv){
FILE *ffa;
int w=0;
long l;
int counter=0;
char ccc=0;
char cc[100];
int fd1=0;
int fd2=0;
int fff=0;
char *s1;
char *s2;
int t=0;
long ll=0;
int i1=0,i2=0,i3=0,i4=0,i5=0;
char *c=argv[1];
char *d=argv[2];
printf("#%s=%s#",c,d);
if (argc<2) exit(1);
fd1=open(c,O_WRONLY|O_NONBLOCK); 
fd2=open(d,O_RDONLY|O_NONBLOCK); 
do{
counter=0;
do{
l=read(fd2,&ccc,1);
if (l==1){
cc[counter]=ccc;
counter++;
}
}
while(ccc!='\n');
cc[counter-1]=0;
s1=&cc[1];
if (cc[0]=='s')for (i1=0;i1<50;i1++)printf("\n");


if (cc[0]=='c'){
sscanf(s1,"%i %i",&i1,&i2);
i1=i1+30;
i2=i2+40;
printf("\e[0;%d;%dm",i1,i2);
}
if (cc[0]=='g'){
sscanf(s1,"%i %i",&i1,&i2);
printf("\e[%d;%df",i1,i2);
}

if(cc[0]=='p')printf("%s\n",s1);
if (cc[0]=='e')fff=1;
}while(fff!=1);
write(fd1,"e\n",2);
close(fd1);
close(fd2);

return 0;
}













