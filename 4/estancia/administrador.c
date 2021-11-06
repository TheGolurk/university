#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errores.c"
#include "constantes.c"


void agregar_producto(){
    FILE *ptrArchivo;
    ptrArchivo = fopen("productos.dat", "a+");
    if (ptrArchivo == NULL) {
        return;
    }

    struct productos reg_producto;

    printf("Asignar clave para el producto:");
    scanf("%d", &reg_producto.id_producto);


    printf("Modelo:");
    scanf("%s", reg_producto.modelo);

    printf("Tallas:");
    scanf("%s",reg_producto.talla);


    printf("Cantidad disponible:");
    scanf("%d", &reg_producto.cant_disponible);


    printf("Precio:");
    scanf("%f", &reg_producto.precio);
}

void modificar_producto(){
    FILE *ptrArchivo;
    ptrArchivo = fopen("productos.dat", "a+");
    if (ptrArchivo == NULL) {
        return;
    }

}


void eliminar_producto(){
    FILE *ptrArchivo;
    ptrArchivo = fopen("productos.dat", "a+");
    if (ptrArchivo == NULL) {
        return;
    }

}


void mostrar_ventas(){
    FILE *ptrArchivo;
    ptrArchivo = fopen("compras.dat", "a+");
    if (ptrArchivo == NULL) {
        return;
    }

}



void mostrar_usuario_ad(){
    int opc = 0;
   
    while (opc != 5)
    {

        printf(ANSI_COLOR_MAGENTA "--------------MENU DE ADMINISTRADOR----------------\n" ANSI_COLOR_MAGENTA);
        printf(ANSI_COLOR_RESET);

        printf("1.- Agregar producto\n");   
        printf("2.- Modificar producto\n");  
        printf("3.- Eliminar producto\n");     
        printf("4.- Mostrar productos vendidos\n");   
        printf("---------------5.- Salir---------------------------\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            break;
        
        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            printf("\n\n\n");
            break;
        
        default:
            WrongOption();
            break;
        }
    }
}