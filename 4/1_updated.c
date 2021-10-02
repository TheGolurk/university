#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int dato;
    struct elemento *sig;
    struct elemento *ant;
};

int insertarInicio(int datoNuevo, struct elemento **inicio, struct elemento **fin);
int insertarFinal(int datoNuevo, struct elemento **inicio, struct elemento **fin);
int insertarMedio(int datoNuevo, struct elemento *anterior);
int insertarOrdenado(int datoNuevo, struct elemento **inicio, struct elemento **fin);
void mostrarAdelante(struct elemento *inicio);
void mostrarAtras(struct elemento *finRec);

int eliminarInicio(struct elemento **inicio, struct elemento **fin);
int eliminarMedio(struct elemento *eliminado);
int eliminarFinal(struct elemento **inicio, struct elemento **fin);
int eliminar(int datoE, struct elemento **inicio, struct elemento **fin);

int main()
{
    struct elemento *inicio = NULL, *fin = NULL;
    insertarInicio(10, &inicio, &fin);
    insertarFinal(4, &inicio, &fin);
    mostrarAdelante(inicio);

    return 0;
}

int insertarInicio(int datoNuevo, struct elemento **inicio, struct elemento **fin)
{
    struct elemento *nuevo;
    nuevo = (struct elemento *)malloc(sizeof(struct elemento));

    if (nuevo == NULL)
    {
        return 0;
    }

    nuevo->dato = datoNuevo;
    nuevo->ant = NULL;
    nuevo->sig = *inicio;

    if (*inicio == NULL)
    {
        *fin = nuevo;
    }
    else
    {
        (*inicio)->ant = nuevo;
    }
    *inicio = nuevo;

    return 1;
}

int insertarFinal(int datoNuevo, struct elemento **inicio, struct elemento **fin)
{
    struct elemento *nuevo;
    nuevo = (struct elemento *)malloc(sizeof(struct elemento));

    if (nuevo == NULL)
    {
        return 0;
    }

    nuevo->dato = datoNuevo;
    nuevo->sig = NULL;
    nuevo->ant = *fin;

    if (*fin == NULL)
    {
        *inicio = nuevo;
    }
    else
    {
        (*fin)->sig = nuevo;
    }
    *fin = nuevo;

    return 1;
}

int insertarMedio(int datoNuevo, struct elemento *anterior)
{
    struct elemento *nuevo;
    nuevo = (struct elemento *)malloc(sizeof(struct elemento));

    if (nuevo == NULL)
    {
        return 0;
    }

    nuevo->dato = datoNuevo;
    nuevo->ant = anterior;
    nuevo->sig = anterior->sig;

    nuevo->sig->ant = nuevo;
    anterior->sig = nuevo;
    return 1;
}

int insertarOrdenado(int datoNuevo, struct elemento **inicio, struct elemento **fin)
{
    if (*inicio == NULL)
    {
        return insertarInicio(datoNuevo, inicio, fin);
    }
    struct elemento *aux1 = *inicio, *aux2 = *inicio;

    while (aux1 != NULL)
    {
        if (datoNuevo > aux1->dato)
        {
            aux1 = aux1->sig;
        }
        break;
    }
    if (aux1->sig == NULL)
    {
        return insertarInicio(datoNuevo, inicio, fin);
    }
    return insertarMedio(datoNuevo, aux1);
}

void mostrarAdelante(struct elemento *inicioRec)
{
    while (inicioRec != NULL)
    {
        printf("%d ->", inicioRec->dato);
        inicioRec = inicioRec->sig;
    }
}

void mostrarAtras(struct elemento *finRec)
{
    while (finRec != NULL)
    {
        printf("%d ->", finRec->dato);
        finRec = finRec->ant;
    }
}

int eliminarInicio(struct elemento **inicio, struct elemento **fin)
{

    int datoEliminado = -1;

    if (*inicio == NULL)
    {
        return datoEliminado;
    }

    struct elemento *eliminado = *inicio;

    datoEliminado = eliminado->dato;

    *inicio = (*inicio)->sig;

    if (*inicio == NULL)
    {
        (*fin) = NULL;
    }
    else
    {
        (*inicio)->ant = NULL;
    }
    free(eliminado);

    return datoEliminado;
}

int eliminarMedio(struct elemento *eliminado)
{

    int datoEliminado = eliminado->dato;

    eliminado->ant->sig = eliminado->sig;

    eliminado->sig->ant = eliminado->ant;

    free(eliminado);

    return datoEliminado;
}

int eliminarFinal(struct elemento **inicio, struct elemento **fin)
{

    int datoEliminado = -1;

    if (*inicio == NULL)
    {
        return datoEliminado;
    }

    struct elemento *eliminado = *fin;

    datoEliminado = eliminado->dato;

    *fin = (*fin)->ant;

    if (*fin == NULL)
    {
        *inicio = NULL;
    }
    else
    {
        (*fin)->sig = NULL;
    }
    free(eliminado);

    return datoEliminado;
}

int eliminar(int datoE, struct elemento **inicio, struct elemento **fin)
{
    struct elemento *aux;
    aux = *inicio;

    while (aux != NULL)
    {
        if (aux->dato == datoE)
        {
            break;
        }
        aux = aux->sig;
    }

    if (aux == NULL)
    {
        return 0;
    }
    if (aux->ant == NULL)
    {
        return eliminarInicio(inicio, fin);
    }
    if (aux->sig == NULL)
    {
        return eliminarInicio(inicio, fin);
    }
    return eliminarMedio(aux);
}
