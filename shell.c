#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void msgbox();
char linec[80];
char *c=linec;
int pos=0;
int exitcode=0;

int main(int argc, char *argv[]){
	msgbox();
	do{	
		strcpy(c,"");
		pos=0;
		do{
			if(pos<79) c[pos]=fgetc(stdin);
			if (c[pos]!=255 && c[pos]!=0)pos++;
			c[pos]=0;
			if (pos>77 || c[pos-1]=='\n' )exitcode=1;
			if (c[pos-1]=='\n') c[pos-1]=0;
		}while(exitcode!=1);
		if(strcmp(c,"exit")==0)break;
		
		system(c);
		exitcode=0;
	}while(exitcode!=1);
return 0;
}

void msgbox(){
	printf ("\e[0;34;47m");
	printf("\nmini kernel - shell\n");
}








