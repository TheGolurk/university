#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrar_usuario_ad(){

    int opc = 0;
    printf("--------------MENU DE ADMINISTRADOR----------------\n");
    printf("1.- Agregar productos\n");   
    printf("2.- Editar productos\n");  
    printf("3.- Eliminar producto\n");     
    printf("4.- Mostrar productos vendidos\n");   
    printf("---------------5.- Salir---------------------------\n");
    scanf("%d", &opc);

    while (opc != 5)
    {

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
            break;
        }

    }


}