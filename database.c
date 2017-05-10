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


char table[256];
char table2[270];
char table3[270];
const char *typee[]={"txt","integer","number"};
char ttable[270][34];
char tsizet[270][2];
int iindex=0;


void addInterger(char *e);
void addTxt(char *e,char f);
void addNumber(char *e);
void creatD(char *e);
void creatT(char *e);
void openT();
void valueInteger(char *e);
void listV();
void valueNumber(char *e);
void valueTxt(char *e,char f);
void recordS();
void listF();
void printLL();
void selectx();
int loadTxt(int f1,char s);
int loadNumber(int f1);
int loadInteger(int f1);


int main(int argc, char ** argv){
int f1;
if (argc==1){
openT();
printf ("%s\n",table);	
exit(0);
}

char *c=argv[1];

if (argc>3){
if (0==strcmp("add\0",c)){
char *d=argv[2];

if (0==strcmp("record\0",d)){
openT();
listF();
if(argc==iindex+3){
int iiii=0;
for(iiii=0;iiii<iindex;iiii++){
if(tsizet[iiii][0]==1) addInterger(argv[iiii+3]); 
if(tsizet[iiii][0]==2) addNumber(argv[iiii+3]); 
if(tsizet[iiii][0]==0) addTxt(argv[iiii+3],tsizet[iiii][1]); 
}
}else{
printf("error:token");
}
exit(0);
}
}
}


if (argc==2){
if (0==strcmp("select\0",c)){
openT();
listF();
selectx();
exit(0);
}


if (0==strcmp("table\0",c)){
openT();
listF();
printLL();
exit(0);
}
}



if (argc==3){
char *d=argv[2];
if (0==strcmp("list\0",c)){
if (0==strcmp("value\0",d)){
listV();
exit(0);
}

}
if (0==strcmp("record\0",c)){
if (0==strcmp("size\0",d)){
recordS();
exit(0);
}

}



}

if (argc==6){
int gg=0;
char *d=argv[2];
char *e=argv[3];
char *f=argv[4];
char *g=argv[5];
if (0==strcmp("add\0",c)){
if (0==strcmp("value\0",d)){

if (0==strcmp("txt\0",f)){
openT();
sscanf(g,"%d",&gg);
valueTxt(e,(char) gg);
exit(0);
}

}
}
}


if (argc==5){
char *d=argv[2];
char *e=argv[3];
char *f=argv[4];


if (0==strcmp("add\0",c)){
if (0==strcmp("value\0",d)){

if (0==strcmp("number\0",f)){
openT();

valueNumber(e);
exit(0);
}



if (0==strcmp("integer\0",f)){
openT();

valueInteger(e);
exit(0);
}



}
}
}

if (argc==4){

char *d=argv[2];
char *e=argv[3];


if (0==strcmp("open\0",c)){
if (0==strcmp("database\0",d)){
creatD(e);
exit(0);
}

if (0==strcmp("table\0",d)){
creatT(e);
exit(0);
}


}


if (0==strcmp("creat\0",c)){

if (0==strcmp("table\0",d)){
creatT(e);
exit(0);
}



if (0==strcmp("database\0",d)){
creatD(e);
exit(0);
}
}
}
 

return 0;
}




void creatD(char *e){
int f1;
mkdir(e,0777);
chmod(e,0777);
f1=open ("database.dat" , O_WRONLY | O_CREAT );
write(f1,e,strlen(e)+1);
close (f1);
chmod("database.dat",0777);
}



void creatT(char *e){
int f1;
int f2;
int f3;
f1=open ("table.dat" , O_WRONLY | O_CREAT );
write(f1,e,strlen(e)+1);
close (f1);
chmod("table.dat",0777);
}


void openT(){
int f1;
int f2;
int f3;
char *p;
f1=open ("database.dat" , O_RDONLY);
f2=read(f1,&table,252);
close (f1);
table[f2]=0;
f2=strlen(table);
table[f2]='/';
p=&table[f2+1];
f1=open ("table.dat" , O_RDONLY );
f3=read(f1,p,254-f2);
close (f1);
table[f2+1+f3]=0;
strcpy(table2,table);
strcpy(table3,table);
strcat(table2,".table");
strcat(table3,".dat");
}


void valueInteger(char *e){
int f1;
char *p;
char b=1;
char b2=sizeof(long);
p=&table2[0];
f1=open (p , O_WRONLY | O_APPEND | O_CREAT );
write(f1,e,32);
write(f1,&b,1);
write(f1,&b2,1);
close (f1);
chmod(p,0777);
}


