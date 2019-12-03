#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cairo.h>
#include <gtk/gtk.h>

//g++ -o out gimage.cpp  `pkg-config gtk+-3.0 --cflags --libs`

gboolean on_clock(gpointer data);
int nnumber(int n);
void on_exits1();
void on_paint(cairo_t *cr);
gboolean on_draws1(GtkWidget *widget,cairo_t *cr,gpointer user_data);
int errorss;
int first_time=0;
GtkWidget *window;
GtkWidget *draws;
GtkWidget *widgets;
GtkStyleContext *context;
int w=640;
int h=320;
cairo_t *cr1;
gint exitcode=0;
guint gu1=100;
float x=30.0f;
float y=30.0f;
float addx=5.0f;
float addy=5.0f;
double currency;
int nn;
double curre;

gboolean on_clock(gpointer data){
	
	if(first_time==1) {
		nn=nnumber(1000)-460;
		curre=(double) nn;
		curre=curre/100;
		currency=currency+curre;
		x=x+addx;
		y=250;
		if (x>680.0f)addx=-5;
		if (x<-80.0f)addx=5;
		gtk_widget_queue_draw_area(draws,0,0,620,320);
	}
 return TRUE;
}

gboolean on_draws1(GtkWidget *widget,cairo_t *cr,gpointer user_data){
	on_paint(cr);
	first_time=1;
	return FALSE;
}

int main( int   argc,char *argv[] )
{
	srandom(time(NULL));
	currency=160;
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 620, 320);
    gtk_window_set_title (GTK_WINDOW (window), "ball");
    g_signal_connect (window, "destroy",
                      G_CALLBACK (on_exits1), NULL);
    
    
   
    
    draws = gtk_drawing_area_new ();
	gtk_container_add (GTK_CONTAINER(window), draws);
    gtk_widget_show (draws);
    gtk_widget_set_size_request (GTK_WIDGET (window), 620, 320);
    gtk_widget_show_all(window);

    g_signal_connect (G_OBJECT(draws), "draw",
                     G_CALLBACK (on_draws1), NULL);
                      

    exitcode=g_timeout_add(gu1,on_clock,NULL);


    gtk_main();

    g_source_remove(exitcode);

    return 0;
}

void on_exits1(){
	
	gtk_main_quit();
}

void on_paint(cairo_t *cr){
	char ccc[512];
	sprintf(ccc,"$%f",currency);
	cairo_set_source_rgb(cr,0.0,0.0,0.0);
	cairo_set_line_width(cr,1);
    cairo_rectangle(cr,0.0,0.0,640.0,350.0);
    cairo_stroke_preserve(cr);
    cairo_fill(cr);
    cairo_select_font_face(cr,"mono",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr,24.0);
    cairo_set_source_rgb(cr,1.0,1.0,1.0);
    cairo_move_to(cr,10.00,20.00);
    cairo_show_text(cr,"asteroid the game:");
    cairo_move_to(cr,300.00,20.00);
    cairo_show_text(cr,ccc);
    cairo_set_line_width(cr,1);
	cairo_rectangle(cr,x+5,y-10,40,20);
    cairo_stroke_preserve(cr);
    cairo_fill(cr);
    cairo_arc(cr,x,y,10.0f,0.00f,2.00*G_PI);
	cairo_fill(cr);
    cairo_arc(cr,x+50,y,10.0f,0.00f,2.00*G_PI);
    cairo_fill(cr);
    cairo_set_source_rgb(cr,0.0,0.0,0.0);
    cairo_arc(cr,x-3,y-3.0f,3.0f,0.00f,2.00*G_PI);
	cairo_fill(cr);
    cairo_arc(cr,x+53,y-3.0f,3.0f,0.00f,2.00*G_PI);
	cairo_fill(cr);
	cairo_set_line_width(cr,1);
	cairo_rectangle(cr,x+10,y-5,30,10);
	cairo_fill(cr);


}




int nnumber(int n){
	int nnn=RAND_MAX/n;
	int nn=random()/nnn;
	return nn;
}
