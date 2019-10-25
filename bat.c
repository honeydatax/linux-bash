#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void msgbox();
char linec[80];
char *c=linec;
FILE *f1;

int main(int argc, char *argv[]){
		msgbox();
		if(argc<2)exit(0);
		f1=fopen(argv[1],"r");
		do{
			fgets(c,79,f1);
			system(c);
			
			
		}while(!feof(f1));


return 0;
}

void msgbox(){
	printf ("\e[0;34;47m");
}








