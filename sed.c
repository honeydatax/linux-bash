#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define nlines 16
#define sleept 3
void msgbox();
void strReplace(char *cccc,char *c,char *cc,char *ccc);
int page=0;
char linec[800];
char *c=linec;
char *ch;
FILE *f1;
int count=0;
char var0[512];

int main(int argc, char *argv[]){
		char *c0=var0;
		msgbox();
		if (argc<3) exit(0);
		do{
			fgets(c,79,stdin);
			if (c[0]!=0){
				strReplace(c0,c,argv[1],argv[2]);
				printf("%s",c0);
			}
			c[0]=0;
		}while(!feof(stdin));


return 0;
}

void msgbox(){
	printf ("\e[0;34;47m");
}

void strReplace(char *cccc,char *c,char *cc,char *ccc){
	long i1=0;
	long i2=0;
	long i3=0;
	char *v1=NULL;
	char *v2=NULL;
	v2=c;
	strcpy(cccc,"");
	do{
		i1=(long)(void*)v2;
		i3=strlen(v2);
		v1=strstr(v2,cc);
		if (v1!=NULL) i2=(long)(void*)v1;
		if (v1!=NULL) i3=i2-i1;
		strncat(cccc,v2,i3);
		if (v1!=NULL) strcat(cccc,ccc);
		if (v1!=NULL) v2=v1+strlen(cc);
	}while(v1!=NULL);
	

}








