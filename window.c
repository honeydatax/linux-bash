#include <curses.h>
#include <string.h>
#include <stdio.h>

int main(){
char scr[1024];
WINDOW *win1,*win2,*win3;
memset(scr,' ',15*40);
scr[15*40+1]='\n';
beep();
initscr();
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
win1=newwin(15,40,1,1);
wbkgd(win1,COLOR_PAIR(1));
win2=newwin(15,40,2,2);
wbkgd(win2,COLOR_PAIR(2));
win3=newwin(15,40,3,3);
wbkgd(win3,COLOR_PAIR(3));
//mvwprintw(win1,1,1,scr);
mvwprintw(win1,1,1,"windows 1!");
box(win1,0,0);
//mvwprintw(win2,1,1,scr);
mvwprintw(win2,1,1,"windows 2!");
box(win2,0,0);
//mvwprintw(win3,1,1,scr);
mvwprintw(win3,1,1,"windows 3!");
box(win3,0,0);
wrefresh(stdscr);
wrefresh(win1);
wrefresh(win2);
wrefresh(win3);
refresh();
getch();
redrawwin(stdscr);
redrawwin(win3);
redrawwin(win1);
redrawwin(win2);
wrefresh(stdscr);
wrefresh(win2);
wrefresh(win3);
wrefresh(win1);
refresh();
getch();
redrawwin(stdscr);
redrawwin(win3);
redrawwin(win1);
redrawwin(win2);
wrefresh(stdscr);
wrefresh(win3);
wrefresh(win1);
wrefresh(win2);
refresh();
getch();
delwin(win1);
delwin(win2);
delwin(win3);
endwin();
return 0;
}












