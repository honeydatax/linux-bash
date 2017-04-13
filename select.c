#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

void item(char *strs);

int main(int argc, char ** argv){
int a=0,i=0,n=0;
char *c=" ";
char *d="select";
char *e="cancel";
int nn=0;
int nnn=0;
int cy=0;
int ccy=0;
struct termios oldt,newt;
tcgetattr(fileno(stdin),&oldt);
memcpy(&newt,&oldt,sizeof(struct termios));
newt.c_lflag &= ~(ECHO|ICANON);
newt.c_cc[VTIME]=0;
newt.c_cc[VMIN]=0;
tcsetattr(fileno(stdin),TCSANOW,&newt);



for(i=0;i<26;i++)printf ("\n");

do{
printf("\e[1;1f\e[0;40;37m");
a=0;
item (c);
item (d);
printf("%d ",a);
item (e);
a++;
for(i=1;i<argc;i++){
printf("%d ",a);
item (argv[i]);
a++;
}
nnn=nn+3;
printf("\e[%i;1f\e[0;47;30m",nnn);
printf("%d ",nn);
if (nn==0)item ("cancel");
else item (argv[nn]);
cy=argc+3;
printf("\e[%i;1f\e[0;40;37m",cy);
do{
ccy=getc(stdin);
}while(ccy==-1);
if (ccy==65)nn--;
if (ccy==66)nn++;
if (nn<0)nn=0;
if (nn>argc-1)nn=argc-1; 
}while(ccy!=10);

oldt.c_lflag|=ECHO|ICANON;
tcsetattr(fileno(stdin),TCSANOW,&oldt);


return nn;
}

void item(char *strs){
printf("%s\n",strs); 
}













