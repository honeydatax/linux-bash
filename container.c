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

struct nodes{
int count;
node *list;
};


node *addNode(nodes *ns1,char *text);
void addSubNode(node *ns1,char *text);
nodes *creatList(char *text);
void printList(nodes *ns1);

nodes *node0;



int main(){
int a=1;
char s1[50];
node *n1;
strcpy (s1,"root");
node0=creatList(s1);
for (int i=0;i<4;i++){
sprintf(s1,"item %d",i);
n1=addNode(node0,s1);
for (int ii=0;ii<a;ii++){
sprintf(s1,"sub item %d",ii);
addSubNode(n1,s1);
}
a++;
}
printList(node0);
return 0;
}


node *addNode(nodes *ns1,char *text){
node *n1=new node;
node *nl;
strcpy(n1->text,text);
n1->nexts=NULL;
n1->container=NULL;
nl=ns1->list;
for (int i=0;i<ns1->count-1;i++){
nl=nl->nexts;
}
nl->nexts=n1;
ns1->count=ns1->count+1;
return n1;
}

void addSubNode(node *ns1,char *text){
node *n1=new node;
node *nl;
node *nl2;
strcpy(n1->text,text);
n1->nexts=NULL;
nl=ns1->container;
if (nl==NULL)ns1->container=n1;
else{
do{
nl2=nl;
nl=nl->nexts;
}while(nl!=NULL);
nl2->nexts=n1;
}
}


nodes *creatList(char *text){
nodes *ns1=new nodes;
node *n1=new node;
strcpy(n1->text,text);
n1->nexts=NULL;
ns1->count=1;
ns1->list=n1;
return ns1;
}


void printList(nodes *ns1){
node *nl;
node *nl1;
node *nl2;
nl=ns1->list;
for (int i=0;i<ns1->count;i++){
printf("%s\n",nl->text);
if (nl->container!=NULL){
nl1=nl->container;
do{
printf("-----%s\n",nl1->text);
nl1=nl1->nexts;
}while(nl1!=NULL);
}
nl=nl->nexts;
}

}









