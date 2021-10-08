// Created by user on 01/10/2021.

#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int dato;
    struct elemento *sig;
    struct elemento *ant;
};

int insertarInicio(int datoNuevo, struct elemento **inicio, struct elemento **fin);

int insertarFinal(int datoNuevo, struct elemento **inicio, struct elemento **fin);

int insertarMedio(int datoNuevo, struct elemento *anterior);

int insertar(int datoNuevo, struct elemento **inicio, struct elemento **fin);

int eliminarInicio(struct elemento **inicio, struct elemento **fin);

int eliminarMedio(struct elemento *eliminado);

int eliminarFinal(struct elemento **inicio, struct elemento **fin);

int eliminar(int datoE, struct elemento **inicio, struct elemento **fin);

void mostrarAdelante(struct elemento *inicio);

void mostrarAtras(struct elemento *finRec);

void menu(char *);

void valida(int, int);

int validarOpcion(char *);

int main(){
    
    int dato, eliminarDato, nuevoDato, tipoFuncion;
    char respuesta;

    printf("Prueba de funcionamiento de listas dobles");
    printf("\n\n¿Desea probar el funcionamiento? \nA)Si    B)No    \n\n> Respuesta: ");
    scanf ("%c%*c", &respuesta);
    
    validarOpcion(&respuesta);
    
    if (respuesta == 'b' || respuesta == 'B'){
        printf ("\n\nGracias por usar el programa");
    }else{
        struct elemento *l1 = NULL, *l2 = NULL;
        do{
            menu(&respuesta);

            switch(respuesta){
                case 'a':
                case 'A':
                    tipoFuncion = 1;
                    printf("\n> Ingresa el dato que deseas agregar: ");
                    scanf ("%d%*c", &nuevoDato);
                    dato = insertarInicio(nuevoDato, &l1, &l2);
                    valida(tipoFuncion, dato);
                    break;
                case 'b':
                case 'B':
                    tipoFuncion = 1;
                    printf("\n> Ingresa el dato que deseas agregar: ");
                    scanf ("%d%*c", &nuevoDato);
                    dato = insertarMedio(nuevoDato, l1);
                    valida(tipoFuncion, dato);
                    break;
                case 'c':
                case 'C':
                    tipoFuncion = 1;
                    printf("\n> Ingresa el dato que deseas agregar: ");
                    scanf ("%d%*c", &nuevoDato);
                    dato = insertarFinal(nuevoDato, &l1, &l2);
                    valida(tipoFuncion , dato);
                    break;
                case 'd':
                case 'D':
                    tipoFuncion = 1;
                    printf("\n> Ingresa el dato que deseas agregar: ");
                    scanf ("%d%*c", &nuevoDato);
                    printf ("\nEn construcción....");
                    dato = insertar(nuevoDato, &l1, &l2);
                    valida(tipoFuncion, dato);
                    break;
                case 'e':
                case 'E':
                    tipoFuncion = 2;
                    dato = eliminarInicio(&l1, &l2);
                    valida(tipoFuncion, dato);
                    break;
                case 'f':
                case 'F':
                    printf ("\n> Ingresa el dato que se desea eliminar: ");
                    scanf ("%d%*c", &eliminarDato);
                    tipoFuncion = 2;
                    dato = eliminarMedio(l1);
                    valida(tipoFuncion, dato);
                    break;
                case 'g':
                case 'G':
                    tipoFuncion = 2;
                    dato = eliminarFinal(&l1, &l2);
                    valida(tipoFuncion, dato);
                    break;
                case 'h':
                case 'H':
                    printf ("\n> Ingresa el dato que se desea eliminar: ");
                    scanf ("%d%*c", &eliminarDato);
                    tipoFuncion = 2;
                    dato = eliminar(eliminarDato, &l1, &l2);
                    valida(tipoFuncion, dato);
                    break;
                case 'i':
                case 'I':
                    mostrarAdelante(l1);
                    break;
                case 'j':
                case 'J':
                    mostrarAtras(l2);
                    break;
                case 'k':
                case 'K':
                    printf ("\n\nSaliendo del programa...");
                    break;
                default:
                    printf("\n> Opción no válida");
                    menu(&respuesta);
                    break;
            }
        }while(respuesta!= 'k' && respuesta!= 'K');
    }

    return 0;
}

int insertarInicio(int datoNuevo, struct elemento **inicio, struct elemento **fin) {
    struct elemento *nuevo;
    nuevo = (struct elemento *) malloc(sizeof(struct elemento));

    if (nuevo == NULL) {
        return 0;
    }

    nuevo->dato = datoNuevo;
    nuevo->ant = NULL;
    nuevo->sig = *inicio;//Si no hay elementos, será nulo

    if (*inicio == NULL) {
        *fin = nuevo;//Nuevo fin al no tener más datos
    }else{
        (*inicio)->ant = nuevo;//Cambia el enlace si tiene un elemento o más
    }
    *inicio = nuevo;//Nuevo inicio

    return 1;
}

int insertarFinal(int datoNuevo, struct elemento **inicio, struct elemento **fin){
    struct elemento *nuevo;
    nuevo = (struct elemento *) malloc(sizeof(struct elemento));

    if (nuevo == NULL) {
        return 0;
    }

    nuevo->dato = datoNuevo;
    nuevo->sig = NULL;
    nuevo->ant = *fin;

    if (*fin == NULL){
        *inicio = nuevo;
        //*fin = nuevo;
    }else{
        (*fin)->sig = nuevo;
        //*fin = nuevo;
    }
    *fin = nuevo;

    return 1;
}

