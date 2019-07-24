/*
 * Calculadora
 * Escrito por: Juan Dirceu Navarro Airas
 *
 */


#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

GtkWidget *pantalla;

gchar *obtener_datos(){
    gchar *dato;
    dato = g_strdup(gtk_entry_get_text(GTK_ENTRY(pantalla)));
    return dato;
}

gchar *anadir_datos(gchar *dato_nuevo){

    gchar *dato_anterior;
    gchar *dato_devuelto;

    dato_anterior = g_strdup(obtener_datos());

    if (g_strcmp0(dato_anterior, "0") != 0){//Evita que se escriba ceros a la izquierda al inicio.
        dato_anterior = g_strconcat(dato_anterior, dato_nuevo, NULL); printf("dato anterior: %s\n", dato_anterior);
        dato_devuelto = g_strdup(dato_anterior);
    } else {
        dato_devuelto = g_strdup(dato_nuevo);
    }
    printf("Dato devuelto: %s, tamaño: %i\n", dato_devuelto, (int)strlen(dato_devuelto));

    return dato_devuelto;
}

void on_button_0_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("0");
    printf("Boton 0 presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_1_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("1");
    printf("Boton 1 presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_2_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("2");
    printf("Boton 2 presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_3_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("3");
    printf("Boton 3 presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_4_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("4");
    printf("Boton 4 presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_5_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("5");
    printf("Boton 5 presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_6_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("6");
    printf("Boton 6 presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_7_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("7");
    printf("Boton 7 presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_8_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("8");
    printf("Boton 8 presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_9_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("9");
    printf("Boton 9 presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_suma_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("+");
    printf("Boton + presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_resta_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("-");
    printf("Boton - presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_multiplicacion_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("*");
    printf("Boton * presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_division_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("/");
    printf("Boton / presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_punto_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos(".");
    printf("Boton . presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_parentesis_izq_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos("(");
    printf("Boton ( presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_parentesis_der_clicked (GtkWidget *button, gpointer userdata){

    gchar *dato_nuevo = anadir_datos(")");
    printf("Boton ) presionado: %s\n", dato_nuevo);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato_nuevo);

}

void on_button_ac_clicked (GtkWidget *button, gpointer userdata){

    printf("Boton AC presionado.\n");
    gtk_entry_set_text(GTK_ENTRY(pantalla), "0");

}

void on_button_rtcs_clicked (GtkWidget *button, gpointer userdata){
    printf("Boton RTCS presionado.\n");
    //gtk_entry_set_text(GTK_ENTRY(pantalla), "0");
    gchar *dato;
    dato = g_strdup(gtk_entry_get_text(GTK_ENTRY(pantalla)));

    dato[strlen(dato)-1] = '\0';
    printf("dato: %s", dato);
    gtk_entry_set_text(GTK_ENTRY(pantalla), dato);
    if (strlen(dato)==0) {
        gtk_entry_set_text(GTK_ENTRY(pantalla), "0");
    }
}

gchar *validar(gchar *cadena){
    int i;
    int longitud = strlen(cadena);
    printf("longitud: %i, cadena: %s\n", longitud, cadena);

    char valor_devuelto[100];

    for (i = 0; i < longitud; i++){
        printf("Valor de i: %i, ", i);
        if (cadena[i] != '\r')
            valor_devuelto[i] = cadena[i];
    }
    printf("valor devuelto: %s\n", valor_devuelto);
    return cadena;
}

void on_button_igual_clicked (GtkWidget *button, gpointer userdata){

    printf("Boton = presionado: \n");
    FILE *fp;
    int status;
    char resultado[100];
    char *operacion;
    //int result;

    operacion = g_strdup(obtener_datos());
    operacion = g_strdup(validar(operacion));

    printf("Resultado: %s\n", operacion);

    //operacion = (char) result;

    #ifdef linux
        operacion = g_strconcat("./calc \"", operacion, NULL);
    #endif // linux

    #ifdef _WIN32
        operacion = g_strconcat("calc.exe \"", operacion, NULL);
    #endif // _WIN32

    operacion = g_strconcat(operacion, "\"", NULL);

    printf("Operación: %s\n", operacion);

    fp = popen(operacion, "r");
    if (fp == NULL) {
        printf("NO se pudo ejecutar el comando.");
    };

    while (fgets(resultado, 100, fp) != NULL);

    printf("Resultado: %s", resultado);
    gtk_entry_set_text(GTK_ENTRY(pantalla), resultado);

    status = pclose(fp);
    if (status == -1) {
        // Error reported by pclose()
    } else {
        // Use macros described under wait() to inspect `status' in order
        //to determine success/failure of command executed by popen()
    }

}

void obtener_widgets(GtkBuilder *builder){

    GtkWidget *button0;
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *button3;
    GtkWidget *button4;
    GtkWidget *button5;
    GtkWidget *button6;
    GtkWidget *button7;
    GtkWidget *button8;
    GtkWidget *button9;

    GtkWidget *button_suma;
    GtkWidget *button_resta;
    GtkWidget *button_multiplicacion;
    GtkWidget *button_division;
    GtkWidget *button_punto;
    GtkWidget *button_igual;
    GtkWidget *button_parentesis_izq;
    GtkWidget *button_parentesis_der;
    GtkWidget *button_ac;
    //GtkWidget *button_rtcs;


    pantalla = GTK_WIDGET(gtk_builder_get_object(builder,"entry1"));

    button0 = GTK_WIDGET(gtk_builder_get_object(builder,"button_0"));
    g_signal_connect( G_OBJECT(button0), "clicked",
            G_CALLBACK(on_button_0_clicked), NULL);

    button1 = GTK_WIDGET(gtk_builder_get_object(builder,"button_1"));
    g_signal_connect( G_OBJECT(button1), "clicked",
            G_CALLBACK(on_button_1_clicked), NULL);

    button2 = GTK_WIDGET(gtk_builder_get_object(builder,"button_2"));
    g_signal_connect( G_OBJECT(button2), "clicked",
            G_CALLBACK(on_button_2_clicked), NULL);

    button3 = GTK_WIDGET(gtk_builder_get_object(builder,"button_3"));
    g_signal_connect( G_OBJECT(button3), "clicked",
            G_CALLBACK(on_button_3_clicked), NULL);

    button4 = GTK_WIDGET(gtk_builder_get_object(builder,"button_4"));
    g_signal_connect( G_OBJECT(button4), "clicked",
            G_CALLBACK(on_button_4_clicked), NULL);

    button5 = GTK_WIDGET(gtk_builder_get_object(builder,"button_5"));
    g_signal_connect( G_OBJECT(button5), "clicked",
            G_CALLBACK(on_button_5_clicked), NULL);

    button6 = GTK_WIDGET(gtk_builder_get_object(builder,"button_6"));
    g_signal_connect( G_OBJECT(button6), "clicked",
            G_CALLBACK(on_button_6_clicked), NULL);

    button7 = GTK_WIDGET(gtk_builder_get_object(builder,"button_7"));
    g_signal_connect( G_OBJECT(button7), "clicked",
            G_CALLBACK(on_button_7_clicked), NULL);

    button8 = GTK_WIDGET(gtk_builder_get_object(builder,"button_8"));
    g_signal_connect( G_OBJECT(button8), "clicked",
            G_CALLBACK(on_button_8_clicked), NULL);

    button9 = GTK_WIDGET(gtk_builder_get_object(builder,"button_9"));
    g_signal_connect( G_OBJECT(button9), "clicked",
            G_CALLBACK(on_button_9_clicked), NULL);


    button_suma = GTK_WIDGET(gtk_builder_get_object(builder,"button_suma"));
    g_signal_connect( G_OBJECT(button_suma), "clicked",
            G_CALLBACK(on_button_suma_clicked), NULL);

    button_resta = GTK_WIDGET(gtk_builder_get_object(builder,"button_resta"));
    g_signal_connect( G_OBJECT(button_resta), "clicked",
            G_CALLBACK(on_button_resta_clicked), NULL);

    button_multiplicacion = GTK_WIDGET(gtk_builder_get_object(builder,"button_multiplicacion"));
    g_signal_connect( G_OBJECT(button_multiplicacion), "clicked",
            G_CALLBACK(on_button_multiplicacion_clicked), NULL);

    button_division = GTK_WIDGET(gtk_builder_get_object(builder,"button_division"));
    g_signal_connect( G_OBJECT(button_division), "clicked",
            G_CALLBACK(on_button_division_clicked), NULL);

    button_punto = GTK_WIDGET(gtk_builder_get_object(builder,"button_punto"));
    g_signal_connect( G_OBJECT(button_punto), "clicked",
            G_CALLBACK(on_button_punto_clicked), NULL);

    button_igual = GTK_WIDGET(gtk_builder_get_object(builder,"button_igual"));
    g_signal_connect( G_OBJECT(button_igual), "clicked",
            G_CALLBACK(on_button_igual_clicked), NULL);

    button_parentesis_izq = GTK_WIDGET(gtk_builder_get_object(builder,"button_parentesis_izq"));
    g_signal_connect( G_OBJECT(button_parentesis_izq), "clicked",
            G_CALLBACK(on_button_parentesis_izq_clicked), NULL);

    button_parentesis_der = GTK_WIDGET(gtk_builder_get_object(builder,"button_parentesis_der"));
    g_signal_connect( G_OBJECT(button_parentesis_der), "clicked",
            G_CALLBACK(on_button_parentesis_der_clicked), NULL);

    button_ac = GTK_WIDGET(gtk_builder_get_object(builder,"button_ac"));
    g_signal_connect( G_OBJECT(button_ac), "clicked",
            G_CALLBACK(on_button_ac_clicked), NULL);

    button_ac = GTK_WIDGET(gtk_builder_get_object(builder,"button_rtcs"));
    g_signal_connect( G_OBJECT(button_ac), "clicked",
            G_CALLBACK(on_button_rtcs_clicked), NULL);


    gtk_entry_set_alignment(GTK_ENTRY(pantalla), 1); //Alinear la pantalla a la derecha
}
