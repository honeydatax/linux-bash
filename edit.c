#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define linesize 60
#define nlines 16

	int i1=0;
	long l;
	long ll;
	char *cursor;
	char *ddi;
	int count=0;
	int sizes=0;
	int large=0;
	char toadd[3];
	char varname[1864000]; 
	char varname1[1864000]; 
	char var1[linesize+20];
	char var2[linesize+20];
	char *p[8000];
	char *aargv;
	time_t rawtime;
	struct termios oldt,newt;
	struct tm *timeinfo;
	struct timeval start, ends;
	FILE *fp;
	

void on_selection();
void on_select();
int instr(char *c,char *cc);
void insert(char c);
void deletec();
void leftc();
void rigthc();
void upc();
void downc();
void pagedownc();
void pageupc();

int main(int argc, char *argv[])
{
	char a=0;
	int b=0;

	tcgetattr(fileno(stdin),&oldt);
	memcpy(&newt,&oldt,sizeof(struct termios));
	newt.c_lflag &= ~(ECHO|ICANON);
	newt.c_cc[VTIME]=0;
	newt.c_cc[VMIN]=0;
	tcsetattr(fileno(stdin),TCSANOW,&newt);


	printf ("\033c");
	printf ("\e[0;34;47m");
	printf ("\e[1;1f editor press ? to exit");
	printf ("\e[2;1f");
	if (argc<2){
		goto escapes;	
	}
	aargv=argv[1];
	on_select();
	//strcpy(varname,"hello world.!");
	p[0]=varname;
	cursor=varname;
	printf ("\e[2;1f");
	insert('|');
	count=0;
	sizes=0;
	large=0;
	printf ("\e[2;1f");
	on_selection();
	
	do{
		a=fgetc(stdin);
		

		if (a!=0 && a!=255 && a!=127 && a!=8 && a!='~' && a!='|'){
	
			if (a==27){
				a=fgetc(stdin);

				if (a=='O'){
					a=fgetc(stdin);
				if (a=='H'){
						upc();//home
					}
				}
				if (a=='F'){
					downc();//end
				}

				if(a==91){
					a=fgetc(stdin);
					if(a==51){
						a=fgetc(stdin);
						if(a==126){
							deletec();//delete
							a=255;
						}
					}
					if(a==54){
						a=fgetc(stdin);
						if(a==126){
							pagedownc();//page down
						}
					}

					if(a==53){
						a=fgetc(stdin);
						if(a==126){
							pageupc();//page up
						}
					}

						
					
					if(a==50){
						a=fgetc(stdin);
						if(a==126){
							deletec();//delete
							a=255;
						}

						
					}

					if(a==65){
						upc();//up
					}
					
					if(a==66){
						downc();//down
					}

					if(a==68){
						leftc();//left
					}
					if(a==67){
						rigthc();//rigth
					}
					
					
				}
				a=255;
			}else{
				if (a!=255 && a!=8 && a!=0)insert(a);
				if(a==127 || a==8){
					deletec();//delete
					a=255;

				}

			}
			//printf("%c",a);
			if (a!=255){
			printf ("\e[2;1f");
			on_selection();
			cursor=cursor+1;
			}


		}
		if(a==127 || a==8){
			deletec();//delete
			a=255;
		}


	}while(a!=63);
	escapes: 
	oldt.c_lflag|=ECHO|ICANON;
	tcsetattr(fileno(stdin),TCSANOW,&oldt);
	printf ("\033c");
	return 0;
}

