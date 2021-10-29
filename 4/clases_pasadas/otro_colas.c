// Created by user on 05/10/2021.

#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int dato;
    struct elemento *sig;
};
//Estructura adicional para encapsular

struct cola{
    struct elemento *inicio;
    struct elemento *fin;
};

int insertar(struct elemento **inicio, struct elemento **fin, int datoNuevo);

int eliminar(struct elemento **inicio, struct elemento **fin);

int estaVacia(struct elemento *inicio);

int primero(struct  elemento *inicio);

int main(){

    return 0;
}

int insertar(struct elemento **inicio, struct elemento **fin, int datoNuevo){
    struct elemento *nuevo;
    nuevo = (struct elemento *) malloc(sizeof (struct elemento));
    if (nuevo == NULL){
        return 0;
    }
    nuevo->dato = datoNuevo;
    nuevo->sig = NULL;
    if (*inicio == NULL){
        *inicio = nuevo;
    }else{
        (*fin)->sig= nuevo;
    }
    *fin = nuevo;
    return 1;
}

int eliminar(struct elemento **inicio, struct elemento **fin){
    if (*inicio == NULL){
        return 0;
    }
    struct elemento *eliminado = *inicio;
    int datoEliminado = eliminado->dato;

    *inicio = eliminado->sig;//*inicio->sig;
    if (*inicio == NULL){
        *fin = NULL;
    }
    free(eliminado);
    return datoEliminado;
}

int estaVacia(struct elemento *inicio){
    if (inicio == NULL){
        return 1;
    }
    return 0;
}

int primero(struct elemento *inicio){
    if (estaVacia(inicio)){
        return -1;
    }
    return inicio->dato;
}