
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define textsize 800000
#define nlines 12000
void msgbox();
int page=0;
char linec[textsize];
char *c=linec;
char *cc;
char *ccc;
char *tabs[nlines];
int count=0;
int tindex=0;

int main(int argc, char *argv[]){
		msgbox();
		c=linec;
		tabs[0]=c;
		tindex=1;
		do{
			if (!feof(stdin)){
				fgets(c,800,stdin);
				count=strlen(c);
				c=tabs[tindex-1]+count+2;
				tabs[tindex]=c;
				tindex++;
			}
		}while(!feof(stdin));
		
		if (tindex>1){
			for (count=1;count<tindex;count++){
				cc=tabs[count];
				for (page=0;page<count;page++){
					if(strcmp(cc,tabs[page])<0){
						ccc=tabs[page];
						tabs[page]=cc;
						cc=ccc;
					}
				tabs[count]=cc;
				}
				
			}
			
		}
		 
			for (count=0;count<tindex;count++){
				printf("%s",tabs[count]);
			}
return 0;
}

void msgbox(){
	printf ("\e[0;34;46m");
}