void gotoxy(int x,int y){
	printf("\e[%d;%d",x,y);
	/*
			if (var222[0]=='\0'){
					sizes++;
					p[sizes]=dd;
			}else{
				sizes--;
				if (sizes<0)sizes=0;
				dd=p[sizes];
			}
		
		*/
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

	dd=p[sizes];
	p[sizes+1]=varname+strlen(varname);
	count=0;
	do{
		n=instr(dd,enters);
		in=instr(dd,entersss);
		if (n==-1)n=1000;
		if (in==-1)in=1000;
		if (in<n)n=in;
		if(n<linesize){
			cc=dd+n;
			ee=cc+1;
			memset(var1,32,linesize);
			strncpy(var1,dd,n);
			var1[linesize]=0;
			printf("%s\n",var1);
			dd=ee;
		}else{
			n=strlen(dd);
			if(n<linesize){
			memset(var1,32,linesize);
			var1[linesize]=0;
			strncpy(var1,dd,n);
			printf("%s\n",var1);
			ee=dd+n;
			dd=ee;
			}else{
				strncpy(var1,dd,linesize);
				printf("%s\n",var1);
				var1[linesize]=0;
				ee=dd+linesize;
				dd=ee;
			}
		}
		count++;
		
		i1=0;
		if (dd[0]==0){
			ddi=dd-1;
			p[sizes+1]=dd-1;
			i1=1;
		}else{
			ddi=dd;
			p[sizes+1]=dd;
			i1=0;
		}
		
		if (count>nlines || dd[0]==0)in=1;
	}while(in!=1);
	p[sizes+1]=dd;
	memset(var1,32,linesize);
	var1[linesize]=0;
	for (nnn=count;nnn<nlines;nnn++)printf("%s\n",var1);
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


void insert(char c){
	l=(long)(void*)varname;
	ll=(long)(void*)cursor;
	l=ll-l;
	strncpy(varname1,varname,l);
	varname1[l]=c;
	varname1[l+1]=0;
	strcat(varname1,cursor);
	strcpy(varname,varname1);
}


void deletec(){
	if (cursor>p[sizes]){
		l=(long)(void*)varname;
		ll=(long)(void*)cursor;
		l=ll-l;
		strncpy(varname1,varname,l-1);
		varname1[l-1]=0;
		strcat(varname1,cursor);
		strcpy(varname,varname1);
		printf ("\e[2;1f");
		on_selection();
		cursor--;
	}
}

void leftc(){
	char bb;
	char aa;
	if (cursor>p[sizes]){
		l=(long)(void*)varname;
		ll=(long)(void*)cursor;
		l=ll-l;
		aa=varname[l-1];
		bb=varname[l];
		varname[l-1]=bb;
		varname[l]=aa;
		printf ("\e[2;1f");
		on_selection();
		cursor--;
	}
}


void rigthc(){
	char bb;
	char aa;
	
	if ((cursor<(p[sizes+1]-1) && i1==0) || (cursor<=(p[sizes+1]-1) && i1==1)){
		l=(long)(void*)varname;
		ll=(long)(void*)cursor;
		l=ll-l;
		aa=varname[l+1];
		bb=varname[l];
		varname[l+1]=bb;
		varname[l]=aa;
		printf ("\e[2;1f");
		on_selection();
		cursor++;
	}
	
}

void upc(){
	char bb;
	char aa;
	cursor++;
	deletec();
	cursor=cursor-60;
	if ((cursor<(p[sizes+1]-1) && i1==0) || (cursor<=(p[sizes+1]-1) && i1==1)){
		cursor=p[sizes];
		if(i1==1)cursor=p[sizes];
	}
	insert('|');
	printf ("\e[2;1f");
	on_selection();
}

void downc(){
	char bb;
	char aa;
	cursor++;
	deletec();
	cursor=cursor+60;
	if (cursor>=p[sizes+1] && i1==0) cursor=p[sizes+1]-1;
	if (cursor>p[sizes+1] && i1==1) cursor=p[sizes+1];
	insert('|');
	printf ("\e[2;1f");
	on_selection();
	//cursor++;
	//if (cursor<p[sizes+1]) cursor=p[sizes+1]-1;
}


void pageupc(){
	cursor++;
	deletec();
	sizes--;
	if (sizes<0)sizes=0;
	cursor=p[sizes];
	insert('|');
	printf ("\e[2;1f");
	on_selection();
}

void pagedownc(){
	cursor++;
	deletec();
	cursor=p[sizes+1]-1;
	if (i1!=1 && sizes<7999){
		sizes++;
		p[sizes]=ddi;
	}
	insert('|');
	printf ("\e[2;1f");
	on_selection();

}













