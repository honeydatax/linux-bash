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
int R[50];
int G[50];
int B[50];
SDL_Rect rrr[1];
SDL_Rect rrrr[50];
SDL_Surface *sss;
SDL_Surface *iiii;
SDL_Event event;

int w=0;
long l;
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
char *d=argv[2];
if (argc<2) exit(1);

fd1=open(c,O_WRONLY|O_NONBLOCK); 
fd2=open(d,O_RDONLY|O_NONBLOCK); 

rrr[0] = {0 ,0 ,639 ,479 };
SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
atexit(SDL_Quit);
sss=SDL_SetVideoMode(640,480,8,0);
SDL_FillRect(sss,&rrr[0],SDL_MapRGB(sss->format,255,255,255));
SDL_UpdateRects(sss,1,rrr);
SDL_WM_SetCaption("graphics",NULL);
R[0]=255;
B[0]=255;
G[0]=255;
w=1;


do{
counter=0;
do{
ccc='\0';
if(SDL_PollEvent(&event)){
if(event.type==SDL_KEYDOWN){
if(event.key.keysym.sym==SDLK_ESCAPE)
{fff=1;
ccc='\n';
counter=3;
cc[counter]=2;
} 
}
else if (event.type==SDL_QUIT){
fff=1;
counter=3;
cc[counter]=2;
ccc='\n';
}
}
l=1;
if (ccc!='\n') l=read(fd2,&ccc,1);
if (l==1){
cc[counter]=ccc;
counter++;
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
sscanf(s1,"%i %i %i %i %i %i %i",&i1,&i2,&i3,&i4,&i5,&i6,&i7);
rrrr[w].x=i1;
rrrr[w].y=i2;
rrrr[w].w=i3;
rrrr[w].h=i4;
R[w]=i5;
B[w]=i6;
G[w]=i7;

SDL_FillRect(sss,&rrrr[w],SDL_MapRGB(sss->format,R[w],G[w],B[w]));
w++;
SDL_UpdateRects(sss,1,rrr);
}

if (cc[0]=='s')
{
s1=&cc[1];
sscanf(s1,"%i",&i1);
ll=(long)i1;
ll=ll*1000000;
usleep (ll);
}
if (cc[0]=='e')fff=1;
}while(fff!=1);



write(fd1,"e\n",2);


close(fd1);
close(fd2);


return 0;
}













