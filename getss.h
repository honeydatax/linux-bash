 #include <stdio.h>
char *gets(char *c);

char *gets(char *c){
	return fgets(c,80,stdin);
}