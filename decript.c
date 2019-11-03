#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void msgbox();
char linec[800];
char *c=linec;
FILE *f1;
int count=0;



int main(int argc, char *argv[]){
		ssize_t sssize_t;
		char cccc[80];
		int fin;
		int fout;
		int sizez;
		int ssize;
		int pointers;
		msgbox();
		int bb;
		int count=0;
		if (argc<2) exit(1);
		strcpy(cccc,argv[1]);
		sizez=strlen(cccc);
		fin=fileno(stdin);
		fout=fileno(stdout);
		sssize_t=799;
		pointers=0;
		bb=0;
		do{

				
				sssize_t=read(fin,c,800);
				for(count=0;count<((int)sssize_t);count++){
					c[count]=(char) c[count]-cccc[pointers];
					pointers++;
					if (pointers>=sizez)pointers=0;
				}
				write(fout,c,sssize_t);
				if (sssize_t<800)bb=1;
			
		}while(bb!=1);

return 0;
}

void msgbox(){
	;//printf ("\e[0;31;46m");
}








