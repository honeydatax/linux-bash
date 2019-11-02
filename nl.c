#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void msgbox();
char linec[800];
char *c=linec;
FILE *f1;
int count=0;


int main(int argc, char *argv[]){
		msgbox();
		int count=0;
		do{
			fgets(c,800,stdin);
			
			if (c[0]!=0){
				printf("%d %s",count,c);
		}		count++;
			c[0]=0;
		}while(!feof(stdin));


return 0;
}

void msgbox(){
	printf ("\e[0;31;46m");
}