int insertarMedio(int datoNuevo, struct elemento *anterior){
    struct elemento *nuevo;
    nuevo = (struct elemento *) malloc(sizeof(struct elemento));

    if (nuevo == NULL) {
        return 0;
    }

    nuevo->dato = datoNuevo;
    nuevo->ant = anterior;
    nuevo->sig = anterior->sig;

    nuevo->sig->ant = nuevo;//anterior->sig->ant = nuevo;
    anterior->sig = nuevo;//No aplica porque se debe cambiar la estructura
    // nuevo->ant->sig = nuevo;
    return 1;
}

int insertar(int datoNuevo, struct elemento **inicio, struct elemento **fin){
    if (*inicio == NULL){
        return insertarInicio(datoNuevo, inicio, fin);
    }
    struct elemento *aux1 = *inicio, *aux2 = *inicio;

    while(aux1 != NULL){
        if (datoNuevo > aux1->dato){
            aux1 = aux1->sig;
        }
        break;
    }
    if(aux1->sig == NULL){
        return insertarInicio(datoNuevo, inicio, fin);
    }
    return insertarMedio(datoNuevo, aux1);
}

int eliminarInicio(struct elemento **inicio, struct elemento **fin){

    int datoEliminado = -1;

    if(*inicio == NULL){
        return datoEliminado;
    }

    struct elemento *eliminado = *inicio;

    datoEliminado = eliminado->dato;

    *inicio = (*inicio)->sig;

    if (*inicio==NULL){
        (*fin)=NULL;
    }else{
        (*inicio)->ant = NULL;
    }
    free(eliminado);

    return datoEliminado;
}

int eliminarMedio(struct elemento *eliminado){

    int datoEliminado = eliminado->dato;

    eliminado->ant->sig = eliminado->sig;

    eliminado->sig->ant = eliminado->ant;

    free(eliminado);

    return datoEliminado;
}

int eliminarFinal(struct elemento **inicio, struct elemento **fin){

    int datoEliminado = -1;

    if(*inicio == NULL){
        return datoEliminado;
    }

    struct elemento *eliminado = *fin;

    datoEliminado = eliminado->dato;

    *fin = (*fin)->ant;

    if (*fin==NULL){
        *inicio = NULL;
    }else{
        (*fin)->sig = NULL;
    }
    free(eliminado);

    return datoEliminado;
}

int eliminar(int datoE, struct elemento **inicio, struct elemento **fin){
    struct elemento *aux;
    aux = *inicio;

    while (aux != NULL){
        if (aux->dato == datoE){
            break;
            //aux = aux->sig;
        }
        aux = aux->sig;
    }

    if (aux == NULL){
        return -1;
    }
    if(aux->ant == NULL){
        return eliminarInicio(inicio, fin);
    }
    if(aux->sig == NULL){
        return eliminarInicio(inicio, fin);
    }
    return eliminarMedio(aux);
}

void mostrarAdelante(struct elemento *inicioRec){
    if(inicioRec == NULL){
        printf ("\nNo existen datos en la lista\n");
    }else{
        while(inicioRec != NULL){
            printf ("%d ->", inicioRec->dato);
            inicioRec = inicioRec->sig;
        }
    }
}

void mostrarAtras(struct elemento *finRec){
    if(finRec == NULL){
        printf ("\nNo existen datos en la lista\n");
    }else{
        while(finRec != NULL){
            printf ("%d ->", finRec->dato);
            finRec = finRec->ant;
        }
    }
}

/*******Funciones para validar opciones en el main*******/

int validarOpcion(char *respuesta){
    while (*respuesta!= 'A' && *respuesta!= 'a' && *respuesta!= 'B' && *respuesta != 'b'){
        printf ("\n\nOpcion no valida\n\n");
        printf ("Ingrese nuevamente una Opcion:\nA)Si    B)No    \n\nRespuesta: ");
        scanf ("%c%*c", respuesta);
    }
}

void menu(char *res){
    printf("\n> Elige una opción de las siguientes que se presentan: \n\n");
    printf("\t+----------------------+ +--------------------+ +------------------+ +------------+ +-------------------+\n");
    printf("\t| A)Insertar al Inicio | |B)Insertar en Medio | | C)Insertar Final | | D)Insertar | | E)Eliminar Inicio |\n");
    printf("\t+----------------------+ +--------------------+ +------------------+ +------------+ +-------------------+\n\n");
    printf("\t+------------------+ +------------+ +--------------------------+ +-----------------------+ +---------+\n");
    printf("\t| G)Eliminar Final | | H)Eliminar | | I)Mostrar Lista Adelante | | J)Mostrar Lista Atras | | k)Salir |\n");
    printf("\t+------------------+ +------------+ +--------------------------+ +-----------------------+ +---------+\n");
    printf("\n> Respuesta: ");
    scanf("%c%*c", res);
}

void valida(int tipo, int dato){
    switch(tipo){
        case 1:
            if (dato == 1){
                printf ("\n\nSe ha insertado con éxito\n");
            }else{
                printf ("\n\nLo sentimos, ha ocurrido un problema al insertar\n");
            }
            break;
        case 2:
            if (dato != -1){
                printf ("\n\nSe ha eliminado con éxito\n");
            }else{
                printf ("\n\nLo sentimos, ha ocurrido un problema al eliminar\n");
            }
            break;
        default:
            printf ("\n\nLo sentimos, ha ocurrido un problema\n");
            break;
    }
}