#include <stdio.h>

#define enero 31
#define marzo 31
#define abril 30
#define mayo 31
#define junio 30
#define julio 31
#define agosto 31
#define septiembre 30
#define octubre 31
#define noviembre 30
#define diciembre 31

int main(int argc, char const *argv[])
{   
    char opt;
    int menu = 0;

    while (opt != 'n')
    {

        printf("Selecciona una opcion\n");
        printf(" 1.- Suma de digitos\n 2.- Dia de año\n 3.- Piramide\n 4.- Dibujar una piramide\n 5.- Salir\n");
        scanf("%d", &menu);

        switch (menu)
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
            printf("Adios\n");
            return 0;
        
        default:
            printf("Opcion incorrecta\n");
            return 1;
        }

        printf("Desea continuar? s/n \n");
        scanf("%c", &opt);
    }
    
    return 0;
}
