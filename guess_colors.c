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
void strings(char *s,int llen,char t);
int ppass (char *s,char *ss,char t);


int main(){
char ccolors[8][30]={"black","red","orange","yellow","green","cyan","blue","violet"};
char tcolor[30];
char ttcolor[30];
char s[8024];
char *ssss=&tcolor[0];
char *sss=&ttcolor[0];
char *ss=&s[0];
int nnnn=0;
int nnn=0;
unsigned char nn=0;
int c=0;
unsigned char b=0;
int lens=15;
int ll[1500];
int *ll1=&ll[0];
int *lll[1500];
srandom(time(NULL));
nn=nnumber(7);
strcpy(tcolor,ccolors[nn]);
nn=strlen(tcolor);
nnn=0;
strings(sss,nn,'*');
system("clear");
printf("game gess a color\n");
do{
printf("gess a color %s abcdefghijklmnopqrstuvwxyz  enter to give up\n",ttcolor);
ss=gets(ss);
b=s[0];
ll[c]=(int) b;
c++;
nn=nn-ppass(ssss,sss,b);
if(b<'a')nnn++;
if(b>'z')nnn++;
if(nn<1)nnn++;
if(c>1498)nnn++;
}while(nnn==0);
system("clear");
if (nn<1)printf("you win = %s  try = %d\n",tcolor,c);
if (nn>0)printf("you lost = %s  try = %d\n",tcolor,c);
return 0;
}




int nnumber(int n){
int nnn=RAND_MAX/n;
int nn=random()/nnn;
return nn;
}


void strings(char *s,int llen,char t){
for (int a=0;a<llen;a++)s[a]=t;
s[llen]=0;
}


int ppass (char *s,char *ss,char t){
int n=strlen(s);
int nn=0;
for (int a=0;a<n;a++){
if (s[a]==t){
nn++;
ss[a]=t;
}
}
return nn;
}









