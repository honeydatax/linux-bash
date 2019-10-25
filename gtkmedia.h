#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


//g++ -o out gimage.cpp  `pkg-config gtk+-3.0 --cflags --libs` 

GtkBuilder      *builder; 
GtkWidget       *window;
GtkFileChooser *file1;
void on_destroy();
void on_select();
void on_acivate();
void openfile(char *cc);


void on_close(){

}


void on_acivate(){
}


void on_select(){
	char *cc;
	char *icc;
	
	file1=GTK_FILE_CHOOSER(window);
	cc=gtk_file_chooser_get_filename(file1);
	if (cc!=NULL){
		icc=strstr(cc,".");
		if (icc!=NULL) openfile(cc);
	}


}




void on_destroy(){
	gtk_main_quit();
}



void openfile(char *cc){
	char ccc[100];
	char *icc=ccc;
	strcpy(icc,"exo-open ");
	strcat(icc,cc);
	system(icc);
}







