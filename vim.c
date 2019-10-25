
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//gcc -o out my.c
int count=0;
int sizes=0;
int large=0;
int linesize=60;
char varname[1864000]; 
char var1[100];
char var2[100];
char *p[8000];
char *aargv;
void on_selection();
void on_select();
int instr(char *c,char *cc);

int main(int argc, char *argv[])
{
		
		printf("\e[0;47;34m\n");	
		if (argc>1){
			aargv=argv[1];
			on_selection();
		}
        return 0;
}

void on_selection(){
	char *c1;
	int n=0;
	int nnn=0;
	int in=0;
	char *dd;
	char *ee;
	char var22;
	char *var222=var2;
	char *c=varname;
	char *cc=var1;
	char enterss[]="\r";
	char *entersss=enterss;
	char enter[]="\n";
	char *enters=enter;
	on_select();
	dd=varname;
	count=0;
	p[0]=dd;
	sizes=0;
	large=0;
	do{
		n=instr(dd,enters);
		in=instr(dd,entersss);
		if (n==-1)n=1000;
		if (in==-1)in=1000;
		if (in<n)n=in;
		if(n<linesize){
			cc=dd+n;
			ee=cc+1;
			strncpy(var1,dd,n+1);
			var1[n+1]=0;
			printf("%s",var1);
			dd=ee;
		}else{
			n=strlen(dd);
			if(n<linesize){
			printf("%s\n",dd);
			ee=dd+n;
			dd=ee;
			}else{
				strncpy(var1,dd,linesize);
				var1[linesize]=0;
				printf("%s\n",var1);
				ee=dd+linesize;
				dd=ee;
			}
		}
		count++;
		if (count>23){
			printf("\npage %d\npress a enter key to continue space key and enter go back\r",sizes);
			var22=gets(var222);
			count=0;
			if (var222[0]=='\0'){
					sizes++;
					p[sizes]=dd;
			}else{
				sizes--;
				if (sizes<0)sizes=0;
				dd=p[sizes];
			}
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%d\n",sizes);
		}
		if (dd[0]==0)nnn=1;
	}while(nnn!=1);
	
	}





void on_select(){
	char *cc;
	char *ccc;
	char d[600];
	char *dd=d;
	FILE *f1;
	cc=aargv;
	if (cc!=NULL){
		ccc=varname;
		strcpy(ccc,"");
		f1=fopen(cc,"r");
		do{
			fgets(dd,599,f1);
			strcat(ccc,dd);
			
			
		}while(!feof(f1));

		fclose(f1);
		
		
		

	}
}

int instr(char *c,char *cc){
	long i1=0;
	long i2=0;
	long i3=0;
	char *v1=NULL;
	i1=(long)(void*)c;
	i3=-1;
	v1=strstr(c,cc);
	if (v1!=NULL) i2=(long)(void*)v1;
	if (v1!=NULL) i3=i2-i1;
	return (int) i3;
}







