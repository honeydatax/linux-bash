#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int lists(char *argv);
void PrintList(int sizes);
void priorityList(int sizes);
void priorityString(int sizes);
void clears(int p1,int size);
double subs(double d1,double d2);
double sums(double d1,double d2);
double muls(double d1,double d2);
double divs(double d1,double d2);

char labels[50*50];

void main(int argc, char *argv[]){
	int ii;
	char argvs[100];
	argvs[0]=0;
	for (ii=1;ii<argc;ii++){
		strcat(argvs,argv[ii]);
	}

	printf("\e[0;43;30m\n");	
	printf("%s\n",argvs);
	ii=lists(argvs);
	priorityList(ii);
	priorityString(ii);
	PrintList(ii);
	}

int lists(char *argv){
    int i;
    int ii=0;
    int iii=0;
    int iiii=0;
    int ti=0;
    
    for (i = 0;i<strlen(argv); i++) {
		if (argv[i]=='+' || argv[i]=='-' || argv[i]=='*' || argv[i]=='/' || argv[i]=='\\' || argv[i]=='(' || argv[i]==')'){
			if (i!=0 && iiii!=1) {
				labels[ii*50+iii]=0;
				ii++;
				iii=0;
				ti++;
			}
			labels[ii*50+iii]=(char) argv[i];
			labels[ii*50+iii+1]=0;
			ii++;
			iii=0;
			iiii=1;
			ti++;
		}else{
			labels[ii*50+iii]=(char) argv[i];
			iii++;
			iiii=0;
			ti++;
			}
		
    }
	labels[ii*50+iii+1]=0;
	return ti+1;

	}


void PrintList(int sizes)

{
    int i=0;
    int ppi=0;
    double d=0.00;
    double dd=0.00;
    char *p;
    char *p1;
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
		if (labels[i*50]!=0){
			if(labels[i*50]>'0'-1 && labels[i*50]<'9'+1){
				if (i==0) {
					d=atof(p);
				
				
			}}else{
				if (labels[i*50]=='+'){
					p1=&labels[(i+1)*50];
					dd=d;
					d=sums(d,atof(p1));	
					printf("%f + %s=%f\n",dd,p1,d);
					ppi=1;
				}else{
					if (labels[i*50]=='-'){
					p1=&labels[(i+1)*50];
					dd=d;
					d=subs(d,atof(p1));	
					printf("%f - %s=%f\n",dd,p1,d);
					ppi=1;
					}else{
						if (labels[i*50]=='/'){
						}else{
							if (labels[i*50]=='\\'){
								;
							}else{
							if (labels[i*50]=='*'){
								;
							}else{						
								printf("\n error !!!!!!!!!\n");
									
							}
						}
					}
				}
		}
		
		}
    }

i=i+ppi;
ppi=0;
}	
	printf("\n = %f \n",d);
}

void priorityList(int sizes)
{
    int i=0;
    int ppi=0;
    double d=0.00;
    double dd=0.00;
    char *p;
    char *p1;
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
		if (labels[i*50]!=0){
			if(labels[i*50]>'0'-1 && labels[i*50]<'9'+1){
				
					d=atof(p);
				
				
			}else{
				if (labels[i*50]=='+'){
					d=0.00;
				}else{
					if (labels[i*50]=='-'){
						d=0.00;
					}else{
						if (labels[i*50]=='/'){
							p1=&labels[(i+1)*50];
							dd=d;
							printf("%f / %f ",d,atof(p1));
							d=divs(d,atof(p1));	
							printf(" = %f \n",d);	
							clears(i-1,50*3);
							labels[i*50]='+';
							labels[(i-1)*50]='0';
							p1=&labels[(i+1)*50];
							sprintf(p1,"%f",d);
							
						}else{
							if (labels[i*50]=='\\'){
							p1=&labels[(i+1)*50];
							dd=d;
							printf("%f / %f ",d,atof(p1));
							d=divs(d,atof(p1));
							printf(" = %f\n",d);	
							clears(i-1,50*3);
							labels[i*50]='+';
							labels[(i-1)*50]='0';
							p1=&labels[(i+1)*50];
							sprintf(p1,"%f",d);
							}else{
							if (labels[i*50]=='*'){
							p1=&labels[(i+1)*50];
							dd=d;
							printf("%f * %f ",d,atof(p1));
							d=muls(d,atof(p1));	
							printf(" = %f \n",d);
							clears(i-1,50*3);
							labels[i*50]='+';
							labels[(i-1)*50]='0';
							p1=&labels[(i+1)*50];
							sprintf(p1,"%f",d);
							}else{						
								printf("\n error !!!!!!!!!\n");
									
							}
						}
					}
				}
		}
		
		}
    }

i=i+ppi;
ppi=0;
}	
}

void priorityString(int sizes)
{
    int i=0;
    int ppi=0;
    double d=0.00;
    double dd=0.00;
    char *p;
    char *p1;
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
		printf("%s",p);
	}
	printf("\n");
}

void clears(int p1,int size){
		int i;
		for (i=0;i<size;i++){
			labels[(p1*50)+i]=0;
		}
	}

double sums(double d1,double d2){
	return d1+d2;
}

double subs(double d1,double d2){
	return d1-d2;
}

double muls(double d1,double d2){
	return d1*d2;
}

double divs(double d1,double d2){
	return d1/d2;
}
