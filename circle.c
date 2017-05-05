#include "graficx.h"
#include <math.h>

#define PI 3.1415927


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
long double ddddd=0.0,d1=0.0,dd1=0,d=0.0,dd=0.0,ddd=0.0,pi=(long double)PI;
int x=1,y=1,bc=0,c=7,x1=0,y1=0;



startX();
char cx[1024];
char *kll;
kll=cx;
strcpy(cx,"im love marina.\0");


for (ddd=0.0;ddd<37.0;ddd++){
dd=150.0-100.0*(cos)(ddd/(36/2)*pi);
d=150.0+100.0*(sin)(ddd/(36/2)*pi);
ddddd=ddd+1.0;
if (ddddd==37.0)ddddd=0;
dd1=150.0-100.0*(cos)(ddddd/(36/2)*pi);
d1=150.0+100.0*(sin)(ddddd/(36/2)*pi);
bc=(int)ddd;
x=(int)d;
y=(int)dd;
x1=(int)d1;
y1=(int)dd1;
line(x,y,x1,y1,BLUE);
}


refresh();
caption(kll);



LOOPS();

return 0;
}


























