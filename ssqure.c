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

int nnumber(int n);
int asks(char *ss);
void report(char *s);
double supers(double value,double d);

int main(){
char retss=0;
double a;
int y=0;
char s1[100];
char *s2=&s1[0];
double nn=0;
int nnn=0;
int ppos=0;
int pppos=0;
double an=0;
double anter=0;
double anter2=0;
srandom(time(NULL));
nn=(double)nnumber(2000)+1;
a=nn;
system("clear");
printf("game squre root aproximete\n");
do{
sprintf(s2,"%lf >> %lf \n",nn,a);
report(s2);
y=(ppos/2)*2;
if(y!=ppos)anter2=a;
if(y==ppos)anter=a;
a=supers(nn,a);
ppos++;
if (a==anter)nnn++;
if (a==anter2)nnn++;
}while(nnn==0);
sprintf(s2,"%lf >> %lf  \n",nn,a);
if(anter>anter2)an=(anter-anter2)/2;
if(anter<anter2)an=(anter2-anter)/2;
if(anter>anter2)an=anter2+an;
if(anter<anter2)an=anter+an;
report(s2);
printf(" v_%lf = %lf\n",nn,an);
return 0;
}




int nnumber(int n){
int nnn=RAND_MAX/n;
int nn=random()/nnn;
return nn;
}


void report(char *s){
printf("%s",s);
}




double supers(double value,double d){
double dd=value/(1.00+d);
return dd;
}





































