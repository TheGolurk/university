// Autor:
// Descripcion:
// Fecha:
// Tipo y nombde de evidencia

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct nodo{
    int turno;
    char nombre[100];
    struct nodo *sigPtr;
}Nodo;

typedef struct nodo nd;

void enqueue(int turno, char nombre[], nd **inicio, nd **fin) {
    nd *nuevoptr;
    nuevoptr = (nd *) malloc(sizeof(nd));
    if (nuevoptr!= NULL) {
        strcpy(nuevoptr->nombre, nombre);
        nuevoptr->turno = turno;
        nuevoptr->sigPtr = NULL;
        if (*inicio == NULL)
        {
            *inicio = nuevoptr;
        } else {
            (*fin)->sigPtr = nuevoptr;
        }
    }
}

void listar(nd *inicio) {
    while (inicio != NULL)
    {
        printf("%s \n", inicio->nombre);
        inicio = inicio->sigPtr;
    }
}

void contar(nd *inicio) {
    int contar = 0;
    while (inicio != NULL)
    {
        contar++;
        inicio = inicio -> sigPtr;
    }
}

void promedio(nd *inicio) {
    int contar = 0;
    while (inicio != NULL)
    {
        contar++;
        inicio = inicio -> sigPtr;
    }
}

int main(int argc, char const *argv[])
{

    nd *inicio=NULL, *final=NULL;

    char letra = 's';    

            int turno = 0;

    while (letra == 'n')
    {
        printf("Introducir a un usuario mas?");
        scanf("%c", &letra);
        int numeroaleatorio = (rand() % (2-1+1)+1);
        if (numeroaleatorio == 1) {
            char nombre[100];
            printf("\n");
            printf("Nombre ");
            scanf("%s", &nombre);
            enqueue(turno, nombre, &inicio, &final);
        } else if (numeroaleatorio == 2) {

        }
        turno++;
        listar(inicio);
        contar(inicio);


        /* code */
    }
    

    return 0;
}
