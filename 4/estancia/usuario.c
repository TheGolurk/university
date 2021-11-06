#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errores.c"
#include "constantes.c"

void mostrar_productos(){

}

void comprar(){

}

void compras_realizadas(){
    FILE *ptrArchivo;
    struct alumno alumnos;

    ptrArchivo = fopen ("alumnos.dat", "r");

    if(ptrArchivo == NULL)
    {
        return;
        
    }

    while(fread(&alumnos, sizeof(struct alumno), 1, ptrArchivo))
    {

    }

}

void mostrar_usuario_menu() {
    int opc = 0;

    while (opc != 4)
    {
        printf(ANSI_COLOR_CYAN "---------------MENU DE USUARIO----------------\n" ANSI_COLOR_CYAN);
        printf(ANSI_COLOR_RESET);
        
        printf("1.- Mostrar Productos \n");
        printf("2.- Hacer una compra \n");
        printf("3.- Compras realizadas\n");
        printf("----------------4.- Salir--------------------\n");

        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            mostrar_productos();
            break;

        case 2:
            comprar();
            break;

        case 3:
            compras_realizadas();
            break;

        case 4:
            printf("\n\n\n");
            break;
        
        default:
            WrongOption();
            break;
        }
    }
}