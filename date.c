#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void msgbox();
char linec[800];
char *c=linec;
FILE *f1;
int count=0;


int main(int argc, char *argv[]){
		time_t ticks;
		ssize_t t;
		msgbox();
		int count=0;
		ticks = time(NULL);
		snprintf(linec, sizeof(linec), "%.24s\r\n", ctime(&ticks));
		printf("%s\n",linec);
return 0;
}

void msgbox(){
	printf ("\e[0;31;46m");
}








