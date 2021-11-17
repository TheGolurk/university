#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct alumno {
    int  id_alumno;
    char nombre[30];
    char grupo[5];
    int  opcionRealizar;
    char modelo[20];
};

struct productos{
    int   id_producto;
    char  modelo[20];
    char  talla[15];
    float precio;
    int   cant_disponible;
};

struct compras{
    int id_usuario;
    int id_producto;
    struct tm fecha;
};



void mostrar_productos(){
    FILE *ptrArchivo;
    ptrArchivo = fopen("productos.dat", "r");
    if (ptrArchivo == NULL) {
        return;
    }

    struct productos producto;
    
    while(fread(&producto, sizeof(struct productos), 1, ptrArchivo))
    {
        printf("| ID: %d \t Modelo: %s \t  Talla: %s \t Precio: $%0.2f \t Cantidad disponible: %d |\n", 
        producto.id_producto, producto.modelo, producto.talla, producto.precio, producto.cant_disponible);
    }

    fclose(ptrArchivo);
}

void comprar_producto(){
    

    // listar productos
    // leer el producto a eliminar
    // modificar el archivo de productos (la cantidad) 
    // agrega en el archivo de compras (usuario + producto)
}

void compras_realizadas(int ID){
    FILE *ptrArchivo;
    struct alumno alumnos;

    ptrArchivo = fopen ("compras.dat", "r");

    if(ptrArchivo == NULL)
    {
        return;
        
    }

    while(fread(&alumnos, sizeof(alumnos), 1, ptrArchivo))
    {

    }

}

void mostrar_usuario_menu(int ID) {
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
            compras_realizadas(ID);
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