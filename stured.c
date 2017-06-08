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
char text[50];
};

struct nodes{
int count;
node *list;
};


void addNode(nodes *ns1,char *text);
nodes *creatList(char *text);
void printList(nodes *ns1);

nodes *node0;



int main(){
char s1[50];
strcpy (s1,"root");
node0=creatList(s1);
for (int i=0;i<17;i++){
sprintf(s1,"item %d",i);
addNode(node0,s1);
}
printList(node0);
return 0;
}


void addNode(nodes *ns1,char *text){
node *n1=new node;
node *nl;
strcpy(n1->text,text);
n1->nexts=NULL;
nl=ns1->list;
for (int i=0;i<ns1->count-1;i++){
nl=nl->nexts;
}
nl->nexts=n1;
ns1->count=ns1->count+1;
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
nl=ns1->list;
for (int i=0;i<ns1->count;i++){
printf("%s\n",nl->text);
nl=nl->nexts;
}

}









