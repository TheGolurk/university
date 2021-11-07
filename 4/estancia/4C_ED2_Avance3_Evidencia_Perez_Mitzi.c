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

#include "validator.c"
#include "administrador.c"
#include "usuario.c"

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

                mostrar_usuario_menu();
                

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