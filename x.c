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
char h[250];
char a=0;
int mm=0;
int m1=0;
SDL_Rect rrr[1000];
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
sss=SDL_SetVideoMode(600,300,8,0);
rrr[0] = {0 ,0 ,599 ,299 };
SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));
for (i4=1;i4<300;i4++){
i1=i4*2;
i2=i4*2;
rrr[i1].x=i2;
rrr[i1].y=i4;
rrr[i1].w=1;
rrr[i1].h=1;
i3=600-i2;
rrr[i1+1].x=i3;
rrr[i1+1].y=i4;
rrr[i1+1].w=1;
rrr[i1+1].h=1;

SDL_FillRect(sss,&rrr[i1],SDL_MapRGB(sss->format,0,0,0));
SDL_FillRect(sss,&rrr[i1+1],SDL_MapRGB(sss->format,0,0,0));
}
rrr[600].x=50;
rrr[600].y=50;
rrr[600].w=30;
rrr[600].h=200;
SDL_FillRect(sss,&rrr[600],SDL_MapRGB(sss->format,100,0,0));
rrr[601].x=600-50;
rrr[601].y=50;
rrr[601].w=30;
rrr[601].h=200;
SDL_FillRect(sss,&rrr[601],SDL_MapRGB(sss->format,101,0,0));
rrr[602].x=600-90;
rrr[602].y=80;
rrr[602].w=29;
rrr[602].h=150;
SDL_FillRect(sss,&rrr[602],SDL_MapRGB(sss->format,99,0,0));
rrr[603].x=600-130;
rrr[603].y=100;
rrr[603].w=27;
rrr[603].h=110;
SDL_FillRect(sss,&rrr[603],SDL_MapRGB(sss->format,98,0,0));
rrr[604].x=600-165;
rrr[604].y=110;
rrr[604].w=25;
rrr[604].h=90;
SDL_FillRect(sss,&rrr[604],SDL_MapRGB(sss->format,97,0,0));
rrr[605].x=600-200;
rrr[605].y=120;
rrr[605].w=22;
rrr[605].h=70;
SDL_FillRect(sss,&rrr[605],SDL_MapRGB(sss->format,96,0,0));
rrr[606].x=600-230;
rrr[606].y=130;
rrr[606].w=20;
rrr[606].h=50;
SDL_FillRect(sss,&rrr[606],SDL_MapRGB(sss->format,95,0,0));
rrr[607].x=600-250;
rrr[607].y=140;
rrr[607].w=12;
rrr[607].h=25;
SDL_FillRect(sss,&rrr[607],SDL_MapRGB(sss->format,94,0,0));


SDL_UpdateRects(sss,607,rrr);
SDL_Flip(sss);
SDL_WM_SetCaption("X",NULL);



do{


if(SDL_PollEvent(&event)){
if(event.type==SDL_KEYDOWN){
if(event.key.keysym.sym==SDLK_ESCAPE) a=27; 

}
else if (event.type==SDL_QUIT){
a=27;
}
if(event.type==SDL_MOUSEMOTION){
strcpy(h,"X");
i1=event.motion.x;
i2=event.motion.y;
for(i4=600;i4<608;i4++){
if ((i1>rrr[i4].x)&&(i1<rrr[i4].x+rrr[i4].w)&&(i2>rrr[i4].y)&&(i2<rrr[i4].y+rrr[i4].h)){
strcpy(h,"DOOR 0");
h[5]='0'+(i4-600);
}
}
SDL_WM_SetCaption(h,NULL);
}
}


if (a==27)i1=1;
}while(i1!=1);


return 0;
}











