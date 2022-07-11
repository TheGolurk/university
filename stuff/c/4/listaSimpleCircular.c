//Materia: Estructura de datos
//Programa: Listas circulares simples
//Fecha: 30 de junio, 2022

#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    int dato;
    struct nodo *sigPtr;
}Nodo;


Nodo *crearNodo(int valor);
void insertar(Nodo **listaPtr, int);
int eliminar(Nodo **listaPtr, int);
void borrar(Nodo **listaPtr, int dato);
void imprimir(Nodo *listaPtr);


int main()
{
    Nodo *listaPtr=NULL;
    int valor, opc;
    do
    {
        printf("\n\n-- LISTAS CIRCULARES SIMPLES--\n\n1. Insertar dato\n 2. Eliminar dato \n 3. Salir\n");
        scanf("%d", &opc);

        switch(opc)
        {
            case 1: printf("Dato: ");
                    scanf("%d", &valor);
                    insertar(&listaPtr, valor);
                    imprimir(listaPtr);
                    break;
            case 2: printf("Dato a borrar: ");
                    scanf("%d", &valor);
                    //eliminar(&listaPtr, valor);
                    borrar(&listaPtr, valor);
                    imprimir(listaPtr);
                    break;
         }
    } while (opc!=3);

    return 0;
}

//FUnción para crear el nodo
Nodo *crearNodo(int valor)
{
    Nodo *nuevoPtr=NULL;

    nuevoPtr=malloc(sizeof(Nodo));
    if (nuevoPtr!=NULL)
    {
        nuevoPtr->dato=valor;
        nuevoPtr->sigPtr=nuevoPtr;
    }
    return nuevoPtr;
}


//Función para agregar un nodo a la lista simple circular
void insertar(Nodo **listaPtr, int valor)
{
    Nodo *nuevoPtr;

    nuevoPtr=crearNodo(valor);

    if (nuevoPtr!=NULL)
    {
        if (*listaPtr!=NULL)
        {
            nuevoPtr->sigPtr=(*listaPtr)->sigPtr;
            (*listaPtr)->sigPtr=nuevoPtr;
        }
        *listaPtr=nuevoPtr;
    }
    else
     printf("Memoria insuficiente");
}

//Función que borra un nodo de la lista simple circular
//en caso de no encontrarlo se envía un mensaje
//Versión: Joyanes
int eliminar(Nodo **listaPtr, int valor){
    Nodo *actual;

    int encontrado=0;

    if (*listaPtr==NULL)
        return 0;

    actual=*listaPtr;

    while ((actual->sigPtr!=*listaPtr) && (!encontrado))
    {
        encontrado=(actual->sigPtr->dato==valor);
        if (!encontrado)
            actual=actual->sigPtr;
    }

    encontrado=(actual->sigPtr->dato==valor);

    if (encontrado)
    {
        Nodo *auxPtr;

        auxPtr=actual->sigPtr;

        if (*listaPtr==(*listaPtr)->sigPtr)
            *listaPtr=NULL;
        else{
            if (auxPtr==*listaPtr)
            {
                *listaPtr=actual;
            }
            actual->sigPtr=auxPtr->sigPtr;
        }
        free(auxPtr);
    }
    else
        printf("Elemento no encontrado");
    return 0;
}


//https://conclase.net/c/edd/cap4
void borrar(Nodo **listaPtr, int dato) {
    Nodo *inicioPtr;

    inicioPtr=*listaPtr;

    do {
        if ((*listaPtr)->sigPtr->dato!=dato){
                *listaPtr=(*listaPtr)->sigPtr;
           }
     } while ((*listaPtr)->sigPtr->dato != dato && *listaPtr!= inicioPtr);

     if ((*listaPtr)->sigPtr->dato == dato){
        if (*listaPtr==(*listaPtr)->sigPtr){
            free(*listaPtr);
            *listaPtr=NULL;
        }
        else {
            inicioPtr=(*listaPtr)->sigPtr;
            (*listaPtr)->sigPtr=inicioPtr->sigPtr;
            free(inicioPtr);
        }
     }
}

//Función para imprimir los nodos de la lista simple circular
void imprimir(Nodo *listaPtr)
{
    Nodo *auxPtr;

    if (listaPtr==NULL)
        printf("Lista circular vacia");
    else
    {
        auxPtr=listaPtr->sigPtr;

        do{
            printf("%d\t", auxPtr->dato);
            auxPtr=auxPtr->sigPtr;
        }while (auxPtr!=listaPtr->sigPtr);
    }

}




