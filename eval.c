#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int lists(char *argv);
void PrintList(int sizes);


char labels[50*50];

void main(int argc, char *argv[]){
	int ii;
	char *argvs="(12+12)*3" ;
	printf("%s\n",argvs);
	ii=lists(argvs);
	PrintList(ii);
	}

int lists(char *argv){
    int i;
    int ii=0;
    int iii=0;
    int iiii=0;
    
    for (i = 0;i<strlen(argv); i++) {
		if (argv[i]=='+' || argv[i]=='-' || argv[i]=='*' || argv[i]=='/' || argv[i]=='\\' || argv[i]=='(' || argv[i]==')'){
			if (i!=0 && iiii!=1) {
				labels[ii*50+iii]=0;
				ii++;
				iii=0;
			}
			labels[ii*50+iii]=(char) argv[i];
			labels[ii*50+iii+1]=0;
			ii++;
			iii=0;
			iiii=1;
		}else{
			labels[ii*50+iii]=(char) argv[i];
			iii++;
			iiii=0;
			}
		
    }
	labels[ii*50+iii+1]=0;
	return ii+1;

	}


void PrintList(int sizes)

{
    int i=0;
    
    char *p;
    printf("\n argument number \n",sizes);
    for (i = 0;i<sizes; i++) {
		p=&labels[i*50];
		if (labels[i*50]!=0){
			printf("\n%d = %s",i,p);
			if(labels[i*50]>'0'-1 && labels[i*50]<'9'+1){
				printf("=number\n");
			}else{
				if (labels[i*50]=='+'){
					printf("=sum\n");	
				}else{
					if (labels[i*50]=='-'){
					printf("=sub\n");
					}else{
						if (labels[i*50]=='/'){
							printf("=div\n");
						}else{
							if (labels[i*50]=='\\'){
								printf("=div\n");
							}else{
							if (labels[i*50]=='*'){
								printf("=div\n");
							}else{						
								printf("\n");
								
									
							}
						}
					}
				}
		}
		
		}
    }else{
		printf("\n%d = \n",i);
}
}
	
	printf("\n size %d \n",sizes);
}

