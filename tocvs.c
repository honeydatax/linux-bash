#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define nlines 30
#define sleept 3
void msgbox();
int page=0;
char linec[800];
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


int main(int argc, char *argv[]){
		msgbox();
		do{
			fgets(c,800,stdin);
			
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
					tabs[count]=backnode;
					
					
				}else{
					count++;
					tabs[count]=backnode;
					n=nlines+2;					
					
				}
				
			}
			
				for (n=0;n<count;n++){
					if (n!=0 && strcmp(tabs[n],"")!=0){
						printf("%s",tabs[n]);
						if (n!=count-1)printf(","); 
						//if (n==count-1)printf("\n");
					}
				}
			
		}
			c[0]=0;
		}while(!feof(stdin));

	
return 0;
}

void msgbox(){
	printf ("\e[0;31;46m");
}








