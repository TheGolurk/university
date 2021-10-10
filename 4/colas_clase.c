// Created by user on 05/10/2021.
// ME LO PASO MITZI
#include <stdio.h>
#include <stdlib.h>
/***Funciones o elementos para realizar una cola**/
struct libro{
    char autor[50];
    char titulo[50];
    int numPag;
};

struct elementoCola{
    struct libro dato;
    struct elementoCola *sig;
};

int insertar(struct elementoCola **inicio, struct elementoCola **fin, struct libro datoNuevo);

struct libro eliminar(struct elementoCola **inicio, struct elementoCola **fin);

int estaVacia(struct elementoCola *inicio);

struct libro primero(struct elementoCola *inicio);

struct libro capturar();

/*************************************/

struct elementoLista{
    char dato;
    struct elementoLista *sig;
};

int insertarinicio(struct elementoLista **inicio, struct elementoLista **fin, char datoNuevo);

int insertarFinal(struct elementoLista **inicio, struct elementoLista **fin, char datoNuevo);

void mostrar(struct elementoLista *inicio);

int insertarDespuesDe(struct elementoLista *anterior, char datoNuevo);//Enmedio

int insertarOrdenado(struct elementoLista **inicio, struct elementoLista **fin, char datoNuevo);

int main(){
    struct libro aux;
    struct elementoCola *inicio = NULL, *fin = NULL, *inicio1 = NULL, *inicio2 = NULL, *inicio3 = NULL, *fin1 = NULL, *fin2 = NULL, *fin3 = NULL;
    for (int i = 0; i < 5; ++i) {
        aux = capturar();
        if (insertar(&inicio, &fin, aux) == 1){
            printf ("\nAgregado");
        }
    }
    while(!estaVacia(inicio)){
        aux = eliminar(&inicio, &fin);
        //imprimir los datos del libro
        printf ("%s, %s, %d\n", aux.titulo, aux.autor, aux.numPag);
        if (aux.numPag < 50){
            insertar(&inicio1, &fin1, aux);
        }else if(aux.numPag < 100){
            insertar(&inicio2, &fin2, aux);
        }else{
            insertar(&inicio3, &fin3, aux);
        }
    }
    while(!estaVacia(inicio1)){
        aux = eliminar(&inicio1, &fin1);
        //imprimir los datos del libro
        printf ("%s, %s, %d\n", aux.titulo, aux.autor, aux.numPag);
    }
    while(!estaVacia(inicio2)) {
        aux = eliminar(&inicio2, &fin2);
        //imprimir los datos del libro
        printf("%s, %s, %d\n", aux.titulo, aux.autor, aux.numPag);
    }
    while(!estaVacia(inicio3)){
        aux = eliminar(&inicio3, &fin3);
        //imprimir los datos del libro
        printf ("%s, %s, %d\n", aux.titulo, aux.autor, aux.numPag);
    }
    return 0;
}

int insertar(struct elementoCola **inicio, struct elementoCola **fin, struct libro datoNuevo){
    struct elementoCola *nuevo;
    nuevo = (struct elementoCola *) malloc(sizeof (struct elementoCola));
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

struct libro eliminar(struct elementoCola **inicio, struct elementoCola **fin){
    struct libro datoEliminado = {"Desconocido"};
    if (*inicio == NULL){
        return datoEliminado;
    }
    struct elementoCola *eliminado = *inicio;
    datoEliminado = eliminado->dato;

    *inicio = eliminado->sig;//*inicio->sig;
    if (*inicio == NULL){
        *fin = NULL;
    }
    free(eliminado);
    return datoEliminado;
}

int estaVacia(struct elementoCola *inicio){
    if (inicio == NULL){
        return 1;
    }
    return 0;
}

struct libro primero(struct elementoCola *inicio){
    struct libro info = {"No pues xd"};
    if (estaVacia(inicio)){
        return info;
    }
    return inicio->dato;
}

struct libro capturar(){
    struct libro auxLibro;
    printf ("\nIntroduce el título: ");
    scanf ("%[^\n]%*c", auxLibro.titulo);
    printf ("\nIntroduce el autor: ");
    scanf ("%[^\n]%*c", auxLibro.autor);
    printf ("\nIntroduce el numero de paginas: ");
    scanf ("%d%*c", &auxLibro.numPag);

    return auxLibro;
}
/******/
int insertarinicio(struct elementoLista **inicio, struct elementoLista **fin, char datoNuevo){
    struct elementoLista *nuevo;

    nuevo=(struct elementoLista *)malloc(sizeof(struct elementoLista));

    if (nuevo==NULL){
        return 0;//No nos dio memoria y no podemos insertar
    }

    nuevo->dato=datoNuevo;
    nuevo->sig=*inicio;

    if (*inicio==NULL)
    {
        *fin=nuevo;
    }

    *inicio=nuevo;

    return 1;//Validacion de que si pude insertar
}

int insertarFinal(struct elementoLista **inicio, struct elementoLista **fin, char datoNuevo){
    struct elementoLista *nuevo;

    nuevo = (struct elementoLista *) malloc (sizeof(struct elementoLista));

    if (nuevo==NULL){
        return 0;
    }

    nuevo->dato = datoNuevo;
    nuevo->sig = NULL;

    if(*fin!=NULL)
    {
        (*fin)->sig = nuevo;
        *inicio = nuevo;
    }else{
    }

    *fin=nuevo;

    return 1;
}

int insertarDespuesDe(struct elementoLista *anterior, char datoNuevo){
    struct elementoLista *nuevo;
    
    nuevo = (struct elementoLista *)malloc(sizeof(struct elementoLista));
    
    if (nuevo==NULL){
        return 0;
    }
    
    nuevo->dato = datoNuevo;
    nuevo->sig = anterior->sig;
    anterior->sig = nuevo;
    
    return 1;
}

int insertarOrdenado(struct elementoLista **inicio, struct elementoLista **fin, char datoNuevo){

    if(*inicio == NULL){
        return insertarinicio(inicio, fin, datoNuevo);
    }

    struct elementoLista *aux1 = *inicio, *aux2=*inicio;

    while(aux2!=NULL)
    {/*
        if ()
        {
            return 0;//No sen pudo insertar
        }*/
        if(datoNuevo > aux2->dato)
        {
            aux1 = aux2;
            aux1 = aux2->sig;
        }else{
            break;
        }
    }
    if(aux1 == NULL){
        return insertarinicio(inicio, fin, datoNuevo);
    }
    if(aux2 == NULL){
        return insertarinicio(inicio, fin, datoNuevo);
    }
    return insertarDespuesDe(aux1, datoNuevo);
}

void mostrar(struct elementoLista *inicio){

    printf ("\n");

    while(inicio!=NULL)
    {
        printf ("%d->", inicio->dato);
        inicio=inicio->sig;

    }

}
//Funcion hecha en clase xd

