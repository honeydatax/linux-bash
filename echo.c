#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


void msgbox();
char *c;
int i;

int main(int argc, char *argv[]){
		msgbox();
		if (argc<2) exit(0);
		for (i=0;i<argc-1;i++){
			printf("%s ",argv[i+1]);
		}
		printf("\n");	
return 0;
}

void msgbox(){
	printf ("\e[0;34;47m");
}








