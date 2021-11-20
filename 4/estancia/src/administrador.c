#include <stdio.h>
#include <stdlib.h>




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
    ptrArchivo = fopen("compras.dat", "r");
    if (ptrArchivo == NULL) {
        return;
    }

    struct compras compra;
    
    while(fread(&compra, sizeof(struct compras), 1, ptrArchivo))
    {
        printf("| %d \t %d \t %d/%d/%d  |\n", compra.id_usuario, compra.id_producto, 
        compra.fecha.tm_year, compra.fecha.tm_mon, compra.fecha.tm_mday);
    }

    fclose(ptrArchivo);
}

void mostrar_productos_actuales(){
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

void mostrar_menu_administrador(){
    int opc = 0;
    int id;
   
    while (opc != 6)
    {

        printf("--------------MENU DE ADMINISTRADOR----------------\n");
        printf("1.- Agregar producto\n");   
        printf("2.- Modificar producto\n");  
        printf("3.- Eliminar producto\n");     
        printf("4.- Mostrar productos vendidos\n");   
        printf("5.- Mostrar todos los productos\n");
        printf("6.- Salir\n");
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
            mostrar_productos_actuales();
            break;

        case 6:
            printf("\n\n\n");
            break;
        
        default:
            printf("Opcion incorrecta\n");
            break;
        }
    }
}