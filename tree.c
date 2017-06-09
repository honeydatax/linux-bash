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


struct node {
node *nexts;
node *container;
char text[50];
};


node *addNode(node *ns1,char *text);
void addSubNode(node *ns1,char *text);
node *creatList(char *text);
void printList(node *ns1);


void addStack(node **stacks,node *i);
void startStack(node **stacks);
int sizeStack();
node *popStack(node **stacks);
void subsub(int i);


int count=0;
node *node0;



int main(){
int a=1;
char s1[50];
node *n1;
node *n2;
strcpy (s1,"root");
node0=creatList(s1);
for (int i=0;i<4;i++){
sprintf(s1,"item %d",i);
n1=addNode(node0,s1);
for (int ii=0;ii<a;ii++){
sprintf(s1,"sub item %d",ii);
n2=addNode(n1,s1);
for (int iii=0;iii<a;iii++){
sprintf(s1,"sub item %d",iii);
addNode(n2,s1);
}
}
a++;
}
printList(node0);
return 0;
}


node *addNode(node *ns1,char *text){
node *n1=new node;
node *nl;
node *nl2;
strcpy(n1->text,text);
n1->nexts=NULL;
n1->container=NULL;
nl=ns1->container;
if (nl==NULL)ns1->container=n1;
else{
do{
nl2=nl;
nl=nl->nexts;
}while(nl!=NULL);
nl2->nexts=n1;
}
return n1;
}



node *creatList(char *text){
node *ns1=new node;
strcpy(ns1->text,text);
ns1->nexts=NULL;
ns1->container=NULL;
return ns1;
}


void printList(node *ns1){
int i4=0;
int i3=0;
int i2=0;
node *nl;
node *nl1;
node *nl2;
node *stack[250];
startStack(stack);
printf("%s\n",ns1->text);
nl=ns1->container;
if (nl!=NULL){
do{
i2=sizeStack();
if (nl!=NULL){
subsub(i2);
printf("%s\n",nl->text);
}
if(nl->container!=NULL){
addStack(stack,nl);
nl=nl->container;
}else{
nl=nl->nexts;
}
i2=sizeStack();
if (nl==NULL && i2>0){
do{
nl=popStack(stack);
nl=nl->nexts;
i4=0;
if (nl!=NULL)i4=1;
i2=sizeStack();
if (i2<1)i4=1;
}while(i4!=1);
}
i3=0;
if (nl==NULL && i2<1)i3=1;
}while(i3!=1);
}
}



void addStack(node **stacks,node *i){
count++;
stacks[count]=i;
}


void startStack(node **stacks){
count=0;
}

int sizeStack(){
return count;
}

node *popStack(node **stacks){
node *i=NULL;
i=stacks[count];
if (count<1)i=NULL;
if (count>0)count--;
return i;
}


void subsub(int i){
for (int ii=0;ii<i+1;ii++)printf("--");
}

























