
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define nlines 16
#define sleept 3
void msgbox();
int page=0;
char linec[800];
char finder[128000];
char *c=linec;
char *tabs[nlines];
int tabb[nlines];
char *nextnode;
char *endnode;
char *backnode;
int bool;
int i;
char *ch;
int n;
FILE *f1;
int count=0;
int tindex=0;
char *iindex;
int t;
int tt;
int ii;

int main(int argc, char *argv[]){
		tt=-31000;
		msgbox();
		if (argc<2) exit(0);
		t=atoi(argv[1]);
		tindex=0;
		do{
			fgets(c,800,stdin);
			iindex=finder+(tindex*100);
			strcpy(iindex,c);
			if (c[0]!=0){
			backnode=c;
			tabs[0]=c;
			count=0;

			for (n=0;n<nlines;n++){
				nextnode=strstr(backnode," ");
				if(nextnode!=NULL){
					count++;
					backnode=nextnode+1;
					tabs[count]=backnode;
					nextnode[0]=0;
					bool=0;
					if (backnode[0]!=32 || backnode[0]==0) bool=1;
					while(bool!=1){
						bool=0;
						backnode=backnode+1;
						if (backnode[0]!=32 || backnode[0]==0) bool=1;
						
					};
					
					
					
				}else{
					count++;
					tabs[count]=backnode;
					n=nlines+2;					
					
				}
				
			}
			ii=atoi(tabs[t]);
			if (ii==tt){
				tindex ++;
			}
			if (ii>tt){
				tt=ii;
				iindex=finder+(tindex*100);
				strcpy(finder,iindex);
				tindex=1;
			}


		}
			c[0]=0;
		}while(!feof(stdin));
		for (i=0;i<tindex;i++){
			iindex=finder+(i*100);
			printf("%s",iindex);
		}

return 0;
}

void msgbox(){
	printf ("\e[0;34;46m");
}








