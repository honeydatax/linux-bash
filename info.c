#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//g++ -o out process.c  `pkg-config gtk+-3.0 --cflags --libs` 

FILE 			*f1;
char 			c1[88];
char 			*c;
char			*cc;
int ii;

static void
on_changed (GtkComboBox *widget,
            gpointer   user_data)
{
  GtkComboBox *list1 = widget;

  if (gtk_combo_box_get_active (list1) != 0) {
    gchar *value = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(list1));
	strcpy (c1," ");
	strncat(c1, value,6);
	g_free(value);
	printf("%s\n",c1);
    }

}


static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  gint i;
  GtkWidget *viewer;
  GtkWidget *form1;
  GtkWidget *list1;
  GdkColor color1;
  
  color1.red=0;
  color1.green=65535;
  color1.blue=65535;

  form1 = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (form1), "cpu");
  gtk_window_set_default_size (GTK_WINDOW (form1), 600, 320);
  gtk_container_set_border_width (GTK_CONTAINER (form1), 10);

  
  list1 = gtk_combo_box_text_new ();
  
  	system("cat /proc/cpuinfo > info.dat");
	f1=fopen("info.dat","r");
	cc=c1;
	
	while(!feof(f1)){
		c=fgets(cc,81,f1);
		ii=strlen(cc);
		cc[ii]=0;
		gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (list1),cc);
	}
  
  
  gtk_combo_box_set_active (GTK_COMBO_BOX (list1), 0);

  g_signal_connect (list1,
                    "changed",
                    G_CALLBACK (on_changed),
                    NULL);


  gtk_container_add (GTK_CONTAINER (form1), list1);

  gtk_widget_show_all (form1);
}


int
main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
