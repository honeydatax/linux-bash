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


int imuls(int n1,int n2);

int main(){
int a=1;
for (int n=0;n<31;n++){
printf (" %d\n",a);
a=imuls(a,2);
}
return 0;
}




int imuls(int n1,int n2){
int nn=n1*n2;
return nn;
}






































