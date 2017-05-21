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
int i1=15,i2=40,i3=10,i4=10,i5=0,i6,i7,i8,i9,i10,i11,i12;
long cmpere;


startX();
char kl[]="im love marina.";
char *kll=kl;
caption(kll);
long caption;
i3=5;	
i4=300;
do{
outSide(i2);
line(i4,i2,i4,349,BLUE);
line(i4,i2,i4-200,349,BLUE);
line(i4,i2,i4+200,349,BLUE);
refresh();
if (i4>400)i3=-5;
if (i4<200)i3=5;
i4=i4+i3;
cmpere=getSeconds();
do{
a=doEvents();
i1=0;
caption=getSeconds();
i1=0;
if (cmpere!= caption || a==27)i1=1;
}while(i1!=1);
i1=0;
if (i2>300)i1=1;
if (a==27)i1=1;
}while(i1!=1);




return 0;
}


























