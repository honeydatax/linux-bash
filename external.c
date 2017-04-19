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



#define sizz 9674

extern char _binary_external_bmp_start;
extern char _binary_external_bmp_end;


int main(){
char *p=&_binary_external_bmp_start;
char *p2=&_binary_external_bmp_end;
int f1;
char a;
char f;
SDL_Surface *s;
SDL_Surface *i,*ii;
SDL_Rect ir;
f1=open("marina.bmp",O_CREAT|O_RDWR);
write(f1,p,sizz);
close (f1);

chmod("marina.bmp",0666);

if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO==-1)){
printf("error:%s",SDL_GetError());
exit(-1);
}



atexit(SDL_Quit);

s=SDL_SetVideoMode(640,480,24,SDL_HWSURFACE);
if (s==NULL){
printf ("video mode size error:",SDL_GetError());
}

i=SDL_LoadBMP("marina.bmp");
ii=SDL_DisplayFormat(i);
if (i->format->palette && s->format->palette){
SDL_SetColors(s,i->format->palette->colors,0,
i->format->palette->ncolors);
}
ir.x=100;
ir.y=100;
ir.x=ii->w;
ir.y=ii->h;
if (SDL_BlitSurface(ii,NULL,s,&ir)<0){
printf ("surface error:",SDL_GetError());
}

SDL_UpdateRect(s,ir.x,ir.y,ii->w,ii->h);

a=fgetc(stdin);

SDL_FreeSurface(i);
SDL_FreeSurface(ii);

return (0);
}













