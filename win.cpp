#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void) {
   Display *d;
   Window w;
    XEvent e;
      
   int s;
 
   d = XOpenDisplay(NULL);
   if (d == NULL) {
      fprintf(stderr, "x fail\n");
      exit(1);
   }
 
   s = DefaultScreen(d);
   w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 320, 240, 1,
                           0x0000F0, 0xFF8E00);
   XSelectInput(d, w, ExposureMask);
   XMapWindow(d, w);
   
   
    
 
   while (1) {
      XNextEvent(d, &e);
      if (e.type == Expose) {
		
      }
      if (e.type == exit) {
		break;
      }

   }
 
   XCloseDisplay(d);
   return 0;
}
