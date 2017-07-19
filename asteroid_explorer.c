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
void report(char *s,int ttime);
int supers(int value,int d);

int main(){
char ccolors[4][30]={"buy asteroid AA","buy asteroid BB","buy asteroid CC","buy asteroid DD"};
char mmcolors[2][50]={"pay maintenance expense $150.00","recives $200.00"};
char oocolors[4][30]={" asteroid AA"," asteroid BB"," asteroid CC"," asteroid DD"};
char maps[]{0,0,0,1,5,0,0,0,0,2,6,0,0,0,0,0,3,5,0,0,0,0,0,4,6,0,0,0,0,0,0,0,0,0,0,0,0};
int currencys=160;
char bbase[4];
char retss=0;
char a[100];
char s1[100];
char *s2=&s1[0];
int nn=0;
int nnn=0;
int ppos=0;
bbase[0]=0;
bbase[1]=0;
bbase[2]=0;
bbase[3]=0;
srandom(time(NULL));
nnn=0;
strcpy(a," ");
system("clear");
printf("game moon base\n");
do{
nn=nnumber(5)+1;
ppos=ppos+nn;
ppos=supers(ppos,32);
nn=maps[ppos];

if (nn==1){
if (bbase[0]==0){
sprintf(s2,"$%d.00  titles:%s \n %s y,n?\n",currencys,a,ccolors[0]);
retss=asks(s2);
if (retss==1){
currencys=currencys-150;
bbase[0]=1;
strcat(a,oocolors[0]);
}
}
}

if (nn==2){
if (bbase[1]==0){
sprintf(s2,"$%d.00  titles:%s \n %s y,n?\n",currencys,a,ccolors[1]);
retss=asks(s2);
if (retss==1){
currencys=currencys-150;
bbase[1]=1;
strcat(a,oocolors[1]);
}
}
}

if (nn==3){
if (bbase[2]==0){
sprintf(s2,"$%d.00  titles:%s \n %s y,n?\n",currencys,a,ccolors[2]);
retss=asks(s2);
if (retss==1){
currencys=currencys-150;
bbase[2]=1;
strcat(a,oocolors[2]);
}
}
}

if (nn==4){
if (bbase[3]==0){
sprintf(s2,"$%d.00  titles:%s \n %s y,n?\n",currencys,a,ccolors[3]);
retss=asks(s2);
if (retss==1){
currencys=currencys-150;
bbase[3]=1;
strcat(a,oocolors[3]);
}
}
}


if (nn==5){
sprintf(s2,"$%d.00  titles:%s \n %s \n",currencys,a,mmcolors[0]);
retss=0;
report(s2,2);
currencys=currencys-150;
}

if (nn==6){
sprintf(s2,"$%d.00  titles:%s \n %s \n",currencys,a,mmcolors[1]);
retss=0;
report(s2,2);
currencys=currencys+200;
}



if (bbase[0]==1 && bbase[1]==1 && bbase[2]==1 && bbase[3]==1 )nnn++;
if(retss>1)nnn++;
if(retss>1)currencys=-1;
if(currencys<1)nnn++;
}while(nnn==0);
system("clear");
if (currencys>0)printf("you win \n");
if (currencys<0)printf("you lost \n");
return 0;
}




int nnumber(int n){
int nnn=RAND_MAX/n;
int nn=random()/nnn;
return nn;
}


void report(char *s,int ttime){
int t=ttime*1000000;
printf("%s\n",s);
usleep(t);
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
int dd=value;
if (dd>d)dd=dd-(d+1);
return dd;
}





































