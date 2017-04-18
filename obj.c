#include <stdio.h>
#include <stdlib.h>
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

#define sizz 18

extern char _binary_obj_start;
extern char _binary_obj_end;
main(){
char *p=&_binary_obj_start;
char *p2=&_binary_obj_end;
p2[0]=0;
printf("%s",p);
}




















