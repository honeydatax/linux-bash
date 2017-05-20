#include "graficx.h"

void onClicks(int index);

	
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
int i=0;

startX();
char kl[100]="im love marina.";
char *kll=kl;
caption(kll);
int len;

control c;

caption(kll);
c.x=4;
c.y=4;
c.w=500;
c.h=250;
int color=BLUE;
centerControl (&c,600,350);
grid (c,5,color);


mainMenu[0].c.y=4;
mainMenu[i].c.x=4;
for (i=0;i<10;i++){
strcpy(mainMenu[i].caption,kll);
len=textW(mainMenu[i].caption)+8;
mainMenu[i].c.w=len;
mainMenu[i].c.h=16;
mainMenu[i].color=BLUE;
mainMenu[i].onClick=&onClicks;
strcat(kll,".");
}

menuWait(10);

usleep(5000000);
}

	
void onClicks(int index){
char s[30];
sprintf(s,"index:%d",index);
caption (s);
}

























