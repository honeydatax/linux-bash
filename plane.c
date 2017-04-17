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


void ppixel(SDL_Surface *r1,int x,int y ,Uint32 pixel);

time_t rawtime;
struct tm *timeinfo;
struct timeval start, ends;



int main(int argc, char ** argv){
char a=0;
int mm=0;
int m1=0;
SDL_Rect rrr[8];
SDL_Rect rrr1[300];
SDL_Rect rrr2[300];
SDL_Rect rrr3[300];
SDL_Surface *sss;
SDL_Surface *iiii;
SDL_Event event;
Uint32 pixel;
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
rrr[0] = {0 ,0 ,599 ,10 };
SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));
rrr[1].x = 0;
rrr[1].y = 110;
rrr[1].w = 599;
rrr[1].h = 240;



rrr[2].x = 0;
rrr[2].y = 10;
rrr[2].w = 599;
rrr[2].h = 100;


SDL_FillRect(sss,&rrr[1],SDL_MapRGB(sss->format,150,50,0));
SDL_FillRect(sss,&rrr[2],SDL_MapRGB(sss->format,0,255,255));

SDL_UpdateRects(sss,3,rrr);

SDL_WM_SetCaption("plane",NULL);



do{


if(SDL_PollEvent(&event)){
if(event.type==SDL_KEYDOWN){
if(event.key.keysym.sym==SDLK_ESCAPE) a=27; 

}
else if (event.type==SDL_QUIT){
a=27;
}
}

rrr[1].y++;
rrr[1].h--;



rrr[2].h++;


SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));
SDL_FillRect(sss,&rrr[1],SDL_MapRGB(sss->format,150,50,0));
SDL_FillRect(sss,&rrr[2],SDL_MapRGB(sss->format,0,255,255));
SDL_UpdateRects(sss,3,rrr);
i2=300/rrr[1].h;
i3=rrr[1].y;
for(i1=0;i1<299;i1++){
rrr1[i1].x=300-i1;
rrr1[i1].y=i3;
rrr1[i1].w=2;
rrr1[i1].h=2;
rrr2[i1].x=300+i1;
rrr2[i1].y=i3;
rrr2[i1].w=2;
rrr2[i1].h=2;
rrr3[i1].x=300;
rrr3[i1].y=i3;
rrr3[i1].w=2;
rrr3[i1].h=2;

SDL_FillRect(sss,&rrr1[i1],SDL_MapRGB(sss->format,0,0,0));
SDL_FillRect(sss,&rrr2[i1],SDL_MapRGB(sss->format,0,0,0));
SDL_FillRect(sss,&rrr3[i1],SDL_MapRGB(sss->format,0,0,0));
i3=i3+i2;
}
SDL_UpdateRects(sss,299,rrr1);
SDL_UpdateRects(sss,299,rrr2);
SDL_UpdateRects(sss,299,rrr3);
SDL_Flip(sss);
usleep (190000l);
i1=0;
if (rrr[1].h<20 || a==27)i1=1;
}while(i1!=1);


return 0;
}











