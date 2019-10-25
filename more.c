#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define nlines 16
#define sleept 3
void msgbox();
int page=0;
char linec[80];
char *c=linec;
char ch;
FILE *f1;
int count=0;


int main(int argc, char *argv[]){
		msgbox();
			
		do{
			fgets(c,79,stdin);
			printf("%s",c);
			count++;
			if (count>nlines){
				count=0;
				printf("\npage %d\n",page);
				sleep (sleept);
				page++;
			}
			
		}while(!feof(stdin));


return 0;
}

void msgbox(){
	printf ("\e[0;34;47m");
}








