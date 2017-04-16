#include <stdio.h>
#include <termios.h>
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
int w=0;
long l=0;
long lll=0;
int counter=0;
char ccc[2050];
int fd1=0;
int fd2=0;
int fff=0;
char a;
char *su;
char *s3;
char *s1;
char *s2;
int t=0;
long ll=0;
int i1=0,i2=0,i3=0,i4=0,i5=0,i6,i7,i8,i9,i10,i11,i12;
char *c=argv[1];
char *d=argv[2];
if (argc<2) exit(1);

fd1=open(d,O_WRONLY|O_CREAT); 
fd2=open(c,O_RDONLY|O_NONBLOCK); 
l=read(fd2,&ccc,2048);
close(fd2);
if (l>2){
ccc[l]=0;
ll=0;
do{
s1=&ccc[ll];
if (ccc[ll]>='0' && ccc[ll]<='9'){
sscanf(s1,"%i",&i1);
a=i1;
}else{
a=ccc[ll];
}
lll=write(fd1,&a,1);
i3=0;
do{
if(ccc[ll]==32 || ccc[ll]==0 || ll>=l)i3=1;
ll++;
}while(i3!=1);
i3=0;
if(ccc[ll]==0 || ll>=l)i3=1;
}while(i3!=1);
}

close(fd1);

chmod (d,0666); 

return 0;
}













