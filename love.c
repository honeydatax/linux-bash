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

main(){
long sz;
chmod("love",0777);
FILE *f1=fopen("love","r");
char c[1024];
char *p=&c[0];
fseek(f1,0L,SEEK_END);
sz=ftell(f1);
sz=sz-sizz;
fseek(f1,sz,SEEK_SET);
sz=ftell(f1);
printf("%lu\n",sz);
fgets(c,sizz,f1);
c[sizz+1]=0;
printf("%s",c);
fclose(f1);
}




















