// gcc `pkg-config --cflags gtk+-3.0` -o firstproject0 firstproject0.c `pkg-config --libs gtk+-3.0` -rdynamic

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
    GtkBuilder *builder = data;
    GtkEntry *entry = GTK_ENTRY(gtk_builder_get_object(builder,"uinput"));
    GtkWidget *combobox = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
    GtkWidget *combobox2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry2"));
    int response = gtk_combo_box_get_active (GTK_COMBO_BOX(combobox));
    int response2 = gtk_combo_box_get_active (GTK_COMBO_BOX(combobox2));
    const gchar *entry_text = gtk_entry_get_text(GTK_ENTRY(entry));
    // printf("response: %d", response);
    // g_print("response2: %d", response2);

    const gchar *val = "Invalid comparison";
    gchar *result_text = NULL;
    
    if (response != response2){
        g_print("Error: %s \n", val);
        // result_text = g_strdup_printf("Error: %s \n", val);
    }
    else if (response == 0 && response2 == 0) {
        double converted = atof(entry_text);
        g_print("Abhi: %f m\n", converted);
        double final = converted * 3.28084;
        g_print("Computer: %f ft\n", final);
        // result_text = g_strdup_printf("Abhi: %f m\nComputer: %f ft\n", converted, converted * 3.28084);
    }
    else if (response == 1 && response2 == 1) {
        double converted = atof(entry_text);
        g_print("Abhi: %f kg\n", converted);
        double final = converted * 2.20462262185;
        g_print("Computer: %f lbs\n", final);
    }
    else if (response == 2 && response2 == 2) {
        double converted = atof(entry_text);
        g_print("Abhi: %f ltr\n", converted);
        double final = converted * 33.814;
        g_print("Computer: %f oz.\n", final);
    }
    else if (response == 3 && response2 == 3){
        double converted = atof(entry_text);
        g_print("Abhi: %f C\n", converted);
        double final = converted * (9/5) + 32;
        g_print("Computer: %f F\n", final);
    }
    // GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "%s", result_text);
    // gtk_dialog_run(GTK_DIALOG(dialog));
    // gtk_widget_destroy(dialog);
    // g_free(result_text);

  // int result = strcmp(entry_text, "Hello, World!");
  // const gchar *response;
  // if (result == 0){
  //     response = "Hello! How are you?";
  // }
  // else {
  //     response = "You bugging!";
  // }
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
