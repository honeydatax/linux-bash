#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void msgbox();
int count=0;
int counts=0;
int n;
int nn;


int main(int argc, char *argv[]){
		int i;
		int max=(16*1024-1);
		int ii;
		int r;
		msgbox();
		if (argc<3) exit(0);
		count=0;
		counts=1;
		count=atoi(argv[1]);
		counts=atoi(argv[2]);
		n=atoi(argv[3]);
		for (nn=0;nn<n;nn++){
			srandom(time(NULL));
			r=random() & max;
			counts=counts & max;
			count=count & max;
			i=counts-count;
			ii=max/i;
			i=r/ii;
			i=i+count;
			sleep (1);
			printf("%d,%d\n",nn,i);
		}
return 0;
}

void msgbox(){
	printf ("\e[0;34;46m");
}









