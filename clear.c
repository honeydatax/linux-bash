#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define nlines 25
#define sleept 3
void msgbox();
int page=0;
char linec[81];
char *c=linec;
char *ch;
int count=0;


int main(int argc, char *argv[]){
		msgbox();
}
void msgbox(){
	printf ("\e[0;34;47m");
	memset(c,' ',80);
	c[80]=0;
	for (count=0;count<nlines;count++){
		printf("%s\n",c);
	}
	printf ("\e[1;1f");
}

