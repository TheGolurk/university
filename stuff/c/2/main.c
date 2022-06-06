// Autor: Diego Peña Medina
// Descripcion:
// Fecha:
// Tipo y nombre de la evidencia:

#include <stdio.h>

struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct medicamento
{
    int codigo;
    char nombre[100];
    float precioUnitario;
    int unidades;
    struct fecha fechaCad;
};

typedef struct medicamento medi;

int main(int argc, char const *argv[])
{
    medi medi[10], *m;
    m = medi;

    int opc = 0;

    do
    {
        printf("1- Ingresar medicamenteos 2.- consultar medicamentos por codigo 3.- imprimir todos 4.-salir\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("ingrese los 10 medicamentos \n");
            for (int i = 0; i < 10; i++)
            {
                printf("codigo\n");
                scanf("%i", &(m + i)->codigo);

                printf("nombre ");
                scanf("%s", &(m + i)->nombre);

                printf("precio unitario \n");
                scanf("%f", &(m + i)->precioUnitario);

                printf("unidades \n");
                scanf("%d", &(m + i)->unidades);

                printf("dia \n");
                scanf("%d", &(m + i)->fechaCad.dia);

                printf("mes \n");
                scanf("%d", &(m + i)->fechaCad.mes);

                printf("anio \n");
                scanf("%d", &(m + i)->fechaCad.anio);
                fflush(stdin);
            }

            break;
        case 2:
            int codigoBuscar = 0;
            printf("codigo a buscar \n");
            scanf("%d", &codigoBuscar);

            for (size_t i = 0; i < 10; i++)
            {
                if (codigoBuscar == m[i].codigo)
                {
                    printf("informacion\n");
                    printf("%d \n", m[i].codigo);
                    printf("%f \n", m[i].nombre);
                    printf("%f \n", m[i].precioUnitario);
                    printf("%d \n", m[i].unidades);
                    printf("%d \n", m[i].fechaCad.dia);
                    printf("%d \n", m[i].fechaCad.mes);
                    printf("%d \n", m[i].fechaCad.anio);
                }
                
            }
            

            break;
        case 3:
            for (size_t i = 0; i < 10; i++)
            {
                if (codigoBuscar == m[i].codigo)
                {
                    printf("informacion\n");
                    printf("codigo %d nombre %s precio unitoraio %f unidades %d dia %d mes %d anio %d \n", m[i].codigo, m[i].nombre,  
                    m[i].precioUnitario, m[i].unidades, m[i].fechaCad.dia, m[i].fechaCad.mes, m[i].fechaCad.anio);
                }
                
            }

            break;
        case 4:
            printf("adios");
            break;

        default:
            printf("opcion incorrecta");
            break;
        }
    } while (opc != 4);

    return 0;
}
