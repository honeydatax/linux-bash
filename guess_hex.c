#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>

void order(int c,int *l,int **ll);
void dorder(int c,int *l,int **ll);
int nnumber(int n);
int nremover(int c,int **ll);
void phelp();

int main(){
int nnnn=0;
int nnn=0;
int nn=0;
int c=0;
int b=0;
int lens=15;
int ll[1500];
int *ll1=&ll[0];
int *lll[1500];
srandom(time(NULL));
nn=nnumber(254);
nnn=0;
system("clear");
printf("game gess a number\n");
do{
phelp();
printf("gess a number from 0 to 255?%x h  -1 to exit or give up\n",nn);
scanf("%d",&b);
ll[c]=b;
c++;
printf("\nthe number you digit is %x h \n",b);
if(b==nn)nnn++;
if(b<0)nnn++;
if(b>100)nnn++;
if(c>1498)nnn++;
}while(nnn==0);
order(c,ll1,lll);
system("clear");
for (int a=0;a<c;a++)printf ("%d = %d\n",ll[a],lll[a]);
if (b==nn)printf("you win = %d  try = %d\n",nn,c);
if (b!=nn)printf("you lost = %d  try = %d\n",nn,c);
return 0;
}


void order(int c,int *l,int **ll){
int *d1,*d2,*d3,d4;
if (c>0){
for (int a=0;a<c;a++){
if (a>0){
d3=(int *) l[a];
for (int b=0;b<a;b++){
d1=ll[b];
d2=d3;
if (d1>d2){
ll[b]=d2;
d3=d1;
}

}
ll[a]=d3;
}else ll[0]=(int *)l[0];
}
}else ll[0]=(int *)l[0];
}


void dorder(int c,int *l,int **ll){
int *d1,*d2,*d3,d4;
if (c>0){
for (int a=0;a<c;a++){
if (a>0){
d3=(int *) l[a];
for (int b=0;b<a;b++){
d1=ll[b];
d2=d3;
if (d1<d2){
ll[b]=d2;
d3=d1;
}

}
ll[a]=d3;
}else ll[0]=(int *)l[0];
}
}else ll[0]=(int *)l[0];
}


int nnumber(int n){
int nnn=RAND_MAX/n;
int nn=random()/nnn;
return nn;
}


int nremover(int c,int **ll){
int *d1,*d2,*d3,*d4;
int rrnn=c;
int cc=0;
int back=-1;
int ccc=0;
for (int a=0;a<rrnn;a++){
if(back==(int)ll[a]){
if(a<rrnn){
rrnn--;
for (int b=a;b<rrnn;b++)ll[b]=ll[b+1];
}
}else back=(int)ll[a];
}
return rrnn;
}


void phelp(){
int i=0;
int cc=0;
char c[]="0123456789ABCDEF";
int x=0;
for (i=0;i<16;i++){
x=i*16;
printf("%c0h=%d\t",c[i & 15],x);
cc++;
if(cc==4){
cc=0;
printf("\n");
}
}
}











