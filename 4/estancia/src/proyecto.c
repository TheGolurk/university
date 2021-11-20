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

    Notas: El proyecto usa git, en caso de mirar las versiones se puede usar checkout de 
    tags para volver a el momento en el que se subió la actividad. (Tags a partir de la evidencia de avance 3).
         - |Solo funciona si se descarga el proyecto desde el repositorio|

    Ej: $ git checkout tags/v0.3 -b develop_tag

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>

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
};

// Declaracion
void agregar_producto();
void eliminar_producto(()
void modificar_producto(int id);

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