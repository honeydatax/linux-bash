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

int main(){
int lens=15;
int ll[lens];
int *ll1=&ll[0];
int *lll[lens];
srandom(time(NULL));
for (int a=0;a<lens;a++)ll[a]=nnumber(49)+1;
order(lens,ll1,lll);
lens=nremover(lens,lll);
for (int a=0;a<lens;a++)printf ("%d = %d\n",a,lll[a]);
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













