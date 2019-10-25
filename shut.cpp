#include "shut.h"
int main(int argc, char *argv[])
{
	
    gtk_init(&argc, &argv);
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "shut.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "form1"));
    bt1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    bt2 = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));
    bt3 = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
    bt4 = GTK_WIDGET(gtk_builder_get_object(builder, "button4"));

	
  
	g_signal_connect_swapped (window , "destroy",
			      G_CALLBACK (on_destroy),
			    window );
			     
	
	g_signal_connect_swapped (bt1, "pressed",
			      G_CALLBACK (on_f1),
			    window );

	g_signal_connect_swapped (bt2, "pressed",
			      G_CALLBACK (on_f2),
			    window );

	g_signal_connect_swapped (bt3, "pressed",
			      G_CALLBACK (on_f3),
			    window );

	g_signal_connect_swapped (bt4, "pressed",
			      G_CALLBACK (on_f4),
			    window );




	
   
    g_object_unref(builder);
    gtk_widget_show(window);                
    gtk_main();
    return 0;
}
