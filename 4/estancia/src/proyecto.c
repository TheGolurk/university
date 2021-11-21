/***
PROYECTO DE ESTANCIA: ONLINE SHOP
AUTORES:
HERNÁNDEZ NÁJERA CHRISTIAN
PÉREZ BALTAZAR MITZI GUADALUPE
VALLE GONZÁLEZ LORENA
***/


/*
    REPO: https://github.com/TheGolurk/university/tree/master/4/estancia
    BUILD:
        BASH: $ chmod 777 run.sh && ./run.sh
        MAKEFILE: $ make run
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ADMIN_ID 9999
#define ARR_SIZE(x)  (sizeof(x) / sizeof((x)[0]))

// structs
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
    char nombre[50]; 
    char matricula[20];
};


// Administrador
void agregar_producto();
void modificar_producto();
void mostrar_ventas();
void eliminar_producto(int id);
void mostrar_productos_actuales();
void mostrar_menu_administrador();
void mostrar_ventas();

// Usuario
void mostrar_productos();
void comprar_producto(int ID);
void compras_realizadas(int id_usuario);
void mostrar_usuario_menu(int ID);

// validador
int encontrar_alumno(int ID); 
int validar_usuario(int ID);

int main()
{

    int opcion = 0;
    int ID;


    while(opcion != 3)
    {

        printf("\n-----------------------------------------------");
        printf("\n BIENVENIDO A ONLINE SHOP");
        printf("\n-----------------------------------------------");
        printf("\nSeleccione el modo de usuario:");
        printf("\n1.- ALUMNO\n2.- ADMINISTRADOR\n3.- Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingresar ID de identificación\n");
                scanf("%d", &ID);

                if ( validar_usuario(ID) != 1 )
                {
                    printf("Usuario no valido\n");
                    continue;
                }

                mostrar_usuario_menu(ID);
                

                break;

            case 2:
                printf("Ingresar ID de identificación\n");
                scanf("%d", &ID);

                if ( validar_usuario(ID) != 2 )
                {
                    printf("Usuario no valido\n");
                    continue;
                }

                mostrar_menu_administrador();

                break;

            case 3:
                printf("HASTA PRONTO\n");
                break;

            default:
                printf("Opcion invalida, adios\n");
                break;
        }
    }

  return 0;
}

// Administrador

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
    scanf("%s",reg_producto.modelo);

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

void mostrar_ventas(){
    FILE *ptrArchivo;
    ptrArchivo = fopen("compras.dat", "r");
    if (ptrArchivo == NULL) {
        return;
    }

    struct compras compra;
    
    while(fread(&compra, sizeof(struct compras), 1, ptrArchivo))
    {
        printf("| Nombre: %s \t Matricula: %s \t ID alumno: %d \t ID producto: %d \t Fecha: %d/%d/%d  |\n", 
        compra.nombre, compra.matricula, compra.id_usuario, compra.id_producto, 
        compra.fecha.tm_year + 1900, compra.fecha.tm_mon, compra.fecha.tm_mday);
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

// Usuario

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

    printf("Ingresar nombre: \n");
    scanf("%s",compra.nombre);

    printf("Ingresar matricula: \n");
    scanf("%s",compra.matricula);

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
    strcpy(compra.nombre, compra.nombre); 
    strcpy(compra.matricula, compra.matricula);

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
                    printf("| Nombre: %s \t ID: %d \t Modelo: %s \t  Talla: %s \t Precio: $%0.2f \t Fecha de compra %d/%d/%d |\n", 
                    compra.nombre,producto.id_producto, producto.modelo, producto.talla, producto.precio,
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

// encontrar_alumno:
// 0 -> encontrado
// -1 -> no encontrado
int encontrar_alumno(int ID) {
    int encontrado = -1;
    int users[] = {1,2,3,4,5,6};  

    for (size_t i = 0; i < ARR_SIZE(users); i++)
    {
        if (users[i] != ID)
        {
            continue;
        }

        encontrado = 0;
    }

    return encontrado;
}

// validar: 
// 0: no reconocido
// 1: estudiante
// 2: administrador
int validar_usuario(int ID) {

    if (encontrar_alumno(ID) == 0) {
        return 1;
    } else if (ID == ADMIN_ID) {
        return 2;
    }

    return 0;
}