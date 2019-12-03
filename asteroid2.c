#include "getss.h"
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



 
int mmain();
int nnumber(int n);
int asks(char *ss);
void report(char *s,int ttime);
int supers(int value,int d);

time_t rawtime;
struct termios oldt,newt;
struct tm *timeinfo;
struct timeval start, ends;
FILE *fp;
int ccc;
char a;
char bbase[4];
int currencys;
int ppos=0;

int main()
{
char ttimes[20];
char toprints[]="\r\0";
currencys=160;
ccc=0;
int s=0;
a=0;
long b=0;
long c=0;
int iii=0;
int xxx=0;
int cc=0;
int tt=0;
int ttt=0;
long counter=0;
srandom(time(NULL));
tcgetattr(fileno(stdin),&oldt);
memcpy(&newt,&oldt,sizeof(struct termios));
newt.c_lflag &= ~(ECHO|ICANON);
newt.c_cc[VTIME]=0;
newt.c_cc[VMIN]=0;
tcsetattr(fileno(stdin),TCSANOW,&newt);


b=0;
printf ("\033c");
printf ("\e[0;30;47m");
for(iii=0;iii<98;iii++){
printf ("                    ");
}

printf ("\e[1;1f\\asteroid the game:key 0 - 3 buy asteroids  press esc to exit");
bbase[0]=0;
bbase[1]=0;
bbase[2]=0;
bbase[3]=0;
do{
counter=0;
a=fgetc(stdin);
mmain();
}while(a!=0x1B); 
oldt.c_lflag|=ECHO|ICANON;
tcsetattr(fileno(stdin),TCSANOW,&oldt);
printf ("\033c");
if (ccc==1)printf("you win \n");
if (ccc!=1)printf("you lost \n");
return 0;
}

int nnumber(int n){
int nnn=RAND_MAX/n;
int nn=random()/nnn;
return nn;
}


void report(char *s,int ttime){
int t=ttime*1000000;
usleep(t);
}


int asks(char *ss){
char s[8024];
char *sss=&s[0];
int i1=2;
return i1;
}


int supers(int value,int d){
int dd=value;
if (dd>d)dd=dd-(d+1);
return dd;
}

int mmain(){
char ccolors[4][30]={"buy asteroid AA","buy asteroid BB","buy asteroid CC","buy asteroid DD"};
char mmcolors[2][50]={"pay maintenance expense $150.00","recives $200.00"};
char oocolors[4][30]={" asteroid AA"," asteroid BB"," asteroid CC"," asteroid DD"};
char maps[]{0,0,0,1,5,0,0,0,0,2,6,0,0,0,0,0,3,5,0,0,0,0,0,4,6,0,0,0,0,0,0,0,0,0,0,0,0};

char retss=0;
char s1[100];
char *s2=&s1[0];
int nn=0;
int nnn=0;
nnn=0;

nn=nnumber(5)+1;
ppos=ppos+nn;
ppos=supers(ppos,32);
nn=maps[ppos];

if (a=='0'){
if (bbase[0]==0){
currencys=currencys-150;
bbase[0]=1;
printf("\e[3;1f\e[0;30;47m");
printf("$%d.00           ",currencys);
printf("\e[4;1f\e[0;30;47m");
printf("%s               ",ccolors[0]);
report(ccolors[0],2);
}
}

if (a=='1'){
if (bbase[1]==0){
currencys=currencys-150;
bbase[1]=1;
printf("\e[3;1f\e[0;30;47m");
printf("$%d.00           ",currencys);
printf("\e[5;1f\e[0;30;47m");
printf("%s               ",ccolors[1]);
report(ccolors[0],2);
}
}

if (a=='2'){
if (bbase[2]==0){
currencys=currencys-150;
bbase[2]=1;
printf("\e[3;1f\e[0;30;47m");
printf("$%d.00           ",currencys);
printf("\e[6;1f\e[0;30;47m");
printf("%s               ",ccolors[2]);
report(ccolors[0],2);
}
}

if (a=='3'){
if (bbase[3]==0){
currencys=currencys-150;
bbase[3]=1;
printf("\e[3;1f\e[0;30;47m");
printf("$%d.00           ",currencys);
printf("\e[7;1f\e[0;30;47m");
printf("%s               ",ccolors[3]);
report(ccolors[0],2);
}
}


if (nn==5){
currencys=currencys+200;
printf("\e[3;1f\e[0;30;47m");
printf("$%d.00           ",currencys);
printf("\e[10;1f\e[0;30;47m");
printf("%s               ",mmcolors[1]);
report(ccolors[0],2);
}


if (nn==6){
currencys=currencys-150;
printf("\e[3;1f\e[0;30;47m");
printf("$%d.00           ",currencys);
printf("\e[11;1f\e[0;30;47m");
printf("%s               ",mmcolors[0]);
report(ccolors[0],2);
}

if (currencys<0)a=0x1B;

if (bbase[0]==1 && bbase[1]==1 && bbase[2]==1 && bbase[3]==1 ){
ccc=1;
a=0x1B;
}
return 0;
}



