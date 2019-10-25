#include <string.h>
#include <stdlib.h>
#include <stdio.h>



//gcc -o out my.c
int linesize=50;
int w=640;
int h=8000;
char files[]="labelhtml.dat";
char *file=files;
char varname[864000]; 
char varname2[864000]; 
char var1[512];
char var2[98];
char *aargv;
char aargvv[]="http://www.planet-source-code.com";
char *body_start(char *c);
char *body_end(char *c);
void remove_tags(char *c, char *cc);
void on_selection();
void on_select();
void replace_sstr(char *c, char *cc,char *ccc);
int instr(char *c,char *cc);
void replace_char(char *c, char cc,char ccc);


int main(int argc, char *argv[])
{
		aargv=aargvv;
		printf("\e[0;47;34m\n");	
		if (argc<2){
			printf("%s\n",aargvv);
			
		}else{
		aargv=argv[1];
		}
        on_selection();
        //system("exo-open labelhtml.txt");
        return 0;
}

void on_selection(){
	char *c1;
	char br[]="<br>";
	char BR[]="<BR>";
	char ibr[]="</br>";
	char iBR[]="</BR>";
	char td[]="<td>";
	char TD[]="<TD>";
	char iTD[]="</TD>";
	char itd[]="</td>";
	char th[]="<th>";
	char TH[]="<TH>";
	char ith[]="</th>";
	char iTH[]="</TH>";
	char p[]="<p>";
	char P[]="<P>";
	char ip[]="</p>";
	char iP[]="</P>";
	char sp1[]="\n";
	char sp2[]="\r\n";
	char sp3[]=" \r\n";
	char sp4[]="  \r\n";
	char sp5[]="   \r\n";
	char tb1[]="\t";
	char tb2[]=" \t";
	char tb3[]="  \t";
	char tb4[]="   \t";
	char tb5[]="    \t";
	int n=0;
	int nnn=0;
	int in=0;
	char *dd;
	char *ee;
	float nn=20.0f;
	char *c=varname;
	char *cc=varname2;
	char enterss[]="\r";
	char *entersss=enterss;
	char enter[]="\n";
	char *enters=enter;
	strcpy(var1,"curl -s ");
	strcat(var1,aargv);
	strcat(var1," > ");
	strcat(var1,file);
	system(var1);
	on_select();
	c1=body_start(c);
	if (c1!=NULL){
	c=c1;
	body_end(c);
	replace_char(c,'\n',' ');
	replace_char(c,'\r',' ');
	replace_char(c,'\t',' ');
	replace_sstr(c,td,tb4);
	replace_sstr(c,TD,tb4);
	replace_sstr(c,itd,tb5);
	replace_sstr(c,iTD,tb5);
	replace_sstr(c,th,sp4);
	replace_sstr(c,TH,sp4);
	replace_sstr(c,ith,sp5);
	replace_sstr(c,iTH,sp5);
	replace_sstr(c,br,sp4);
	replace_sstr(c,BR,sp4);
	replace_sstr(c,ibr,sp5);
	replace_sstr(c,iBR,sp5);
	replace_sstr(c,ip,sp4);
	replace_sstr(c,iP,sp4);
	replace_sstr(c,p,sp3);
	replace_sstr(c,P,sp3);
	remove_tags(cc,c);
	dd=cc;
	
	do{
		n=instr(dd,enters);
		in=instr(dd,entersss);
		if (n==-1)n=1000;
		if (in==-1)in=1000;
		if (in<n)n=in;
		if(n<linesize){
			cc=dd+n;
			ee=cc+1;
			cc[0]=0;
			printf("%s\n",dd);
			nn=nn+14.0;
			dd=ee;
		}else{
			n=strlen(dd);
			if(n<linesize){
			printf("%s\n",dd);
			nn=nn+14.0;
			ee=dd+n;
			dd=ee;
			}else{
				strncpy(var2,dd,linesize);
				printf("%s\n",var2);
				nn=nn+14.0;
				ee=dd+linesize;
				dd=ee;
			}
		}
		if (dd[0]==0)nnn=1;
	}while(nnn!=1);
	}else{
		printf("no page or no net?\n");
		exit(1);
	}
	
		
	}





void on_select(){
	char *cc;
	char *ccc;
	char d[600];
	char *dd=d;

	FILE *f1;
	
	cc=file;
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

char *body_start(char *c){
	char *cc=NULL;
	char *ccc;
	cc=strstr(c,"<body>");
	if (cc==NULL) cc=strstr(c,"<BODY>");
	if (cc==NULL) cc=strstr(c,"<body ");

	return cc;
}

char *body_end(char *c){
	char *cc=NULL;
	
	cc=strstr(c,"</body>");
	if (cc==NULL) cc=strstr(c,"</body>");
	if (cc==NULL) cc=strstr(c,"</BODY>");
	if (cc!=NULL) cc[0]=0; 
	return cc;
}

void remove_tags(char *c, char *cc){
	char *ccc=c;
	char *cccc=cc;
	char *ccc1=cc;
	char *cccc1=cc;
	int tim=0;
	strcpy(c,"");
	do{
		cccc1=strstr(cccc,"<");
		if (cccc1!=NULL){
			if (strncmp(cccc1,"<script",7)==0 ){
				cccc=strstr(cccc1,"</script>");
				cccc1=cccc;
			}else{
				if (strncmp(cccc1,"<SCRIPT",7)==0 ){
				cccc=strstr(cccc1,"</SCRIPT>");
				cccc1=cccc;
				}else{
					if (cccc1!=NULL){
			
						ccc1=cccc1+1;
						cccc1[0]=0;
						strcat(c,cccc);
						cccc=strstr(ccc1,">");
						cccc=cccc+1;
						if (cccc[0]=='\0') tim=1;
			
						
					}
				
			}
		}
		}else{
						strcat(c,cccc);
						tim=1;
						}
			
	}while(tim!=1);
	
}

void replace_char(char *c, char cc,char ccc){
	char *cccc=c;
	char *cccc1=c;
	int tim=0;
	do{
		cccc1=strchr(cccc,cc);
		if (cccc1!=NULL){
			cccc=cccc1+1;
			cccc1[0]=ccc;
			cccc1=cccc;
			if (cccc1[0]=='\0') tim=1;
		}else{
			tim=1;
		}
		
	}while(tim!=1);
}

void replace_sstr(char *c, char *cc,char *ccc){
	char *cccc=c;
	char *cccc1=c;
	int i=0;
	int n=0;
	int tim=0;
	do{
		cccc1=strstr(cccc,cc);
		if (cccc1!=NULL){
			cccc=cccc1;
			i=strlen(ccc);
			for(n=0;n<i;n++){
				cccc[0]=ccc[n];
				cccc1=cccc+1;
				cccc=cccc1;
			}

			cccc1=cccc+1;
			if (cccc1[0]=='\0') tim=1;
		}else{
			tim=1;
		}
		
	}while(tim!=1);
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







