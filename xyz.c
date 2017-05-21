#include "graficx.h"
	
int main(int argc, char ** argv){
char a=0;
int x=0,y=0,z=0,xx=0,yy=0,rr=0;
long captions=0,cmpere=0;
int i1=0,i2=30,i3=0,i4=0;

startX();
char kl[]="im love marina.";
char *kll=kl;
caption(kll);



do{
outSide(i2);
getxyz(x,y,z,&xx,&yy,&rr,3);
ball (xx,yy,rr,BLUE);
refresh();
x++;
if (x>7){
x=0;
y++;
}
if (y>7){
y=0;
z++;
}
if(z>7)a=27;
cmpere=getSeconds();
do{
a=doEvents();
i1=0;
captions=getSeconds();
i1=0;
if (cmpere!= captions || a==27)i1=1;
}while(i1!=1);
i1=0;
if (i2>300)i1=1;
if (a==27)i1=1;
}while(i1!=1);




return 0;
}


























