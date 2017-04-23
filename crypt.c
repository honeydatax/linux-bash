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
char k=0;
char str[250];
int w=0;
long l=0;
long lll=0;
int counter=0;
char ccc[1024*12];
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
char *e=argv[1];
char *c=argv[2];
char *d=argv[3];
if (argc<2){ 
printf("-c [file.txt] [file.dat]   cript\n -d [file.dat] [file.txt] decript\n");
exit(1);
}

if (e[0] == '-' ){
printf ("password to cript file: ");
su=fgets(str,249,stdin);
if ( e[1] == 'c'){

fd2=open(d,O_WRONLY|O_CREAT); 
fd1=open(c,O_RDONLY|O_NONBLOCK); 
l=read(fd1,&ccc,12*1024);
close(fd1);
if (l>2){
i1=0;
i2=0;
do{
ccc[i1]=ccc[i1]+su[i2];
i2++;
if (i2>=12*1024-1)i2=0;
if (su[i2]==10)i2=0;
if (su[i2]==13)i2=0;
if (su[i2]==0)i2=0;
i1++;
}while(l-1!=i1);
}
write(fd2,&ccc,l);
close(fd2);

chmod (d,0666); 
}
if ( e[1] == 'd'){

fd2=open(d,O_WRONLY|O_CREAT); 
fd1=open(c,O_RDONLY|O_NONBLOCK); 
l=read(fd1,&ccc,12*1024);
close(fd1);
if (l>2){
i1=0;
i2=0;
do{
ccc[i1]=ccc[i1]-su[i2];
i2++;
if (i2>=12*1024-1)i2=0;
if (su[i2]==10)i2=0;
if (su[i2]==13)i2=0;
if (su[i2]==0)i2=0;
i1++;
}while(l-1!=i1);
}
write(fd2,&ccc,l);
close(fd2);

chmod (d,0666); 
}



}
return 0;
}













