#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void msgbox();
int count=0;


int main(int argc, char *argv[]){
		
		msgbox();
		if (argc>2)for (count=atoi(argv[1]);count<atoi(argv[2]);count++) printf("%d\n",count);
		if (argc<3)for (count=0;count<atoi(argv[1]);count++) printf("%d\n",count);
return 0;
}

void msgbox(){
	printf ("\e[0;34;47m");
}









