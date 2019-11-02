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
		char cccc[]="abdcdefghijklmnopqrstuvwxyz0123456789!@#$%%&*+-";
		int i;
		int max=(16*1024-1);
		int ii;
		int r;
		int rr;
		int xx;
		int xxx;
		msgbox();
		if (argc<3) exit(0);
		printf("\nnumber,password\n");
		count=0;
		counts=1;
		count=1;
		counts=sizeof(cccc);
		n=atoi(argv[1]);
		xxx=atoi(argv[2]);
		srandom(time(NULL));
		for (nn=0;nn<n;nn++){
			printf("%d ",nn);
			for (xx=0;xx<xxx;xx++){
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
				printf("%c",cccc[i]);
			}
			printf("\n");
		}
		
return 0;
}

void msgbox(){
	printf ("\e[0;34;46m");
}









