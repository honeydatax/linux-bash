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
char ac1;
int mm=0;
int m1=0;
int R[150];
int G[150];
int B[150];
SDL_Rect rrr[150];
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
int i1=0,i2=0,i3=0,i4=0,i5=0,i6,i7,i8,i9,i10,i11,i12;
char *c=argv[1];
if (argc<1) exit(1);

fd2=open(c,O_RDONLY|O_NONBLOCK); 

rrr[0] = {0 ,0 ,639 ,479 };
SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
atexit(SDL_Quit);
sss=SDL_SetVideoMode(640,480,8,0);
SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));
for (mm=0;mm<20;mm++){
m1=mm*20;
rrr[mm+1].x = 0;
rrr[mm+1].y = m1;
rrr[mm+1].w = 20*20;
rrr[mm+1].h = 2;

rrr[mm+21].x = m1;
rrr[mm+21].y = 0;
rrr[mm+21].w = 2;
rrr[mm+21].h = 20*20;

SDL_FillRect(sss,&rrr[mm+1],SDL_MapRGB(sss->format,0,0,0));
SDL_FillRect(sss,&rrr[mm+21],SDL_MapRGB(sss->format,0,0,0));
}
SDL_UpdateRects(sss,40,rrr);
SDL_WM_SetCaption("X Y",NULL);
R[0]=255;
B[0]=255;
G[0]=255;
w=41;
ll5=8000000;


do{
counter=0;
do{
l=read(fd2,&ccc,1);
if (l==1){
cc[counter]=ccc;
counter++;
}else{
fff=1;
counter=3;
cc[counter]=0;
ccc='\n';
cc[0]='e';
}
}
while(ccc!='\n');
cc[counter-1]=0;
i1=0;
i2=0;
i3=0;
i4=0;
i5=0;
if (cc[0]=='p'){
s2=&cc[1];
sscanf(s2,"%[^\t\n]",s1);
SDL_WM_SetCaption(s1,NULL);
}

if (cc[0]=='n'){
s1=&cc[1];
sscanf(s1,"%i %i %1c",&i1,&i2,&ac1);

if (ac1=='R' || ac1=='r')R[w]=255;
else R[w]=0;
if (ac1=='G' || ac1=='g')G[w]=255;
else G[w]=0;
if (ac1=='B' || ac1=='b')B[w]=255;
else B[w]=0;

rrr[w].x = 200+i1*20+7;
rrr[w].y = 200+i2*20+1;
rrr[w].w = 8;
rrr[w].h = 18;


SDL_FillRect(sss,&rrr[w],SDL_MapRGB(sss->format,R[w],G[w],B[w]));

w++;

if (ac1=='R' || ac1=='r')R[w]=255;
else R[w]=0;
if (ac1=='G' || ac1=='g')G[w]=255;
else G[w]=0;
if (ac1=='B' || ac1=='b')B[w]=255;
else B[w]=0;


rrr[w].x = 200+i1*20+1;
rrr[w].y = 200+i2*20+8;
rrr[w].w = 18;
rrr[w].h = 8;


SDL_FillRect(sss,&rrr[w],SDL_MapRGB(sss->format,R[w],G[w],B[w]));

w++;
SDL_UpdateRects(sss,w,rrr);
}

if (cc[0]=='s')
{
s1=&cc[1];
sscanf(s1,"%i",&i1);
ll=(long)i1;
ll5=ll*1000000;
}
if (cc[0]=='e')fff=1;
}while(fff!=1);


usleep (ll5);

close(fd2);


return 0;
}













