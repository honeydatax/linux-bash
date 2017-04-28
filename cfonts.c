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
char cx[1024];
char *kll;
kll=cx;
strcpy(cx,"im love marina.\0");
gputs(75,150,RED,kll);
verputs(10,10,BLUE,kll);
boxs(175,50,250,100,YELLOW);
boxs(75,50,150,100,YELLOW);
boxs(320,50,395,100,YELLOW);
boxs(420,50,495,100,YELLOW);
boxs(420+36,74,495-36,76,RED);
line(420+37,75,495,50,RED);
line(420+37,75,495,100,GREEN);
line(420+37,75,420,100,BLUE);
line(420+37,75,420,50,DARKGRAY);
line(395,100,320,50,0);
line(395,50,320,100,0);

for(i1=80;i1<151;i1=i1+10){
line(75,50,i1,100,0);
}
for(i1=175;i1<251;i1=i1+10){
line(175,100,i1,50,0);
}

rectangle(275,50,310,100,RED);

refresh();
caption(kll);



LOOPS();

return 0;
}


























