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
char kl[]="im love marina.";
char *kll=kl;


int len;
label tl;
strcpy(tl.caption,kll);
len=(strlen(tl.caption)+1)*9;
tl.c.x=4;
tl.c.y=4;
tl.c.w=len;
tl.c.h=16;
tl.color=BLUE;
drawLabel(tl);

char img1[(tl.c.w+1)*(tl.c.h+1)];

copyImage(tl.c.x,tl.c.y,tl.c.w,tl.c.h,&img1[0]);
putImage(tl.c.x+10+tl.c.w,tl.c.y,tl.c.w,tl.c.h,&img1[0]);



refresh();
caption(kll);



LOOPS();

return 0;
}


























