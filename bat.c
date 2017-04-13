#include <curses.h>
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
struct termios oldt,newt;
struct tm *timeinfo;
struct timeval start, ends;



int main(int argc, char ** argv){
WINDOW *win[20];
FILE *ffa;
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
int i1=0,i2=0,i3=0,i4=0,i5=0;
char *c=argv[1];
char *d=argv[2];
if (argc<2) exit(1);
tcgetattr(fileno(stdin),&oldt);
memcpy(&newt,&oldt,sizeof(struct termios));
newt.c_lflag &= ~(ECHO|ICANON);
newt.c_cc[VTIME]=0;
newt.c_cc[VMIN]=0;
tcsetattr(fileno(stdin),TCSANOW,&newt);

fd1=open(c,O_WRONLY|O_NONBLOCK); 
fd2=open(d,O_RDONLY|O_NONBLOCK); 

initscr();
beep();
cbreak();
noecho();
keypad(stdscr,TRUE);
halfdelay(0);
raw();
curs_set(0);
start_color();
init_pair(1,COLOR_CYAN,COLOR_BLUE);
init_pair(2,COLOR_WHITE,COLOR_RED);
init_pair(3,COLOR_BLACK,COLOR_GREEN);
init_pair(4,COLOR_BLACK,COLOR_WHITE);
wbkgd(stdscr,COLOR_PAIR(4));
redrawwin(stdscr);
wrefresh(stdscr);
refresh();


do{
counter=0;
do{
l=read(fd2,&ccc,1);
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
sscanf(s2,"%i %i %i %[^\t\n]",&i1,&i2,&i3,s1);

mvwprintw(win[i1],i2,i3,s1);
wnoutrefresh(win[i1]);
doupdate();
redrawwin(stdscr);
for(t=0;t<w;t++) redrawwin(win[t]);
wrefresh(stdscr);
for(t=0;t<w;t++) wrefresh(win[t]);
refresh();
}

if (cc[0]=='n'){
s1=&cc[1];
sscanf(s1,"%i %i %i %i %i",&i1,&i2,&i3,&i4,&i5);
win[w]=newwin(i1,i2,i3,i4);
wbkgd(win[w],COLOR_PAIR(i5));
box(win[w],0,0);
w++;
redrawwin(stdscr);
for(t=0;t<w;t++) redrawwin(win[t]);
wrefresh(stdscr);
for(t=0;t<w;t++) wrefresh(win[t]);
refresh();
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


fclose(ffa);

write(fd1,"e\n",2);

for(t=0;t<w;t++) delwin(win[t]);
close(fd1);
close(fd2);

delwin(stdscr);
endwin();

oldt.c_lflag|=ECHO|ICANON;
tcsetattr(fileno(stdin),TCSANOW,&oldt);

return 0;
}