void valueNumber(char *e){
int f1;
char *p;
char b=2;
char b2=sizeof(long double);
p=&table2[0];
f1=open (p , O_WRONLY | O_APPEND | O_CREAT );
write(f1,e,32);
write(f1,&b,1);
write(f1,&b2,1);
close (f1);
chmod(p,0777);
}

void valueTxt(char *e,char f){
int f1;
char *p;
char b=0;
char b2=f;
p=&table2[0];
f1=open (p , O_WRONLY | O_APPEND | O_CREAT );
write(f1,e,32);
write(f1,&b,1);
write(f1,&b2,1);
close (f1);
chmod(p,0777);
}


void listV(){
int f1;
int f2;
int f3;
int f4;
char e[36];
char *p;
char b=1;
char b2=sizeof(int);
openT();
p=&table2[0];
f1=open (p , O_RDONLY);
if(f1!=-1){
printf("%-32s %-8s %4s\n","table name:","var:","size:");
do{
f2=read(f1,e,32);
e[33]=0;
f3=read(f1,&b,1);
f4=read(f1,&b2,1);
if (f4!=0) printf("%-32s %-8s %3d\n",e,typee[b],(int) b2);
}while (f4!=0);
close (f1);
}else{
printf ("error:");
}
}

void recordS(){
int tsum=0;
int t=0;
int f1;
int f2;
int f3;
int f4;
char e[36];
char *p;
char b=1;
char b2=sizeof(int);
openT();
p=&table2[0];
f1=open (p , O_RDONLY);
if(f1!=-1){
do{
f2=read(f1,e,32);
f3=read(f1,&b,1);
f4=read(f1,&b2,1);
if (f4!=0) {
t=(int)b2;
tsum=tsum+t;
}
}while (f4!=0);
close (f1);
printf("%d\n",tsum);
}else{
printf ("error:");
}
}


void listF(){
int indexs=0;
int f1;
int f2;
int f3;
int f4;
char e[36];
char *p;
char b=1;
char b2=sizeof(int);
openT();
p=&table2[0];
f1=open (p , O_RDONLY);
if(f1!=-1){
do{
f2=read(f1,e,32);
e[33]=0;
f3=read(f1,&b,1);
f4=read(f1,&b2,1);
if (f4!=0) {
strcpy(ttable[indexs],e);
tsizet[indexs][0]=b;
tsizet[indexs][1]=b2;
indexs++;
}
}while (f4!=0);
close (f1);
}else{
printf ("error:");
}
iindex=indexs;
}


void printLL(){
int i;
printf("%-32s %4s %4s\n","table name:","var:","size:");
for (i=0;i<iindex;i++)printf("%-32s %4d %4d\n",ttable[i],(int)tsizet[i][0],(int)tsizet[i][1]);
}


void addInterger(char *e){
long gg=0;
int f1;
int f2;
int f3;
sscanf(e,"%lu",&gg);
f1=open (&table3[0] , O_WRONLY | O_CREAT | O_APPEND );
write(f1,&gg,sizeof(long));
close (f1);
chmod(&table3[0],0777);
}



void addNumber(char *e){
long double gg=0;
int f1;
int f2;
int f3;
sscanf(e,"%lf",&gg);
f1=open (&table3[0] , O_WRONLY | O_CREAT | O_APPEND );
write(f1,&gg,sizeof(long double));
close (f1);
chmod(&table3[0],0777);
}


void addTxt(char *e,char f){
int f1;
long f2=(long) f;
int f3;
f1=open (&table3[0] , O_WRONLY | O_CREAT | O_APPEND );
write(f1,e,f2);
close (f1);
chmod(&table3[0],0777);
}


void selectx(){
int indexs=0;
int f1;
int f2;
int f3;
int f4;
char e[36];
char *p;
char b=1;
char b2=0;
openT();
f1=open (&table3[0] , O_RDONLY);
if(f1!=-1){
do{
for(f4=0;f4<iindex;f4++){
if(tsizet[f4][0]==1) f3=loadInteger(f1);
if(tsizet[f4][0]==2) f3=loadNumber(f1);
if(tsizet[f4][0]==0) f3=loadTxt(f1,tsizet[f4][1]);
if(f3==0)f4=iindex;
if (f4==iindex-1){
printf("\n");
}else{
printf(":");
}
}
}while(f3!=0);

close (f1);
}else{
printf ("error:");
}
}


int loadInteger(int f1){
long l=0;
int f2=0;
f2=read(f1,&l,sizeof(long));
printf("%lu",l);
return f2;
}

int loadNumber(int f1){
long double l;
int f2=0;
f2=read(f1,&l,sizeof(long double));
printf("%lf",l);
return f2;
}

int loadTxt(int f1,char s){
char l[270];
int ss=(int)s;
int f2=0;
f2=read(f1,&l,ss);
printf("%s",l);
return f2;
}












