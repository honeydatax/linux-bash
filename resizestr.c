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
void strFill(char *a,char c,int n);
void resizestr(char *a,char *b,char c);

int main(){
char a[256];
char b[256];
strcpy(b,"im love marina");
strFill(a,'*',50);
resizestr(a,b,'.');
printf("%s \n",b);
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


void strFill(char *a,char c,int n){
for (int i=0;i<n;i++)a[i]=c;
a[n]=0;
}


void resizestr(char *a,char *b,char c){
char d[256];
int ia=strlen(a);
int ib=strlen(b);
int ii=0;
int i=Stringcmp(a,b);
if (i>0){
ii=ia-ib;
strFill(d,c,ii);
strcat(b,d);
}

if (i<0){
ii=ib-ia;
strFill( d,c,ii);
strcat(a,d);

}

}
























