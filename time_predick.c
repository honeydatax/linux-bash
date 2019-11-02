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
int rain;


int main(int argc, char *argv[]){
		int i;
		int max=(16*1024-1);
		int ii;
		int r;
		int rr;
		msgbox();
		if (argc<2) exit(0);
		printf("\ndate,temprature,clouds,city,rain\n");
		count=0;
		counts=1;
		count=1;
		counts=19;
		n=atoi(argv[1]);
		srandom(time(NULL));
		for (nn=0;nn<n;nn++){
			rr=random() & 1;
			r=random() & max;
			counts=counts & max;
			count=count & max;
			i=counts-count;
			ii=max/i;
			i=r/ii;
			i=i+count;
			rain=0;
			if (rr==1 && i < 9)rain=1;			
			printf("%d,%d,%d,London,%d\n",nn,i,rr,rain);
		}
return 0;
}

void msgbox(){
	printf ("\e[0;34;46m");
}









