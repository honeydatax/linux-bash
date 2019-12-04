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
gboolean on_key(GtkWidget *widget,GdkEventKey *events, gpointer user_data);
int errorss;
int first_time=0;
GtkWidget *window;
GtkWidget *draws;
GtkWidget *widgets;
GtkStyleContext *context;
int w=640;
int h=320;
int title[11];
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
int pos;
int gameover;
int lost=0;
int win=0;

gboolean on_clock(gpointer data){
	int map[]={0,0,0,0,0,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
	if(gameover==0){
		if(first_time==1) {
		
			nn=nnumber(5)+1;
			pos=pos+nn;
			if (pos>20)pos=pos-20;
			curre=0;
			if (map[pos]==1)curre=-150.00;
			if (map[pos]==2)curre=250.00;
			currency=currency+curre;
			if (currency<0) gameover=1;
			if (currency<0) lost=1;
			x=x+addx;
			y=250;
			if (x>680.0f)addx=-5;
			if (x<-80.0f)addx=5;
	}
	
	}
	gtk_widget_queue_draw_area(draws,0,0,620,320);
 return TRUE;
}


gboolean on_key(GtkWidget *widget,GdkEventKey *events, gpointer user_data){
	int c;
	c=events->keyval;
	if (gameover==0){
		if (title[0]==0 && c==48){
			title[0]=1;
			currency=currency-200;
		}
		if (title[1]==0 && c==49){
			title[1]=1;
			currency=currency-200;
		}
		if (title[2]==0 && c==50){
			title[2]=1;
			currency=currency-200;
		}
		if (title[3]==0 && c==51){
			title[3]=1;
			currency=currency-200;
		}
		if (title[4]==0 && c==52){
			title[4]=1;
			currency=currency-200;
		}
	
		if (title[5]==0 && c==53){
			title[5]=1;
			currency=currency-200;
		}
		if (title[6]==0 && c==54){
			title[6]=1;
			currency=currency-200;
		}
		if (title[7]==0 && c==55){
			title[7]=1;
			currency=currency-200;
		}

		if (title[8]==0 && c==56){
			title[8]=1;
			currency=currency-200;
		}

		if (title[9]==0 && c==57){
			title[9]=1;
			currency=currency-200;
		}
		if(title[0]==1 && title[1]==1 && title[2]==1 && title[3]==1 && title[4]==1 && title[5]==1 && title[6]==1 && title[7]==1 && title[8]==1 && title[9]==1){
			win=1;
			gameover=1;
		}
	}
	return FALSE;
}

gboolean on_draws1(GtkWidget *widget,cairo_t *cr,gpointer user_data){
	on_paint(cr);
	first_time=1;
	return FALSE;
}

int main( int   argc,char *argv[] )
{
	int i;
	gameover=0;
	srandom(time(NULL));
	currency=900.00;
	pos=0;
	for(i=0;i<10;i++) title[i]=0;
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 620, 320);
    gtk_window_set_title (GTK_WINDOW (window), "asteroids");
    
    g_signal_connect (window, "destroy",
                      G_CALLBACK (on_exits1), NULL);
    
  
    draws = gtk_drawing_area_new ();
	gtk_container_add (GTK_CONTAINER(window), draws);
    gtk_widget_show (draws);
    gtk_widget_add_events(window,GDK_KEY_PRESS_MASK);
    gtk_widget_set_size_request (GTK_WIDGET (window), 620, 320);
    gtk_widget_show_all(window);

    g_signal_connect (G_OBJECT(draws), "draw",
                     G_CALLBACK (on_draws1), NULL);
                      
    g_signal_connect (window, "key_press_event",
                      G_CALLBACK (on_key),NULL);
   

    exitcode=g_timeout_add(gu1,on_clock,NULL);


    gtk_main();

    g_source_remove(exitcode);

    return 0;
}

void on_exits1(){
	
	gtk_main_quit();
}

void on_paint(cairo_t *cr){
	int ii;
	int nn=0;
	char *c1;
	char ccc[512];
	float f;
	sprintf(ccc,"$%f",currency);
	c1=strstr(ccc,".");
	c1=c1+3;
	c1[0]=0;
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
    cairo_move_to(cr,10.00,60.00);
    if (gameover==1) cairo_show_text(cr,"game over");
    cairo_move_to(cr,10.00,120.00);
    cairo_show_text(cr,"key 0 - 9 buy asteroid");
    cairo_move_to(cr,160.00,60.00);
    if (lost==1) cairo_show_text(cr,"you lost");
    cairo_move_to(cr,160.00,60.00);
    if (win==1) cairo_show_text(cr,"you win");
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
    cairo_set_source_rgb(cr,1.0,1.0,1.0);
	for(ii=0;ii<10;ii++){
		f=(float) ii;
		f=f*18.00+5.00;
		sprintf(ccc,"%d",ii);
		cairo_move_to(cr,f,90.00);
		if (title[ii]==1)cairo_show_text(cr,ccc);
	}

}




int nnumber(int n){
	int nnn=RAND_MAX/n;
	int nn=random()/nnn;
	return nn;
}
