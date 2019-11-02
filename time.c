#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define maxarg 20
void msgbox();
int i;
int page=0;
char c[80];
char ccc[80];
char *ch[25];
char *cc;
FILE *f1;
int count=0;
int counts=0;


int main(int argc, char *argv[]){
		time_t t=time(NULL);
		time_t tt=time(NULL);
		char argvv[1];
		msgbox();
		if (argc<2) exit(0);
		argvv[0]=0;
		strcpy(c,"");
		for(count=0;count<argc-1;count++){
			
				strcat(c,argv[count+1]);
				strcat(c," ");
		}
		
		system(c);
		tt=time(NULL);
		tt=tt-t;
		printf("%ld\n",tt);
return 0;
}

void msgbox(){
	printf ("\e[0;34;47m");
}





