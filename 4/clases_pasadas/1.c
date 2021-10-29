#include <stdio.h>
#include <stdlib.h>
struct elemento{
    int dato ;
    struct elemento *ant;
    struct elemento *sig;
};

int insertarInicio(int datoNuevo, struct elemento **inicio, struct elemento **fin);
int insertarFinal(int datoNuevo, struct elemento **inicio, struct elemento **fin);
int insertarMedio(int datoNuevo, struct elemento *sig);
int insertar(int datoNuevo, struct elemento **inicio, struct elemento **fin);

int eliminarInicio(struct elemento **inicio, struct elemento **fin);
int eliminarFinal(struct elemento **inicio, struct elemento **fin);
int eliminarMedio(struct elemento *eliminado);
int eliminar (int datoE, struct elemento **inicio, struct elemento **fin);

void mostrarAdelante(struct elemento *inicioRec);
void mostrarAtras(struct elemento *fin);

int main (int argc, char **argv)
{
    struct elemento *inicioL1=NULL, *finL1=NULL;
    int i, dato;
    
    for (i=0; i<10; i++){
        dato=rand()%100;
        if(insertarInicio(dato, &inicioL1, &finL1)==1){
            printf("%d insertado\n", dato);
        }
    }
    mostrarAdelante(inicioL1);
    printf("\n");
    mostrarAtras(finL1);
    
    printf("\n");
    return 0;
}


int insertarInicio(int datoNuevo, struct elemento **inicio, struct elemento **fin){
    struct elemento *nuevo;
    nuevo=(struct elemento *)malloc(sizeof(struct elemento));
    if(nuevo==NULL){
        return 0;
    }
    nuevo->dato=datoNuevo;
    nuevo->ant=NULL;
    nuevo->sig=*inicio;
    
    if(*inicio==NULL){
        *fin=nuevo;
    }else{
        (*inicio)->ant=nuevo;
    }
    *inicio=nuevo;
    return 1;
}

void mostrarAdelante(struct elemento *inicioRec){
    while (inicioRec!=NULL){
        printf ("%d->", inicioRec->dato);
        inicioRec=inicioRec->sig;
    }
}

void mostrarAtras(struct elemento *finRec){
    while (finRec!=NULL){
        printf ("%d->", finRec->dato);
        finRec=finRec->ant;
    }
}

int insertarFinal(int datoNuevo, struct elemento **inicio, struct elemento **fin){
    struct elemento *nuevo;
    nuevo=(struct elemento *)malloc(sizeof(struct elemento));
    if(nuevo==NULL){
        return 0;
    }
    nuevo->dato=datoNuevo;
    nuevo->ant=NULL;
    nuevo->ant=*fin;
    if(*inicio==NULL){
        *inicio=nuevo;
    }else{
        (*fin)->sig=nuevo;
    }
    *fin=nuevo;
    return 1;
}

int insertarMedio(int datoNuevo, struct elemento *sig){
    //Solicitar memoria//
    struct elemento *nuevo;
    nuevo=(struct elemento *)malloc(sizeof(struct elemento));
    if(nuevo==NULL){
        return 0;
    }
    //Inicializar nuevo//
    nuevo->dato=datoNuevo;
    nuevo->sig=sig;
    nuevo->ant=sig->ant;
    //Unir a la lista 
    sig->ant->sig=nuevo;
    sig->ant=nuevo;
    return 1;
}

int eliminarInicio(struct elemento **inicio, struct elemento **fin){
    int datoEliminado=-1;
    if(*inicio==NULL){
        return datoEliminado;
    }
    struct elemento *eliminado;
    eliminado=*inicio;
    datoEliminado=eliminado->dato;
    *inicio=(*inicio)->sig; //El parentesis se puede poner en cualquier situacion//
    if(*inicio==NULL){
        *fin=NULL;
    }else{
        (*inicio)->ant=NULL;
    }
    free (eliminado);
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


int eliminar (int datoE, struct elemento **inicio, struct elemento **fin){
    struct elemento *aux=*inicio;
    
    while (aux!=NULL){
        if(aux->dato==datoE){
            break;
            aux=aux->sig;
        }
        if(aux==NULL){
            return 0;
        }
    }
}