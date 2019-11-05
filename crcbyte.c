#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define bufsize 2048

void msgbox();
char linec[bufsize];
char *c=linec;
int f1;
int f2;
size_t t;
long crc;
long crc1;
long crc2;
long crc3;
int n;

int main(int argc, char *argv[]){
		printf ("\e[0;34;47m");
		if(argc<2)exit(0);
		
			

		crc=0;
		
			f1=open(argv[1],  O_RDONLY);
			
		
				do{
					t=read(f1,c,bufsize);
					for(crc3=0;crc3<t;crc3++){
						crc2=(long) c[(int)crc3];
						crc=crc+crc2;
					}
			
			
				}while(t>1);
				close(f1);
		
		
		printf("%lu\n",crc);		
	return 0;
}





