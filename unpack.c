#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define bufsize 2048

void msgbox();
char lines[81];
char linec[bufsize];
char *c=linec;
long bufsizes=0;
long pos;
long pos1;
long pos2;
long pos3;
long pos4;
long tt;
int f1;
int f2;
int f3;
size_t t;
int n;

int main(int argc, char *argv[]){
		lines[80]=0;
		printf ("\e[0;34;47m");
		if(argc<2)exit(0);
		if (strstr(argv[1],".pck")==NULL) exit(0);
		f2=open(argv[1], O_RDONLY);
		f3=creat("pack.dat",S_IRWXU);
		pos=lseek(f2,0,SEEK_END);
		pos=pos-4;
		lseek(f2,pos,SEEK_SET);
		read(f2,&pos,4);
		lseek(f2,pos,SEEK_SET);
		pos4=pos;
		printf("reading: head\n");
				do{
					t=read(f2,c,bufsize);
					write(f3,c,t);
					
				}while(t>1);
				
		close(f3);
		close(f2);
	
		f2=open(argv[1], O_RDONLY);
		f3=open("pack.dat",O_RDONLY);
				
		printf("\nfrom:%s\n",argv[1]);
		
		do{
			pos3=read(f3,lines,80);	
			pos4=0;
			if (pos3>1)pos3=read(f3,&pos4,4);
			if (pos3>1){
				f1=creat(lines,S_IRWXU);
				printf("%s\n",lines);
				if(f1>0){
					
						pos1=lseek(f2,0,SEEK_CUR);
						do{
							bufsizes=bufsize;
							pos1=pos1+bufsizes;
							if (pos1>pos4)bufsizes=bufsizes-(pos1-pos4);
							t=read(f2,c,bufsizes);
							write(f1,c,t);
							pos1=lseek(f2,0,SEEK_CUR);
						}while(pos4>pos1);
						close(f1);
				}
			}
		}while(pos3>1);
		
		close(f3);		
		close(f2);
	return 0;
}





