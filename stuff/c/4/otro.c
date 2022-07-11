#include <stdio.h>
#include <stdlib.h>
struct nodo {
    int dato;
    struct nodo *sig;
};
typedef struct nodo nd;
//funciones abajo del main necesitan declaracion


void enqueue(int dato, nd **inicio, nd **fin) {
    nd *nuevoptr;
    nuevoptr = (nd *) malloc(sizeof(nd));
    if (nuevoptr != NULL) {
        nuevoptr->dato = dato;
        nuevoptr->sig = NULL;
        if (*inicio == NULL) {

                *inicio = nuevoptr;
                (*inicio)->dato = dato;
                nuevoptr->sig = *topeptr;
                topeptr = nuevoptr;
            } else {
                (*fin)->sig = nuevoptr;
            }
            *fin=nuevoptr;
        }
        //nuevoptr->sigptr=finptr;
        //finptr->sigptr=nuevoptr;
        //finptr=nuevoptr;
    }


void imprimir(nd *inicio){//podemos usar la misma variable ya que se pasa por medio del valor

    if(inicio!=NULL) {
        while (inicio != NULL) {//comprobacion de que no este vacio la pila
            printf("\nValor: %d", inicio->dato);//impresion del dato
            inicio=inicio->sig;//movimiento al siguiente elemento
        }
    }else{
        printf("\nNo hay valores que imprimir, la pila esta vacia");
    }
}


int vacia(nd *topeptr){
    if(topeptr==NULL){
        printf("\nLa pila esta vacia");
        return 0;
    }else{
        printf("\nLa pila no esta vacia");
        return 1;
    }
}


void eliminar(nd **inicio, nd **fin){

    if(*inicio!=NULL && *fin!=NULL){
        nd *aux;
        aux=*inicio;
        printf("\nValor a borrar %d", (*inicio)->dato);
        *inicio=(*inicio)->sig;

        if(*inicio==NULL){
            printf("\nEste fue el ultimo elemento de la cola :0\n");
            *fin=NULL;
        }
        free(aux);
    }else{
        printf("\nNo hay elementos por eliminar ");
    }

}

int menu() {
    int opcion;


    printf("\nBienvenido al menu de opciones de pila que deseas realizar?");
    printf("\n1) Insertar datos \n2) Imprimir datos \n3) Eliminar datos \n4) Saber si esta vacia \n5) Salir del programa \nOpcion:");
    scanf("%d", &opcion);
    return opcion;

}
int main() {
    nd *inicio=NULL, *final=NULL;
    int opcion, numero;
    do{
        opcion=menu();
        switch(opcion) {
            case 1:
                printf("\nIntroduce el dato que deseas insertar: ");
                scanf("%i", &numero);

                enqueue(numero, &inicio, &final);
                imprimir(inicio);
                break;
            case 2:
                imprimir(inicio);
                break;
            case 3:
                eliminar(&inicio, &final);
                break;
            case 4:
                vacia(inicio);
                break;
            case 5:
                printf("\nGracias por usar el programa :)");

                break;

            default:
                printf("\nLa opcion no existe :(");

                break;
        }
    }while(opcion!=5);
    //video de simulacion de pilas con memoria dinamica y como es el comportamiento
    return 0;
}