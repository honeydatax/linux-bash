#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define nlines 16
#define sleept 3
void msgbox();
int page=0;
char linec[800];
char *c=linec;
char *ch;
FILE *f1;
int count=0;


int main(int argc, char *argv[]){
		msgbox();
		if (argc<2) exit(0);
		do{
			fgets(c,79,stdin);
			ch=strstr(c,argv[1]);
			if (ch!=NULL){
				printf("%s",c);
			}
			
		}while(!feof(stdin));


return 0;
}

void msgbox(){
	printf ("\e[0;34;47m");
}








