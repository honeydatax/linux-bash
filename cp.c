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
int n;

int main(int argc, char *argv[]){
		printf ("\e[0;34;47m");
		if(argc<3)exit(0);
		
		f2=creat(argv[argc-1],S_IRWXU);
		
		//f2=open(argv[argc-1],  O_RDWR || S_IRWXU);
		printf("\nto:%s\n",argv[argc-1]);
		for (n=1;n<argc-1;n++){
			f1=open(argv[n],  O_RDONLY);
			printf("%s\n",argv[n]);
		
				do{
					t=read(f1,c,bufsize);
					write(f2,c,t);
			
			
				}while(t>1);
				close(f1);
		}
		close(f2);
		
	return 0;
}





