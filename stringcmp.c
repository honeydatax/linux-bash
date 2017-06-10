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
int Stringcmp(char *a,char *b);



int main(){
char a[256];
char b[256];
char c[256];
char d[256];
int i=0;
strcpy(a,"im love marina");
strcpy(b,"im love marina");
strcpy(c,"im love marina.");
strcpy(d,"im love marina..");
i=Stringcmp(a,b);
printf("%d, '%s' , '%s' \n",i,a,b);
i=Stringcmp(a,c);
printf("%d, '%s' , '%s' \n",i,a,c);
i=Stringcmp(c,a);
printf("%d, '%s' , '%s' \n",i,c,a);

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


int Stringcmp(char *a,char *b){
int c=strlen(a);
int d=strlen(b);
int i=0;
if (c<d)i=-1;
if (c>d)i=1;
return i;
}






























