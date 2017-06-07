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
#include <math.h>

char *addItem(char *b);
void printList(char **p,int counter);
void freeList(char **p,int counter);

int main(){
int counter=17;
char c[50];
char *p[100];

for (int a=0;a<counter;a++){
sprintf(c,".item %d",a);
p[a]=addItem(c);
}

printList(&p[0],counter);


freeList(&p[0],counter);

return 0;
}



char *addItem(char *b){
char *a;
a=(char*)malloc(50);
strcpy(a,b);
return a;
}


void printList(char **p,int counter){
for (int a=0;a<counter;a++){
printf("%s\n",p[a]);
}

}


void freeList(char **p,int counter){

for (int a=0;a<counter;a++){
free(p[a]);
}


}












