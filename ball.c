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
sss=SDL_SetVideoMode(640,480,8,0);
rrr[0] = {0 ,0 ,639 ,479 };
SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));
rrr[2].x = i1-20;
rrr[2].y = i2-30;
rrr[2].w = 40;
rrr[2].h = 10;

rrr[1].x = i1-30;
rrr[1].y = i2-20;
rrr[1].w = 60;
rrr[1].h = 40;



rrr[3].y = i1-20;
rrr[3].x = i2+30;
rrr[3].w = 40;
rrr[3].h = 10;



SDL_FillRect(sss,&rrr[1],SDL_MapRGB(sss->format,0,0,255));
SDL_FillRect(sss,&rrr[2],SDL_MapRGB(sss->format,0,0,255));
SDL_FillRect(sss,&rrr[3],SDL_MapRGB(sss->format,0,0,255));
SDL_UpdateRects(sss,4,rrr);
SDL_WM_SetCaption("jumping ball",NULL);



do{


if(SDL_PollEvent(&event)){
if(event.type==SDL_KEYDOWN){
if(event.key.keysym.sym==SDLK_ESCAPE) a=27; 

}
else if (event.type==SDL_QUIT){
a=27;
}
}


rrr[2].x = i1-20;
rrr[2].y = i2-30;

rrr[1].x = i1-30;
rrr[1].y = i2-20;

rrr[3].x = i1-20;
rrr[3].y = i2+20;

SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));
SDL_FillRect(sss,&rrr[1],SDL_MapRGB(sss->format,0,0,255));
SDL_FillRect(sss,&rrr[2],SDL_MapRGB(sss->format,0,0,255));
SDL_FillRect(sss,&rrr[3],SDL_MapRGB(sss->format,0,0,255));
SDL_UpdateRects(sss,4,rrr);

i1=i1+i3;
i2=i2+i4;
if (i2>400)i4=-10;
if (i1>600)i3=-10;
if (i2<40)i4=10;
if (i1<40)i3=10;

usleep (19000l);
}while(a!=27);


return 0;
}













