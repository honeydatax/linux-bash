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

int main(){
int lens=10;
int ll[]={90,60,30,50,40,10,17,8,9,10,11};
int *ll1=&ll[0];
int *lll[lens];
dorder(lens,ll1,lll);
for (int a=0;a<lens;a++)printf ("%d\n",lll[a]);
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





















