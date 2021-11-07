#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct alumno {
    int  id_alumno;
    char nombre[30];
    char grupo[5];
    int  opcionRealizar;
    char modelo[20];
};

void mostrar_productos(){

}

void comprar_producto(){

}

void compras_realizadas(){
    FILE *ptrArchivo;
    struct alumno alumnos;

    ptrArchivo = fopen ("alumnos.dat", "r");

    if(ptrArchivo == NULL)
    {
        return;
        
    }

    while(fread(&alumnos, sizeof(alumnos), 1, ptrArchivo))
    {

    }

}

void mostrar_usuario_menu() {
    int opc = 0;

    while (opc != 4)
    {
        printf("---------------MENU DE USUARIO----------------\n");
        printf("1.- Mostrar Productos \n");
        printf("2.- Hacer una compra \n");
        printf("3.- Compras realizadas\n");
        printf("4.- Salir\n");

        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            mostrar_productos();
            break;

        case 2:
            comprar_producto();
            break;

        case 3:
            compras_realizadas();
            break;

        case 4:
            printf("\n\n\n");
            break;
        
        default:
            printf("opcion incorrecta\n");
            break;
        }
    }
}