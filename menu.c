#include <stdio.h>
#include <stdlib.h>


void item(char *strs);

int main(int argc, char ** argv){
int a=0,i=0,n=0;
char *c=" ";
char *d="menu";
char *e="cancel";

item (c);
item (d);
printf("%d ",a);
item (e);
a++;
for(i=1;i<argc;i++){
printf("%d ",a);
item (argv[i]);
a++;
}

scanf("%d",&n);

return n;
}

void item(char *strs){
printf("%s\n",strs); 
}













