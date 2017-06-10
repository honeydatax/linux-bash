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


void reverseString(char *a,char *b);




int main(){
char a[256];
char b[256];
strcpy(a,"im love marina.");
reverseString(&a[0],&b[0]);
printf("%s\n",b);
return 0;
}



void reverseString(char *a,char *b){
int c=strlen(a);
int counter1;
int counter2=c;
if (c<255 && c>0){
b[counter2]=0;
counter2--;
for(int i=0;i<c;i++){
b[counter2]=a[i];
counter2--;
}
}else b[0]=0;


} 

































