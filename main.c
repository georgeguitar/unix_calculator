/*
 * Calculadora
 * Escrito por: Juan Dirceu Navarro Arias
 *
 * Compile me with:
   gcc `pkg-config --cflags gtk+-3.0` main.c -o main `pkg-config --libs gtk+-3.0`
   Para utilizar el comando anterior desde Windows, se debe entrar a la consola de MSYS2 (desde el menú inicio), se debe copiar el proyecto a: C:\msys64\home\georgeguitar

   Configurar en Codeblocks, de forma global, para todos los proyectos:

   Añadir en Settings, Compiler, Compiler settings, Other compiler options
   `pkg-config --cflags gtk+-3.0`

   Añadir en Settings, Compiler, Linker settings, Other linker options
   `pkg-config --libs gtk+-3.0`


Installing Gtk on Windows
-------------------------
https://github.com/GtkSharp/GtkSharp/wiki/Installing-Gtk-on-Windows

Step 1: Install MSYS2

Download the MSYS2 installer and follow the installation instructions: http://www.msys2.org/
Step 2: Install GTK+3

Open a MSYS2 shell, and run: pacman -S mingw-w64-x86_64-gtk3
Step 3: Modify PATH variable so that the library can be found

    Open up Control Panel
    Go to System and Security > System
    Click on the Advanced system settings link
    Click on Environment Variables... button
    Under System variables find the Path variable and select it
    Click the Edit button
    Add either ;C:\msys64\mingw64\bin or ;C:\msys32\mingw32\bin to the end of the variable, depending on your system architecture
    Click OK, and you are done
    Restart your system for the changes to apply

Cambiar el compilador en Codeblocks:
Settings, Compiler, Toolchain executables, Compiler's instalation directory: C:\msys64\mingw64\bin


 */

#include <gtk/gtk.h>
#include "callbacks.h"



int
main( int    argc,
      char **argv )
{
    GtkBuilder *builder;
    GtkWidget  *window;
    GError     *error = NULL;

    /* Init GTK+ */
    gtk_init( &argc, &argv );

    /* Create new GtkBuilder object */
    builder = gtk_builder_new();
    /* Load UI from file. If error occurs, report it and quit application.
     * Replace "tut.glade" with your saved project. */
    if( ! gtk_builder_add_from_file( builder, "calculadora.glade", &error ) )
    {
        g_warning( "%s", error->message );
        g_free( error );
        return( 1 );
    }

    /* Get main window pointer from UI */
    window = GTK_WIDGET( gtk_builder_get_object( builder, "window1" ) );

    /* Connect signals */
    gtk_builder_connect_signals( builder, NULL );

    obtener_widgets(builder);

    /* Destroy builder, since we don't need it anymore */
    g_object_unref( G_OBJECT( builder ) );

    /* Show window. All other widgets are automatically shown by GtkBuilder */
    gtk_widget_show( window );


    /* Start main loop */
    gtk_main();


    return( 0 );
}
