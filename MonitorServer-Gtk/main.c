#include <gtk/gtk.h>
#include <stdlib.h>

GtkWindow *mainwindow;

GtkBuilder *builder;

GtkWidget *clear, *text;

GtkBox *box1;

GtkTextBuffer *text_buffer;

void mainquit(GtkWidget *window, gpointer data)
{
	gtk_main_quit ();
}

void clear_clicked(GtkWidget *window, gpointer data)
{
	gtk_text_buffer_set_text(GTK_TEXT_BUFFER(text_buffer), "", 0);
	//DEBUG TODO:REMOVE ME
	gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(text_buffer), "TEST", 0);
	gtk_text_view_set_buffer(GTK_TEXT_VIEW(text), GTK_TEXT_BUFFER(text_buffer));
}

static void mainwindow_init()
{
	mainwindow=GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
	gtk_window_set_title(GTK_WINDOW(mainwindow),"MonitorServer-GTK+");
	gtk_widget_show(GTK_WIDGET(mainwindow));
	g_signal_connect (G_OBJECT (mainwindow), "destroy",G_CALLBACK (mainquit), NULL);
	builder = gtk_builder_new ();
	gtk_builder_add_from_file(builder, "main.ui", NULL);
	box1 = (GtkBox *)gtk_builder_get_object (builder, "box1");
	clear = (GtkWidget *)gtk_builder_get_object (builder, "clear");
	text = (GtkWidget *)gtk_builder_get_object (builder, "text");
	text_buffer = (GtkTextBuffer *)gtk_text_view_get_buffer(GTK_TEXT_VIEW(text));
	gtk_widget_reparent(GTK_WIDGET(box1), GTK_WIDGET(mainwindow));
	//gtk_container_add (GTK_CONTAINER (mainwindow), GTK_WIDGET(box1));
	g_signal_connect (G_OBJECT (mainwindow), "destroy",G_CALLBACK (mainquit), NULL);
}

int main(int argc, char **argv)
{
	gtk_init(&argc,&argv);
	mainwindow_init();

	gtk_main();
	return 0;
}
