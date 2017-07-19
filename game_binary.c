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
int supers(int value,int d);

int main(){
char retss=0;
int a;
int bi[]{0,0,0,0,0,0,0,0,0,0,0,0};
char s1[100];
char *s2=&s1[0];
int nn=0;
int nnn=0;
int ppos=128;
int pppos=7;
srandom(time(NULL));
nn=nnumber(254);
system("clear");
printf("game binary number base\n");
do{
retss=0;
sprintf(s2,"number %d  subtract %d y,n?\n",nn,ppos);
retss=asks(s2);
if (retss==1){
nn=nn-ppos;
bi[pppos]=1;
}

for (int i=7;i>0;i--){
sprintf(s2,"%d",bi[i]);
report(s2);
}

sprintf(s2,"\n");
report(s2);
pppos--;
ppos=ppos/2;
if(retss>1)nnn++;
if(retss>1)nn=-255;
if(pppos<0)nnn++;
if(nn<0)nnn++;
}while(nnn==0);
system("clear");
if (nn==0)printf("you win \n");
else printf("you lost \n");
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


int asks(char *ss){
char s[8024];
char *sss=&s[0];
int i1=2;
printf("%s\n",ss);
sss=gets(sss);
if(s[0]=='n' || s[0]=='N' )i1=0;
if(s[0]=='y' || s[0]=='Y' )i1=1;
return i1;
}


int supers(int value,int d){
int dd=value-d;
return dd;
}





































