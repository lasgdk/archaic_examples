/*
   Code by Lars Sommer, <lasg@lasg.dk>
   Beerware license. 
   Do with the code what you want, but keep this license note.
   Give me a beer if we ever meet and you like this program. 

Disclaimer: This is really shitty code!!!
Compile with
gcc dtmfplayer.c -o dtmfplayer `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
   */

#include <gtk/gtk.h>

static void callback( GtkWidget *widget, gpointer   data )
{
system(data);
}

static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
    gtk_main_quit ();
    return FALSE;
}

int main( int   argc,
          char *argv[] )
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *table;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title (GTK_WINDOW (window), "DTMF player");

    g_signal_connect (G_OBJECT (window), "delete_event",
                      G_CALLBACK (delete_event), NULL);

    gtk_container_set_border_width (GTK_CONTAINER (window), 20);

    table = gtk_table_new (3, 5, TRUE);

    gtk_container_add (GTK_CONTAINER (window), table);

    button = gtk_button_new_with_label ("1");
    g_signal_connect (G_OBJECT (button), "clicked",
	              G_CALLBACK (callback), (gpointer) "waveplay 1.wav");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 0, 1, 0, 1);
    gtk_widget_show (button);


    button = gtk_button_new_with_label ("2");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callback), (gpointer) "waveplay 2.wav");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 1, 2, 0, 1);
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("3");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callback), (gpointer) "waveplay 3.wav");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 2, 3, 0, 1);
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("4");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callback), (gpointer) "waveplay 4.wav");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 0,1,1,2 );
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("5");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callback), (gpointer) "waveplay 5.wav");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 1,2,1,2 );
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("6");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callback), (gpointer) "waveplay 6.wav");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 2,3,1,2 );
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("7");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callback), (gpointer) "waveplay 7.wav");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 0,1,2,3 );
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("8");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callback), (gpointer) "waveplay 8.wav");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 1,2,2,3 );
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("9");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callback), (gpointer) "waveplay 9.wav");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 2,3,2,3 );
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("*");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callback), (gpointer) "waveplay stjerne.wav");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 0,1,3,4 );
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("0");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callback), (gpointer) "waveplay 0.wav");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 1,2,3,4 );
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("#");
    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (callback), (gpointer) "waveplay firkant.wav");
    gtk_table_attach_defaults (GTK_TABLE (table), button, 2,3,3,4 );
    gtk_widget_show (button);



    button = gtk_button_new_with_label ("Slut");

    g_signal_connect (G_OBJECT (button), "clicked",
                      G_CALLBACK (delete_event), NULL);

    gtk_table_attach_defaults (GTK_TABLE (table), button, 0, 3, 4, 5);

    gtk_widget_show (button);

    gtk_widget_show (table);
    gtk_widget_show (window);

    gtk_main ();

    return 0;
}
