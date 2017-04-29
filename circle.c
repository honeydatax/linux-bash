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

#define PI 3.1415927


int xx=1;
int yy=1;
int color=7;
int bcolor=0;
void setbcolor(int c);
void setcolor(int c);
void clear();
void setx(int x);
void sety(int y);
void gotoxy(int x,int y);
void cls();

int main(){
long double d=0.0,dd=0.0,ddd=0.0,pi=(long double)PI;
int x=1,y=1,bc=0,c=7;
cls();
clear();
setbcolor(7);
setcolor(0);
for (ddd=1.0;ddd<13.0;ddd++){
dd=10.0-10.0*(cos)(ddd/6*pi);
d=40.0+15.0*(sin)(ddd/6*pi);
bc=(int)ddd;
x=(int)d;
y=(int)dd;
gotoxy(x,y);
printf("%d",bc); 
}
gotoxy(1,1);
usleep(8000000);
return 0;
}


void setx(int x){
xx=x;
}


void sety(int y){
yy=y;
}

void gotoxy(int x,int y)
{
printf("\e[%d;%df",y,x);
}

void clear(){
int n;
for(n=0;n<26;n++){
printf("\n");
}
gotoxy(1,1);
}

void setcolor(int c){
int cc;
cc=c+30;
color=c;
printf("\e[%dm",cc);
}

void setbcolor(int c){
int cc;
cc=c+40;
bcolor=c;
printf("\e[%dm",cc);
}


void cls(){
printf("\033c");
}




























