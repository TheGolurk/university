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

//declaración de struct compras
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

    printf("Asignar clave para el producto:\n");
    scanf("%d", &reg_producto.id_producto);

    printf("Modelo:\n");
    scanf("%s", reg_producto.modelo);

    printf("Tallas:\n");
    scanf("%s",reg_producto.talla);

    printf("Cantidad disponible:\n");
    scanf("%d", &reg_producto.cant_disponible);

    printf("Precio:\n");
    scanf("%f", &reg_producto.precio);

    fwrite(&reg_producto, sizeof(struct productos), 1, ptrArchivo);

    fclose(ptrArchivo);
}

void modificar_producto(int id){
    FILE *ptrArchivo;
    ptrArchivo = fopen("productos.dat", "r+b");
    if (ptrArchivo == NULL) {
        return;
    }

    struct productos producto;

    int index = 0;
    int found = 0;

    while(fread(&producto, sizeof(struct productos), 1, ptrArchivo))
    {
        if(id != producto.id_producto)
        {
            index++;
            continue;
        }
        
        found = 1;
    
        fseek(ptrArchivo, (sizeof(producto))*index, SEEK_SET);

        producto.id_producto = producto.id_producto;

        printf("Nuevo modelo:\n");
        scanf("%s", producto.modelo);
        
        printf("Nueva Talla:\n");
        scanf("%s", producto.talla);
        
        printf("Nuevo precio:\n");
        scanf("%f", &producto.precio);
        
        printf("Nueva cantidad disponible:\n");
        scanf("%d", &producto.cant_disponible);

        fwrite(&producto, sizeof(struct productos), 1, ptrArchivo);
        break;
    }

    if (found == 0)
    {
        printf("No se encontro el producto");
    }
       

    fclose(ptrArchivo);
}

void eliminar_producto(int id){
    FILE *ptrArchivo;
    FILE *tmpArchivo;

    ptrArchivo = fopen("productos.dat", "rb");
    if (ptrArchivo == NULL) {
        return;
    }

    tmpArchivo = fopen("tmp.dat", "wb");
    if (ptrArchivo == NULL) {
        return;
    }


    int found = 0;
    struct productos producto;

    while(fread(&producto, sizeof(struct productos), 1, ptrArchivo))
    {
        if (producto.id_producto != id)
        {
            fwrite(&producto, sizeof(struct productos), 1, tmpArchivo);
            found = 1;
            continue;
        }
    }

    fclose(ptrArchivo);
    fclose(tmpArchivo);

    if (found == 0)
    {
        printf("No encontrado\n");
        return;
    }
    
    remove("productos.dat");
    rename("tmp.dat", "productos.dat");
}

void mostrar_ventas(){
    FILE *ptrArchivo;
    ptrArchivo = fopen("compras.dat", "a+");
    if (ptrArchivo == NULL) {
        return;
    }

    struct compras compra;
    
    while(fread(&compra, sizeof(struct compras), 1, ptrArchivo))
    {
        printf("| %d \t %d \t %d  |", compra.id_compra, compra.id_producto, compra.fcompra);
    }

    fclose(ptrArchivo);
}

void mostrar_menu_administrador(){
    int opc = 0;
    int id;
   
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
            printf("Ingrese el id del producto a buscar:\n");
            scanf("%d", &id);

            modificar_producto(id);
            break;

        case 3:
            printf("Ingrese el id del producto a eliminar:\n");
            scanf("%d", &id);

            eliminar_producto(id);
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