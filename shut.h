#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


//g++ -o out gimage.cpp  `pkg-config gtk+-3.0 --cflags --libs` 

GtkBuilder      *builder; 
GtkWidget       *window;
GtkWidget       *bt1;
GtkWidget       *bt2;
GtkWidget       *bt3;
GtkWidget       *bt4;
void on_destroy();
void on_acivate();
void on_f1();
void on_f2();
void on_f3();
void on_f4();




void on_acivate(){
	;
}



void on_destroy(){
	gtk_main_quit();
}



void on_f1(){
	system("sudo shutdown now");
}

void on_f2(){
	system("sudo shutdown -r now");
}


void on_f3(){
	system("sudo shutdown -H now");
}

void on_f4(){
	system("xfce4-session-logout -l");
}











