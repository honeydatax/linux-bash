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


void ppixel(SDL_Surface *s,int x,int y,char color);
void hline(SDL_Surface *s,int x,int y,int x2,char color);
void vline(SDL_Surface *s,int x,int y,int y2,char color);


time_t rawtime;
struct tm *timeinfo;
struct timeval start, ends;



int main(int argc, char ** argv){
char a=0;
int mm=0;
int m1=0;
SDL_Rect rrr[8];
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
rrr[0] = {0 ,0 ,599 ,349 };
SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));


SDL_UpdateRects(sss,1,rrr);
ppixel(sss,(550-50)/2+50,75,0);
hline(sss,50,50,550,0);
hline(sss,50,100,550,0);
vline(sss,50,50,100,0);
vline(sss,550,50,100,0);
SDL_Flip(sss);
SDL_WM_SetCaption("pixel",NULL);



do{


if(SDL_PollEvent(&event)){
if(event.type==SDL_KEYDOWN){
if(event.key.keysym.sym==SDLK_ESCAPE) a=27; 

}
else if (event.type==SDL_QUIT){
a=27;
}
}

i1=0;
if (a==27)i1=1;
}while(i1!=1);


return 0;
}


void ppixel(SDL_Surface *s,int x,int y,char color){
Uint8 *p=(Uint8*)s->pixels+y*s->pitch+x;
*(Uint8 *)p=color;
} 


void hline(SDL_Surface *s,int x,int y,int x2,char color){
int f;
int xx1=x;
int xx2=x2;
int xx3=x;
if(xx2<xx1){
xx1=xx2;
xx2=xx3;
}
for(f=xx1;f<xx2;f++){
Uint8 *p=(Uint8*)s->pixels+y*s->pitch+f;
*(Uint8 *)p=color;
}

} 

void vline(SDL_Surface *s,int x,int y,int y2,char color){
int f;
int yy1=y;
int yy2=y2;
int yy3=y;
if(yy2<yy1){
yy1=yy2;
yy2=yy3;
}
for(f=yy1;f<yy2;f++){
Uint8 *p=(Uint8*)s->pixels+f*s->pitch+x;
*(Uint8 *)p=color;
}

} 















