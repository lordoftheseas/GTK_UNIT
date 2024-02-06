#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
// static void
// print_hello (GtkWidget *widget,
//              gpointer   data)
// {
//   g_print ("Hello World\n");
// }

static void on_send_clicked(GtkButton *button, gpointer data){
    // struct user_data *received = 
//   data -> entry = GTK_ENTRY(gtk_builder_get_object(builder,"uinput"));
//   data -> combobox = GTK_COMBO_BOX(gtk_builder_get_object(builder, "entry1"));
//   data -> combobox2 = GTK_COMBO_BOX(gtk_builder_get_object(builder, "entry2"));
//   const gchar *entry_text = gtk_entry_get_text(data -> entry);
//   int combo_box_val = gtk_combo_box_get_active(data -> combobox);
//   g_print(combo_box_val);
GtkBuilder *builder = gpointer 
  int combo_box_val_2 = gtk_combo_box_get_active(data -> combobox2);
  
  // GtkComboBox *combobox = GTK_COMBO_BOX(gtk_builder_get_object(uder_data, )) ;
  // combobox = 
  double converted = atoi(entry_text);
  g_print("Abhi: %f\n", converted);
  // int result = strcmp(entry_text, "Hello, World!");
  // const gchar *response;
  // if (result == 0){
  //     response = "Hello! How are you?";
  // }
  // else {
  //     response = "You bugging!";
  // }
  double final = converted * 3.6;
  g_print("Computer: %f\n", final);
}

//this quit button is a bit shitty cause it needs to be clicked twice
void show_quit_screen(GtkWidget *widget, gpointer dialog) {

  // gtk_dialog_run(GTK_DIALOG(dialog));
  // gtk_widget_show_all(dialog);

  int response = gtk_dialog_run(GTK_DIALOG(dialog));
  
   switch (response)
   {
      case GTK_RESPONSE_YES:
         gtk_main_quit();
         break;

      case GTK_RESPONSE_NO:
         // Just hide dialog
         break;

      default:
         // do_nothing_since_dialog_was_cancelled ();
         break;
   }
   gtk_widget_hide(dialog);
}

  struct user_data{
    GtkEntry *entry;
    GtkComboBox *combobox;
    GtkComboBox *combobox2;
  }; //so data is the variable which is later passed as an address and is derefrenced when passsed to another function

int
main (int   argc,
      char *argv[])
{
  GtkBuilder *builder;
  GtkWidget *window;
  GtkButton *button;
  GtkButton *send;
  GError *error = NULL;
  GtkDialog *dialog;

  gtk_init (&argc, &argv);

  /* Construct a GtkBuilder instance and load our UI description */
  //here is builder that opens the xml file
  builder = gtk_builder_new ();
  if (gtk_builder_add_from_file (builder, "builder.ui", &error) == 0)
    {
      g_printerr ("Error loading file: %s\n", error->message);
      g_clear_error (&error);
      return 1;
    }
    //we get all the elements from the windows
    send = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    GtkWidget *widget = GTK_WIDGET(gtk_builder_get_object(builder,"Box"));
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    dialog = GTK_DIALOG(gtk_builder_get_object(builder, "dialog1"));

//   struct user_data *retreive_data = data;
  g_signal_connect (send, "clicked", G_CALLBACK (on_send_clicked), builder);
  
  button = GTK_BUTTON(gtk_builder_get_object (builder, "quit"));
  g_signal_connect (button, "clicked", G_CALLBACK (show_quit_screen), (gpointer) dialog);
  // gtk_widget_show_all(window);
  // gtk_builder_connect_signals(builder, builder);

  gtk_main ();

  return 0;
}