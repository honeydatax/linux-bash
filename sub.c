#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>



int main(int argc, char ** argv){
int i1=atoi(argv[1]);
int i2=atoi(argv[2]);
FILE *f;
char s[50];
if (argc<3) exit(0);
f=fopen(argv[3],"w+");
i1=i1-i2;
fprintf(f,"%i",i1);
fclose(f);
return i1;
}













