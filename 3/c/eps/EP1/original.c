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
    char opt = 's';
    int menu = 0;

    do
    {

        printf("Selecciona una opcion\n");
        printf(" 1.- Suma de digitos\n 2.- Dia de año\n 3.- Piramide\n 4.- Dibujar una piramide\n 5.- Salir\n");
        scanf("%d", &menu);
        fflush(stdin);
        fflush(stdout);

        switch (menu)
        {
        case 1:
            break;

        case 2:
            break;

        case 3:
            int nums = 1;
            int space = 10;
            
            int base = 9;
            int baseleft = base;
            int baseright = base;

            for (size_t t = 10; t > 0; t--)
            { 

                for (size_t i = 0; i < space; i++)
                { 
                printf(" ");
                }

                for (size_t i = 0; i < nums; i++)
                {
                printf("%d", baseleft);
                baseleft--;

                if (baseleft < 0) {
                    baseleft = 9;
                }

                }

                baseright = baseleft + 2;

                for (size_t i = 1; i < nums; i++)
                {

                if (baseright > 9) {
                    baseright = 0;
                }

                printf("%d", baseright);
                baseright++;
            
                }

                nums++;
                space--;
            
                base--;
                baseleft = base;
                baseright = base;

                printf("\n");

            }

            printf("\n\n\n\n");
            break;

        case 4:

            int size;
            int lenght;

            printf("Introduce la altura y largo\n");
            scanf("%d %d", &size, &lenght);

            if (size < 3 || lenght < 13)
            {
                printf("Numeros %d %d fuera de rango", size, lenght);
            }

            int general = lenght - 5;
            int secondTriangle = (general / 2) + 1;
            int firstTriangle = general - secondTriangle;

            int spaces = firstTriangle + 3;
            int limit = 1;
            int spacesFirst = 3;

            int firstTriangleTMP = firstTriangle;
            
            // General size for the first and second triangle.
            for (size_t i = 1; i <= secondTriangle; i++)
            {

                // there are 2 spaces of height from second triangle to first triangle
                if (i < 3)
                {

                for (size_t j = 0; j < spaces; j++)
                {
                    printf(" ");
                }

                } else {  // We can start to print the first triangle once the spaces of height was passed
                
                printf("  ");

                for (size_t q = 1; q <= firstTriangleTMP-1; q++)
                {
                    printf(" ");
                }

                // repeat across the lenght of first triangle and only print the character outline 
                for (size_t q = firstTriangleTMP; q <= firstTriangle; q++)
                {        
                    if (q == firstTriangleTMP || i == secondTriangle || q == firstTriangle)
                    {
                    printf("*");
                    }else {
                    printf(" ");
                    }
                    
                }

                firstTriangleTMP--;

                printf(" ");

                }

                // second triangle
                for (size_t t = 1; t <= limit; t++)
                {
                if (t == 1 || i == secondTriangle || t == limit)
                {
                    printf("*");  
                } else if (t > 1) {
                    printf(" ");
                }
                }
                
                limit += 1;
                
                printf("\n");
            }
            
            // Base
            for (size_t i = 0; i < lenght; i++)
            {
                printf("*");
            }
            
            printf("\n");

            // the middle of the base, have a character only in the spaces of (lenght variable)-1
            for (size_t i = 0; i < lenght; i++)
            {
                printf(" ");
                if (i == 0 || i == lenght-4)
                {
                printf("*");
                }
                
            }

            printf("\n");

            for (size_t i = 0; i < 2; i++)
            {
                printf(" ");
            }
            for (size_t i = 0; i < lenght-4; i++)
            {
                printf("*");
            }

            break;
        
        case 5:
            printf("Adios\n");
            return 0;
        
        default:
            printf("Opcion incorrecta\n");
            return 1;
        }
        
        printf("Desea continuar? s/n\n");
        scanf(" %c", &opt);

    } while (opt == 's');
    
    return 0;
}
