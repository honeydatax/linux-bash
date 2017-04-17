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
SDL_Surface *s;
SDL_Surface *i,*ii;
SDL_Rect ir;

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
int i1=40,i2=40,i3=1,i4=1,i5=0,i6,i7,i8,i9,i10,i11,i12;
SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
atexit(SDL_Quit);
sss=SDL_SetVideoMode(600,350,8,0);
i=SDL_LoadBMP("photo.bmp");
ii=SDL_DisplayFormat(i);
SDL_FreeSurface(i);
rrr[0] = {0 ,0 ,599 ,349 };
SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));
rrr[1].x = i1-30;
rrr[1].y = i2-20;
rrr[1].w = ii->w;
rrr[1].h = ii->h;






SDL_FillRect(sss,&rrr[1],SDL_MapRGB(sss->format,255,255,255));
SDL_UpdateRects(sss,2,rrr);
SDL_WM_SetCaption("marina",NULL);



do{


if(SDL_PollEvent(&event)){
if(event.type==SDL_KEYDOWN){
if(event.key.keysym.sym==SDLK_ESCAPE) a=27; 

}
else if (event.type==SDL_QUIT){
a=27;
}
}


rrr[1].x = i1-30;
rrr[1].y = i2-20;


SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));
SDL_BlitSurface(ii,NULL,sss,&rrr[1]);
SDL_UpdateRects(sss,2,rrr);

i1=i1+i3;
i2=i2+i4;
if (i2>300)i4=-1;
if (i1>570)i3=-1;
if (i2<40)i4=1;
if (i1<40)i3=1;

usleep (20000l);
}while(a!=27);
SDL_FreeSurface(ii);

return 0;
}













