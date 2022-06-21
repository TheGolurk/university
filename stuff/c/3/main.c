// autor:
// descripcion:
// fecha:
// tipo y nombre de evidencia:

#include <stdio.h>
#include <stdlib.h>

struct fecha
{
    int dia;
    int mes;
    int anio;
};

typedef struct nodo
{
    int ISBN;
    char Autor[100];
    char Titulo[100];
    struct fecha fechaDevo;
    struct nodo *sigPtr;
} Nodo;

void insertar(Nodo **);
void sacar(Nodo **);
void listar(Nodo *);
void consultar(Nodo *);
void contar(Nodo *);

int main()
{
    Nodo *topePtr = NULL;

    int opc = 0;

    do
    {
        printf("Ingrese opcion: 1.- ingresar 2.- sacar 3.- listar 4.- consultar \n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            insertar(&topePtr);
            break;
        case 2:
            sacar(&topePtr);
            break;
        case 3:
            listar(topePtr);
            contar(topePtr);
            break;
        case 4:
            consultar(topePtr);
            contar(topePtr);
            break;
        case 5:
            printf("adios\n");
            break;

        default:
            printf("Opcion incorrecta\n");
            break;
        }
    } while (opc != 5);

    return 0;
}

void insertar(Nodo **topePtr)
{
    Nodo n;
    printf("ingrese isbn\n");
    scanf("%d", &n.ISBN);

    printf("ingrese dia \n");
    scanf("%d", &n.fechaDevo.dia);

    printf("ingrese mes \n");
    scanf("%d", &n.fechaDevo.mes);

    printf("ingrese anio \n");
    scanf("%d", &n.fechaDevo.anio);

    Nodo *nuevoPtr;
    nuevoPtr = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoPtr != NULL)
    {
        nuevoPtr->ISBN = n.ISBN;
        printf("");
        printf("ingrese autor ");
        scanf("%s", &nuevoPtr->Autor);

        printf("ingrese titulo ");
        scanf("%s", &nuevoPtr->Titulo);

        nuevoPtr->fechaDevo.dia = n.fechaDevo.dia;
        nuevoPtr->fechaDevo.mes = n.fechaDevo.mes;
        nuevoPtr->fechaDevo.anio = n.fechaDevo.anio;
        nuevoPtr->sigPtr = *topePtr;
        *topePtr = nuevoPtr;
    }
}

void sacar(Nodo **topePtr) {
     if(*topePtr !=NULL){
        Nodo *aux;
        aux=*topePtr;
        printf("%d",(*topePtr)->ISBN);
        *topePtr=(*topePtr)->sigPtr;
        free(aux);
    }
}

void contar(Nodo *topePtr) {
    Nodo *contador;
    contador = topePtr;
    int pos = 0;

    if (topePtr != NULL)
    {
        while (contador != NULL)
        {
            pos++;
            contador = contador->sigPtr;
        }
    }

    printf("Hay %d libros \n", pos);
}

void listar(Nodo *topePtr)
{
    Nodo *contador;
    contador = topePtr;
    if (topePtr != NULL)
    {
        while (contador != NULL)
        {
            printf("ISBN: %d Autor: %s Titulo: %s FechaDevolucion: %d/%d/%d \n",
                   contador->ISBN, contador->Autor, contador->Titulo,
                   contador->fechaDevo.dia, contador->fechaDevo.mes, contador->fechaDevo.anio);
            contador = contador->sigPtr;
        }
    }
}

void consultar(Nodo *topePtr)
{
    int isbnN = 0;
    printf("ingrese isbn a buscar\n");
    scanf("%d", &isbnN);

    Nodo *contador;
    contador = topePtr;
    if (topePtr != NULL)
    {
        while (contador != NULL)
        {
            if (contador->ISBN == isbnN)
            {
                printf("ISBN: %d Autor: %s Titulo: %s FechaDevolucion: %d/%d/%d \n",
                       contador->ISBN, contador->Autor, contador->Titulo,
                       contador->fechaDevo.dia, contador->fechaDevo.mes, contador->fechaDevo.anio);
            }

            contador = contador->sigPtr;
        }
    }
}