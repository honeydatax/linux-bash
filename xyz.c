#include <SDL/SDL.h>
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

#define rsize 8

SDL_Rect rrr[8];
time_t rawtime;
struct tm *timeinfo;
struct timeval start, ends;

void draw(int x, int y,int s);
void getxyz(int x,int y, int z,int *getx,int *gety,int *getsizess);


int main(int argc, char ** argv){
int xx=0, yy=0,zz=0;
int xxx=0,yyy=0,ssss=0;
char a=0;
int mm=0;
int m1=0;
SDL_Surface *sss;
SDL_Surface *iiii;
SDL_Event event;
int center=300;
int scenter=1;
int w=0;
long l;
long ll5=0;
int counter=0;
char ccc=0;
char cc[100];
int fd1=0;
int fd2=0;
int fff=0;
char *s1;
char *s2;
int t=0;
long ll=0;
int i1=40,i2=40,i3=10,i4=10,i5=0,i6,i7,i8,i9,i10,i11,i12;

SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
atexit(SDL_Quit);
sss=SDL_SetVideoMode(600,350,8,0);
rrr[0] = {0 ,0 ,599 ,2 };
SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));
rrr[1].x = 0;
rrr[1].y = 40;
rrr[1].w = 599;
rrr[1].h = 310;



rrr[2].x = 0;
rrr[2].y = 2;
rrr[2].w = 599;
rrr[2].h = 40;

rrr[3].x = 0;
rrr[3].y = 0;
rrr[3].w = 30;
rrr[3].h = 60;

rrr[4].x = 0;
rrr[4].y = 0;
rrr[4].w = 60;
rrr[4].h = 30;



SDL_FillRect(sss,&rrr[1],SDL_MapRGB(sss->format,150,50,0));
SDL_FillRect(sss,&rrr[2],SDL_MapRGB(sss->format,0,255,255));
SDL_UpdateRects(sss,3,rrr);

SDL_WM_SetCaption("xyz",NULL);



do{


if(SDL_PollEvent(&event)){
if(event.type==SDL_KEYDOWN){
if(event.key.keysym.sym==SDLK_ESCAPE) a=27; 

}
else if (event.type==SDL_QUIT){
a=27;
}
}
getxyz(xx,yy,zz,&xxx,&yyy,&ssss);
draw(xxx,yyy,ssss);
SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));
SDL_FillRect(sss,&rrr[1],SDL_MapRGB(sss->format,150,50,0));
SDL_FillRect(sss,&rrr[2],SDL_MapRGB(sss->format,0,255,255));
SDL_FillRect(sss,&rrr[3],SDL_MapRGB(sss->format,0,0,255));
SDL_FillRect(sss,&rrr[4],SDL_MapRGB(sss->format,0,0,255));
SDL_UpdateRects(sss,5,rrr);
SDL_Flip(sss);

usleep (190000l);
xx++;
if (xx>7){
xx=0;
yy++;
}
if (yy>7){
yy=0;
zz++;
}
if (zz>7)zz=0;
if (zz==6 || a==27)i1=1;
}while(i1!=1);


return 0;
}


void draw(int x, int y,int s){

rrr[3].w = s/2;
rrr[3].h = s;
rrr[3].x = x-rrr[3].w/2 ;
rrr[3].y = y-rrr[3].h/2;


rrr[4].w = s;
rrr[4].h = s/2;
rrr[4].x = x-rrr[4].w/2;
rrr[4].y = y-rrr[4].h/2;
}

void getxyz(int x,int y, int z,int *getx,int *gety,int *getsizess){
x=8-x;
y=8-y;
z=8-z;
int a12=600/2;
int b12=350/2;
*getsizess=y*rsize;
*getx=a12+(*getsizess)*(x-4);
*gety=b12+(*getsizess)*(y-4);
}

























