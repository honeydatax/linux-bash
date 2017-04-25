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

startX();
hline(50,50,550,0);
hline(50,100,550,0);
vline(50,50,100,0);
vline(550,50,100,0);
lineRight(50,50,549,100,0);
lineLeft(50,100,549,50,0);
char cx[1024];
char *kll;
kll=cx;
strcpy(cx,"im love marina.\0");
gputs(75,125,0,kll);
verputs(10,10,0,kll);
refresh();
caption(kll);



do{


a=doEvents();
i1=0;
if (a==27)i1=1;
}while(i1!=1);


return 0;
}


























