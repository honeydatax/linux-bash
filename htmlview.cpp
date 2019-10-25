#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

//g++ -o out gimage.cpp  `pkg-config gtk+-2.0 --cflags --libs`
int errorss;
char labels[50*50];
GtkWidget *entry2;
GtkWidget *entry;
char argsvv[1000];
char *argsvvv;
char files[]="labelhtml.dat";
char *file=files;
char varname[864000]; 
char varname2[864000]; 
char var1[512];
int linesize=50;
char var2[98];
char *aargv;
char aargvv[]="http://www.planet-source-code.com";
char aargvvv[1000];
char *body_start(char *c);
char *body_end(char *c);
void remove_tags(char *c, char *cc);
void on_selection();
void on_select();
void replace_sstr(char *c, char *cc,char *ccc);
int instr(char *c,char *cc);
void replace_char(char *c, char cc,char ccc);



static void enter_callback() 
                            
{
  const gchar *entry_text;
  char *c=varname;
  char *cc=varname2;
  char *ccc=var1;
  
  entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
  sprintf(argsvv,"%s",entry_text);
  aargv=argsvv;
  on_selection();
  gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(entry2)),varname2,-1);
}

int main( int   argc,
          char *argv[] )
{


    GdkColor color1;
    GtkWidget *window;
    GtkWidget *vbox, *hbox;
    GtkWidget *layout1;
    GtkWidget *button;
    GtkWidget *check;
    gint tmp_pos;
	gtk_init (&argc, &argv);
    
    color1.red=56000;
    color1.green=56000;
    color1.blue=56000;
	/* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 620, 340);
    gtk_window_set_title (GTK_WINDOW (window), "label html");
    g_signal_connect (window, "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect_swapped (window, "delete-event",
                              G_CALLBACK (gtk_widget_destroy), 
                              window);
	layout1=gtk_layout_new(FALSE, 0);
    vbox = gtk_vbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_container_add (GTK_CONTAINER (vbox), layout1);
    gtk_widget_show (vbox);
    gtk_widget_show (layout1);
    
    entry = gtk_entry_new ();
    entry2 = gtk_text_view_new ();
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(entry2)),"",-1);
	
    gtk_entry_set_max_length (GTK_ENTRY (entry), 550);
    
    g_signal_connect (entry, "activate",
		      G_CALLBACK (enter_callback),
		      entry);
    gtk_entry_set_text (GTK_ENTRY (entry), "http://localhost:8080/main.html");
    tmp_pos = GTK_ENTRY (entry)->text_length;
    gtk_editable_insert_text (GTK_EDITABLE (entry), "", -1, &tmp_pos);
    
    gtk_editable_select_region (GTK_EDITABLE (entry),
			        0, GTK_ENTRY (entry)->text_length);
    
    gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX (vbox), entry2, TRUE, TRUE, 0);
	
	gtk_widget_modify_text(window,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_bg(window,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_fg(window,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_base(window,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_bg(entry,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_bg(entry2,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_fg(entry,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_fg(entry2,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_base(entry,GTK_STATE_NORMAL,&color1);
	gtk_widget_modify_base(entry2,GTK_STATE_NORMAL,&color1);
    gtk_widget_show (entry);
    gtk_widget_show (entry2);

    hbox = gtk_hbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (vbox), hbox);
    gtk_widget_show (hbox);
   
     
     
    button = gtk_button_new_with_label ("download");
    g_signal_connect_swapped (button, "clicked",
			      G_CALLBACK (enter_callback),
			     entry);
    gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
    gtk_widget_set_can_default (button, TRUE);
    gtk_widget_grab_default (button);
    gtk_widget_modify_base(button,GTK_STATE_NORMAL,&color1);
    gtk_widget_modify_fg(button,GTK_STATE_NORMAL,&color1);
    gtk_widget_modify_bg(button,GTK_STATE_NORMAL,&color1);
   
    gtk_widget_show (button);
    gtk_widget_set_size_request (GTK_WIDGET (entry2), 620, 200);
    gtk_widget_show (window);

    gtk_main();

    return 0;
}

void on_selection(){
	char *c1;
	char br[]="<br>";
	char BR[]="<BR>";
	char ibr[]="</br>";
	char iBR[]="</BR>";
	char td[]="<td>";
	char TD[]="<TD>";
	char iTD[]="</TD>";
	char itd[]="</td>";
	char th[]="<th>";
	char TH[]="<TH>";
	char ith[]="</th>";
	char iTH[]="</TH>";
	char p[]="<p>";
	char P[]="<P>";
	char ip[]="</p>";
	char iP[]="</P>";
	char sp1[]="\n";
	char sp2[]="\r\n";
	char sp3[]=" \r\n";
	char sp4[]="  \r\n";
	char sp5[]="   \r\n";
	char tb1[]="\t";
	char tb2[]=" \t";
	char tb3[]="  \t";
	char tb4[]="   \t";
	char tb5[]="    \t";
	int n=0;
	int nnn=0;
	int in=0;
	char *dd;
	char *ee;
	float nn=20.0f;
	char *c=varname;
	char *cc=varname2;
	char enterss[]="\r";
	char *entersss=enterss;
	char enter[]="\n";
	char *enters=enter;
	strcpy(var1,"curl -s ");
	strcat(var1,aargv);
	strcat(var1," > ");
	strcat(var1,file);
	system(var1);
	on_select();
	c1=body_start(c);
	if (c1!=NULL){
	c=c1;
	body_end(c);
	replace_char(c,'\n',' ');
	replace_char(c,'\r',' ');
	replace_char(c,'\t',' ');
	replace_sstr(c,td,tb4);
	replace_sstr(c,TD,tb4);
	replace_sstr(c,itd,tb5);
	replace_sstr(c,iTD,tb5);
	replace_sstr(c,th,sp4);
	replace_sstr(c,TH,sp4);
	replace_sstr(c,ith,sp5);
	replace_sstr(c,iTH,sp5);
	replace_sstr(c,br,sp4);
	replace_sstr(c,BR,sp4);
	replace_sstr(c,ibr,sp5);
	replace_sstr(c,iBR,sp5);
	replace_sstr(c,ip,sp4);
	replace_sstr(c,iP,sp4);
	replace_sstr(c,p,sp3);
	replace_sstr(c,P,sp3);
	remove_tags(cc,c);
	dd=cc;
	
	}

	
		
	}





void on_select(){
	char *cc;
	char *ccc;
	char d[600];
	char *dd=d;

	FILE *f1;
	
	cc=file;
	if (cc!=NULL){
		ccc=varname;
		strcpy(ccc,"");
		f1=fopen(cc,"r");
		do{
			fgets(dd,599,f1);
			strcat(ccc,dd);
			
			
		}while(!feof(f1));

		fclose(f1);
		
		
		

	}
}

char *body_start(char *c){
	char *cc=NULL;
	char *ccc;
	cc=strstr(c,"<body>");
	if (cc==NULL) cc=strstr(c,"<BODY>");
	if (cc==NULL) cc=strstr(c,"<body ");

	return cc;
}

char *body_end(char *c){
	char *cc=NULL;
	
	cc=strstr(c,"</body>");
	if (cc==NULL) cc=strstr(c,"</body>");
	if (cc==NULL) cc=strstr(c,"</BODY>");
	if (cc!=NULL) cc[0]=0; 
	return cc;
}

void remove_tags(char *c, char *cc){
	char *ccc=c;
	char *cccc=cc;
	char *ccc1=cc;
	char *cccc1=cc;
	int tim=0;
	strcpy(c,"");
	do{
		cccc1=strstr(cccc,"<");
		if (cccc1!=NULL){
			if (strncmp(cccc1,"<script",7)==0 ){
				cccc=strstr(cccc1,"</script>");
				cccc1=cccc;
			}else{
				if (strncmp(cccc1,"<SCRIPT",7)==0 ){
				cccc=strstr(cccc1,"</SCRIPT>");
				cccc1=cccc;
				}else{
					if (cccc1!=NULL){
			
						ccc1=cccc1+1;
						cccc1[0]=0;
						strcat(c,cccc);
						cccc=strstr(ccc1,">");
						cccc=cccc+1;
						if (cccc[0]=='\0') tim=1;
			
						
					}
				
			}
		}
		}else{
						strcat(c,cccc);
						tim=1;
						}
			
	}while(tim!=1);
	
}

void replace_char(char *c, char cc,char ccc){
	char *cccc=c;
	char *cccc1=c;
	int tim=0;
	do{
		cccc1=strchr(cccc,cc);
		if (cccc1!=NULL){
			cccc=cccc1+1;
			cccc1[0]=ccc;
			cccc1=cccc;
			if (cccc1[0]=='\0') tim=1;
		}else{
			tim=1;
		}
		
	}while(tim!=1);
}

void replace_sstr(char *c, char *cc,char *ccc){
	char *cccc=c;
	char *cccc1=c;
	int i=0;
	int n=0;
	int tim=0;
	do{
		cccc1=strstr(cccc,cc);
		if (cccc1!=NULL){
			cccc=cccc1;
			i=strlen(ccc);
			for(n=0;n<i;n++){
				cccc[0]=ccc[n];
				cccc1=cccc+1;
				cccc=cccc1;
			}

			cccc1=cccc+1;
			if (cccc1[0]=='\0') tim=1;
		}else{
			tim=1;
		}
		
	}while(tim!=1);
}









int instr(char *c,char *cc){
	long i1=0;
	long i2=0;
	long i3=0;
	char *v1=NULL;
	i1=(long)(void*)c;
	i3=-1;
	v1=strstr(c,cc);
	if (v1!=NULL) i2=(long)(void*)v1;
	if (v1!=NULL) i3=i2-i1;
	return (int) i3;
}







