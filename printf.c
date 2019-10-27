#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void strReplace(char *cccc,char *c,char *cc,char *ccc);
void msgbox();
char ccc[512];
char cc[512];
char *c;
char *c1;
char *c2;
int i;
int page=0;

char *ch;
FILE *f1;
int count=0;
int counts=0;


int main(int argc, char *argv[]){
		msgbox();
		if (argc<2) exit(0);
		strReplace(cc,argv[1],"\\n","\n");
		strReplace(ccc,cc,"\\r","\r");
		c=strstr(ccc,"%");
		if (c==NULL){
			puts(ccc);
		}else{
		c2=ccc;
		for(count=2;count<argc;count++){
			c=strstr(c2,"%");
			counts=0;
			if(c!=NULL)counts=1;
			if(counts==1){
				c1=c+1;
				c[0]=0;
				printf(c2);
				printf(argv[count]);
				if (c1[0]!=0)c2=c1+1;
				c=strstr(c2,"%");
				if(c==NULL)printf(c2);
			}else{
				if (count<(argc)) printf(c2);
			}
			
			
		}
	}
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




