#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void msgbox();
int numbers[60];
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
		for (nn=0;nn<56;nn++){
			numbers[nn]=0;
		}
		msgbox();
		if (argc<2) exit(0);
		printf("\nnumber,loto\n");
		count=0;
		counts=1;
		count=1;
		counts=55;
		n=atoi(argv[1]);
		srandom(time(NULL));
		for (nn=0;nn<n;nn++){
			r=random() & max;
			counts=counts & max;
			count=count & max;
			i=counts-count;
			ii=max/i;
			i=r/ii;
			i=i+count;
			rr=numbers[i];
			rr++;
			numbers[i]=rr;
			printf("%d,%d\n",nn,i);
		}
		
		printf("*************************\n");
		printf("loto,many times\n");
		for (nn=0;nn<56;nn++){
			printf("%d,%d\n",nn,numbers[nn]);
		}

return 0;
}

void msgbox(){
	printf ("\e[0;34;46m");
}









