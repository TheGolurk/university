#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


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

void comprar_producto(int ID){
    mostrar_productos();

    int id_producto = 0;
    printf("Introduce el ID del producto a comprar \n");
    scanf("%d", &id_producto);

    FILE *ptrArchivo;
    ptrArchivo = fopen("productos.dat", "r+b");
    if (ptrArchivo == NULL) {
        return;
    }

    FILE *ptrArchivo2;
    ptrArchivo2 = fopen("compras.dat", "a+");
    if (ptrArchivo2 == NULL) {
        return;
    }

    struct compras compra;
    struct productos producto;

    int index = 0;
    int found = 0;

    while(fread(&producto, sizeof(struct productos), 1, ptrArchivo))
    {
        if(id_producto != producto.id_producto)
        {
            index++;
            continue;
        }
        
        found = 1;
    
        fseek(ptrArchivo, (sizeof(producto))*index, SEEK_SET);

        producto.id_producto = producto.id_producto;
        strcpy(producto.modelo,producto.modelo);
        strcpy(producto.talla, producto.talla);
        producto.precio = producto.precio;
        producto.cant_disponible = producto.cant_disponible-1;

        fwrite(&producto, sizeof(struct productos), 1, ptrArchivo);
        break;
    }

    if (found == 0)
    {
        printf("No se encontro el producto");
        fclose(ptrArchivo);
        return;
    }
    fclose(ptrArchivo);


    compra.id_usuario = ID;
    compra.id_producto = id_producto;
    
    time_t t = time(NULL);
    compra.fecha = *localtime(&t);

    fwrite(&compra, sizeof(struct compras), 1, ptrArchivo2);

    fclose(ptrArchivo2);
}


void compras_realizadas(int id_usuario){
    FILE *ptrArchivo;
    struct compras compra;

    ptrArchivo = fopen ("compras.dat", "r");

    if(ptrArchivo == NULL)
    {
        return;
    }

    FILE *ptrArchivo2;
    ptrArchivo2 = fopen("productos.dat", "r");
    if (ptrArchivo2 == NULL) {
        return;
    }

    struct productos producto;

    while(fread(&compra, sizeof(compra), 1, ptrArchivo))
    {
        if (id_usuario == compra.id_usuario)
        {
    
            while(fread(&producto, sizeof(struct productos), 1, ptrArchivo2))
            {
                if (compra.id_producto == producto.id_producto)
                {
                    printf("| ID: %d \t Modelo: %s \t  Talla: %s \t Precio: $%0.2f \t Fecha de compra %d/%d/%d |\n", 
                    producto.id_producto, producto.modelo, producto.talla, producto.precio,
                    compra.fecha.tm_year+1900, compra.fecha.tm_mon+1, compra.fecha.tm_mday);
                }
            }
            fclose(ptrArchivo2);

        }
        
    }

    fclose(ptrArchivo);
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
            comprar_producto(ID);
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