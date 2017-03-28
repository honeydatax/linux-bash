/*  demo.c*/
#include<graphics.h> 
int main()
{
char a;
   int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
   initgraph(&gd,&gm,NULL);
setbkcolor(15);
setcolor(14);
setfontcolor(0);
bar(left,top, right , bottom);
   outtextxy(50, 50, "press key");
setcolor(0);
line(100,100,101,101);   

a=getch();
 //delay(10000);
   closegraph();
   return 0;
}
