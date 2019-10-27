#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define maxarg 20
void msgbox();
int i;
int page=0;
char c[80];
char ccc[80];
char *ch[25];
char *cc;
FILE *f1;
int count=0;
int counts=0;


int main(int argc, char *argv[]){
		char argvv[1];
		msgbox();
		if (argc<2) exit(0);
		argvv[0]=0;
		strcpy(c,argv[1]);
		for(count=0;count<maxarg;count++){
			if(count<argc-1){
				ch[count]=argv[count+1];
			}else{
				ch[count]=argvv;
			}
			
		}
		count=execlp(c,ch[0],ch[1],ch[2],ch[3],ch[4],ch[5],ch[6],ch[7],ch[8],ch[9],ch[10],ch[11],ch[12],ch[13],ch[14],ch[15],ch[16],ch[17],ch[18],ch[19]);
		if (count==-1){
			cc=getenv("PATH");
			strcpy(ccc,cc);
			cc=strstr(ccc,":");
			if (cc!=NULL) cc[0]=0;
			strcpy(c,ccc);
			strcat(c,"/");
			strcat(c,argv[1]);
			puts (c);
			count=execlp(c,ch[0],ch[1],ch[2],ch[3],ch[4],ch[5],ch[6],ch[7],ch[8],ch[9],ch[10],ch[11],ch[12],ch[13],ch[14],ch[15],ch[16],ch[17],ch[18],ch[19]);
		}
return 0;
}

void msgbox(){
	printf ("\e[0;34;47m");
}





