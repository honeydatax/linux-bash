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
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>


void addStack(int *stacks,int i);
void startStack(int *stacks);
void printStack(int *stacks);
int popStack(int *stacks);


int main(){
int *stack=(int *)malloc(250*sizeof(int));
int a=0;
addStack(stack,20);
addStack(stack,40);
addStack(stack,60);
addStack(stack,80);
addStack(stack,1000);
printStack(stack);
for (int i=0;i<4;i++){
a=popStack(stack);
printf("pop %d\n",a);

}
printStack(stack);
free(stack);
return 0;
}


void addStack(int *stacks,int i){
if (stacks[2]!=1010)startStack(stacks);
stacks[stacks[0]+3]=i;
stacks[0]++;
}


void startStack(int *stacks){
stacks[0]=0;
stacks[1]=0;
stacks[2]=1010;
}

void printStack(int *stacks){
if (stacks[2]!=1010)startStack(stacks);
printf("------------------stack\n");
for (int i=0;i<stacks[0];i++)printf("%d\n",stacks[i+3]);
}

int popStack(int *stacks){
int i=0;
if (stacks[2]!=1010)startStack(stacks);
else{
i=stacks[stacks[0]+2];
stacks[stacks[0]+2]=0;
if (stacks[0]>0)stacks[0]--;
else i=0;
}
return i;
}













