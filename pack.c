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
long pos;
int f1;
int f2;
int f3;
size_t t;
int n;

int main(int argc, char *argv[]){
		printf ("\e[0;34;47m");
		if(argc<3)exit(0);
		f2=creat(argv[argc-1],S_IRWXU);
		f3=creat("pack.dat",S_IRWXU);
		
		f2=creat(argv[argc-1],S_IRWXU);
		f3=creat("pack.dat",S_IRWXU);
		
		printf("\nto:%s\n",argv[argc-1]);
		for (n=1;n<argc-1;n++){
			f1=open(argv[n],  O_RDONLY);
			printf("%s\n",argv[n]);
			write(f3,argv[n],80);
				do{
					t=read(f1,c,bufsize);
					write(f2,c,t);
			
			
				}while(t>1);
				close(f1);
			pos=lseek(f2,0,SEEK_CUR);
			write(f3,&pos,4);

		}
		pos=lseek(f2,0,SEEK_CUR);
		write(f3,&pos,4);
		close(f3);
		f1=open("pack.dat",  O_RDONLY);
		printf("writing: head\n");
				do{
					t=read(f1,c,bufsize);
					write(f2,c,t);
			
			
				}while(t>1);
				close(f1);
				
		close(f2);
		
	return 0;
}





