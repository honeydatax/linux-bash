#include "graficx.h"
	
int main(int argc, char ** argv){
char a=0;
int mm=0;
int m1=0;
int center=300;
int scenter=1;
int w=0;
long l;
long ll5=0;
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
int i1=40,i2=40,i3=10,i4=10,i5=0,i6,i7,i8,i9,i10,i11,i12;
char cmpere[50];


startX();
char kl[]="im love marina.";
char *kll=kl;
caption(kll);

control c;
c.x=4;
c.y=4;
c.w=500;
c.h=250;
int color=BLACK;
centerControl (&c,600,350);
grid (c,20,color);



int len;
textBar tl;
tl.c.x=4;
tl.c.y=4;
tl.c.w=600-8;
tl.c.h=16;
tl.color=WHITE;
tl.bcolor=BLUE;


do{
getDates(tl.caption);
len=strlen(tl.caption);
tl.caption[len-1]=0;
drawTitle(tl);
refresh();
do{
a=doEvents();
i1=0;
getDates(tl.caption);
i1=0;
if (strcmp(cmpere,tl.caption)!=0)i1=1;
}while(i1!=1);
i1=0;
if (a==27)i1=1;
}while(i1!=1);




return 0;
}


























