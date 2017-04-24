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
#include <dirent.h>


void list();
static int cmpstringp(const void *p1, const void *p2);


int ttotal=0;
int attotal=0;
char directory[1024];
char door[500][50]; 
char *pdoor[500];
time_t rawtime;
struct tm *timeinfo;
struct timeval start, ends;



int main(){
int cursors2=0;
int ppdor=0;
int cursors=0;
char h[250];
char a=0;
int mm=0;
int m1=0;
int center=300;
int scenter=1;
int w=0;
long l;
long ll5=0;
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
int i1=40,i2=40,i3=10,i4=10,i5=0,i6,i7,i8,i9,i10,i11,i12;
list();
printf("%s\n",directory);
for(i6=0;i6<ttotal;i6++)printf("/%s\n",pdoor[i6]);
for(i6=ttotal;i6<attotal+ttotal;i6++)printf("%s\n",pdoor[i6]);
printf("\ntotal:%i",attotal+ttotal);
return 0;
}

void list(){
int i1=0;
int total=0;
int kkl=0;
for (i1=0;i1<500;i1++){
door[i1][0]=0;
pdoor[i1]=&door[i1][0];
}

struct dirent *ldir;
struct dirent *ldir2;
getcwd(directory,sizeof(directory));
DIR *dir=opendir(directory);
ldir=readdir(dir);
if (ldir==NULL)kkl=1;
while(kkl!=1){
strcpy(door[total],ldir->d_name);
if (ldir->d_type==DT_DIR && door[total][0]!='.'){
total++;
}
ldir=readdir(dir);
if (ldir==NULL)kkl=1;
if (total>500)kkl=1;
}
closedir(dir);
ttotal=total;
qsort(&pdoor[0], ttotal, sizeof(char *), cmpstringp);
kkl=0;
DIR *dir2=opendir(directory);
ldir2=readdir(dir2);
if (ldir2==NULL)kkl=1;
while(kkl!=1){
strcpy(door[total],ldir2->d_name);
if (ldir2->d_type!=DT_DIR && door[total][0]!='.'){
total++;
}
ldir2=readdir(dir2);
if (ldir2==NULL)kkl=1;
if (total>500)kkl=1;
}
closedir(dir2);
attotal=total-ttotal;
if (attotal<0)attotal=0; 
qsort(&pdoor[ttotal], attotal, sizeof(char *), cmpstringp);
}

 static int
       cmpstringp(const void *p1, const void *p2)
       {
           return strcmp(* (char * const *) p1, * (char * const *) p2);
       }
















