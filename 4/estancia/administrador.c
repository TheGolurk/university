#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//declaración de struct productos
struct productos{
  int   id_producto;
  char  modelo[20];
  char  talla[15];
  float precio;
  int   cant_disponible;
};

//declaraci+on de struct compras
struct compras{
  int id_compra;
  int id_producto;
  int fcompra;
};

//declaración de struct administrador
struct administrador{
  int id_identificación;
  int opcion;
};



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

    struct compras compra;
    
    while(fread(&compra, sizeof(struct compras), 1,ptrArchivo))
    {
    }

}



void mostrar_menu_administrador(){
    int opc = 0;
   
    while (opc != 5)
    {

        printf("--------------MENU DE ADMINISTRADOR----------------\n");
        printf("1.- Agregar producto\n");   
        printf("2.- Modificar producto\n");  
        printf("3.- Eliminar producto\n");     
        printf("4.- Mostrar productos vendidos\n");   
        printf("5.- Salir\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            agregar_producto();
            break;
        
        case 2:
            modificar_producto();
            break;

        case 3:
            eliminar_producto();
            break;

        case 4:
            mostrar_ventas();
            break;

        case 5:
            printf("\n\n\n");
            break;
        
        default:
            printf("Opcion incorrecta\n");
            break;
        }
    }
}