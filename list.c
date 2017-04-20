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


#define ddir "./\0"

void clear();
void list();

int main(){
clear();
printf(" LIST.\n");
list();
return 0;
}


void clear(){
int i;
for (i=0;i<50;i++)printf("\n");
}

void list(){
int total=0;
DIR *dir=opendir(ddir);
struct dirent *ldir;
ldir=readdir(dir);
while(ldir!=NULL){
printf("%s,%ld\n",ldir->d_name,ldir->d_ino);
total++;
ldir=readdir(dir);
}
closedir(dir);
printf("total files:%d\n",total);
}



















