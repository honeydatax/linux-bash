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


startX();
cls(YELLOW);
clear();
line(50,50,550,50,BLACK);
line(50,100,550,100,MAGENTA);
line(50,50,50,100,BLUE);
line(550,50,550,100,GREEN);
line(50,50,549,100,BROWN);
line(50,100,549,50,RED);
char cx[1024];
char *kll;
kll=cx;
strcpy(cx,"im love marina.\0");
gputs(75,125,RED,kll);
verputs(10,10,BLUE,kll);
boxs(350,150,550,200,RED);
boxs(200,130,300,230,BLACK);
ball(250,180,50,GREEN);
for (fd1=10;fd1<51;fd1=fd1+10) circle(100,190,fd1,YELLOW);
refresh();
caption(kll);



LOOPS();

return 0;
}


























