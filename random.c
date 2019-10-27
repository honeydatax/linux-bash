#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void msgbox();
int count=0;
int counts=0;


int main(int argc, char *argv[]){
		int i;
		int max=(16*1024-1);
		int ii;
		int r;
		msgbox();
		count=0;
		counts=1;
		if (argc==2){
			count=0;
			counts=atoi(argv[1]);
		}else{
			count=atoi(argv[1]);
			counts=atoi(argv[2]);

		}
		srandom(time(NULL));
		r=random() & max;
		counts=counts & max;
		count=count & max;
		i=counts-count;
		ii=max/i;
		i=r/ii;
		i=i+count;
		printf("%d\n",i);
		
return 0;
}

void msgbox(){
	printf ("\e[0;34;47m");
}









