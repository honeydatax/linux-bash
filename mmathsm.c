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
#include <sys/time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <math.h>

#define PI 3.1415927

void clear();
void list();

int main(){
clear();
printf(" \033c.\n");
list();
return 0;
}


void clear(){
int i;
for (i=0;i<50;i++)printf("\n");
}

void list(){
int i=0;
long l;
double d=0.0;
long double dd=0.0,ddd=0.0,dtotal=0.0,dfloat=0.0,pi=0.0;
double total=0;
pi=PI;
printf("long lcos[360]{");
for(total=0.0;total<360.0;total++){
dtotal=(long double)total;
dd=10*cos(dtotal/180.0/pi);
ddd=dd*10000;
l=(long)ddd;
printf("%lu,\n",l);
}
printf("};\nlong lsin[360]{");
for(total=0.0;total<360.0;total++){
dtotal=(long double)total;
dd=10*sin(dtotal/180.0/pi);
ddd=dd*10000;
l=(long)ddd;
printf("%lu,\n",l);
}
printf("};");

}



















