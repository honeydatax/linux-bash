#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void msgbox();
char linec[800];
char *c=linec;
FILE *f1;
int count=0;
int count2=0;
int count3=0;
int count4=0;


int main(int argc, char *argv[]){
		msgbox();
		int count=0;
		if (argc<3) exit(1);
		count2=atoi(argv[1]);
		count3=atoi(argv[2]);
		do{
			fgets(c,800,stdin);
			
			if (c[0]!=0 && count>=count2 && count4<=count3){
				printf("%s",c);
				count4++;
		}
				count++;
			c[0]=0;
		}while(!feof(stdin));


return 0;
}

void msgbox(){
	printf ("\e[0;31;46m");
}








