#include "graficx.h"

int b=0;

void onClicks();

	
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
char kl[]="im love marina.";
char *kll=kl;

control c;
int len;
caption(kll);
c.x=4;
c.y=4;
c.w=500;
c.h=250;
int color=BLUE;
centerControl (&c,600,350);
grid (c,5,color);
messageBox(kll,BLUE,&onClicks);

usleep(5000000);

do{

}while(b!=1);

return 0;
}

	
void onClicks(){
b=1;
}

























