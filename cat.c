#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void msgbox();
char linec[82];
char *c=linec;
int f1;
int f2;
size_t t;

int main(int argc, char *argv[]){
		
		if(argc<2)exit(0);
		f1=open(argv[1],  O_RDONLY);
		f2=fileno(stdout);
		do{
			t=read(f1,c,80);
			write(f2,c,t);
			
			
		}while(t>1);
		close(1);

return 0;
}





