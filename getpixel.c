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


boxs(100,2,200,102,BLUE);

i1=gpixel(300,2);
printf("%d\n",i1);
i1=gpixel(-1,2);
printf("%d\n",i1);
i1=gpixel(150,50);
printf("%d\n",i1);



refresh();
caption(kll);



LOOPS();

return 0;
}


























