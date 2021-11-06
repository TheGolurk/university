/***
PROYECTO DE ESTANCIA: ONLINE SHOP
AUTORES:
HERNÁNDEZ NÁJERA CHRISTIAN
PÉREZ BALTAZAR MITZI GUADALUPE
VALLE GONZÁLEZ LORENA
***/


/*
compile:
 https://dev.to/iamkhalil11/all-you-need-to-know-about-c-static-libraries-1o0b
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validator.c"


//declaración del  struct alumno
struct alumno {

    int id_alumno;
    char nombre[30];
    char grupo[5];
    int  opcionRealizar;
    char modelo[20];

};

//declaración de struct administrador
struct administrador{
  int id_identificación;
  int opcion;
};


//declaración de struct productos
struct productos{
  int id_producto;
  char modelo[20];
  char talla[15];
  float precio;
  int cant_disponible;

};

//declaraci+on de struct compras
struct compras{
  int id_compra;
  int id_producto;
  int fcompra;
  
};


//información de los alumnos debe tener consulta de los productos, hacer su compra, consultar compra
void c_productos(){

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

void compra(){

}

void c_compra(){

}



//información del administrador debe contener   para agregar , editar,eliminar y mostrar los productos vendidos
void agregar(){

    FILE *ptrArchivo;
    ptrArchivo = fopen("productos.dat", "a+");
    if (ptrArchivo == NULL) {
        return;
    }

    struct productos reg_producto, reg;

    printf("Asignar clave para el producto:");
    scanf("%d", &reg_producto.id_producto);


    printf("Modelo:");
    scanf("%s", &reg_producto.modelo);

    printf("Tallas:");
    scanf("%d",&reg_producto.talla);


    printf("Cantidad disponible:");
    scanf("$d", &reg_producto.cant_disponible);


    printf("Precio:");
    scanf("%f", &reg_producto.precio);
}

void modificar(){

}


void eliminar(){

}


void mostrar_ventas(){

}

//para hacer relación de la compra del alumno 
void inf_compras(){

}

int main(int argc, char const *argv[])
{

    int opcion = 0;
    int ID;


    while(opcion != 3)
    {

        printf("\n---------------------------------------------------");
        printf("\n BIENVENIDO A ONLINE SHOP");
        printf("\n---------------------------------------------------");
        printf("Seleccione el modo de usuario:\n");
        printf("1.-ALUMNO\n     2.- ADMINISTRADOR\n 3.- Salir");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingresar ID de identificación");
                scanf("%d", &ID);

                if ( validar_usuario(ID) != 1 )
                {
                    printf("Usuario no valido");
                }

                printf("menu de alumno");
                

                break;

            case 2:
                printf("Ingresar ID de identificación");
                scanf("%d",&ID);

                if ( validar_usuario(ID) != 2 )
                {
                    printf("Usuario no valido");
                }

                printf("menu de administrador");

                break;

            case 3:
                printf("HASTA PRONTO");
                break;

            default:
                break;


        }

    }

  return 0;
}