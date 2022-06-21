#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *sigPtr;
}Nodo;

void insertar(int, Nodo **);

void imprimir(Nodo *);

void eliminar(Nodo **topePtr);

int main()
{
    int opcion;
    int dato;
    Nodo *topePtr=NULL;
   do{
       
       printf("\nBienvenido al programa\n");
       printf("\n¿Que opcion desea escoger?\n");
       printf("\n1.Insertar datos\n");
       printf("\n2.Imprimir datos\n");
       printf("\n3.Eliminar datos\n");
       printf("\n4.Salir\n");
       printf("\nSu opcion es: ");
       scanf("%d",&opcion);
       
       switch(opcion){
           case 1:
           
           printf("Inserte el primer numero: ");
           scanf("%d",&dato);
           printf("Inserte el segundo numero: ");
           scanf("%d",&dato);
           insertar(dato, &topePtr);
        break;
        
        case 2:
        imprimir(topePtr);
        break;
        
        case 3:
        eliminar(&topePtr);
        break;
       }
       
   }while(opcion!=4);
    
    return 0;
}

void insertar(int dato, Nodo **topePtr){
    Nodo *nuevoPtr;
    nuevoPtr=(Nodo *)malloc (sizeof(Nodo));// asigna una parte de memoria
    if(nuevoPtr!=NULL){ //valida si es se asigno la memoria siendo el NODO diferente a null
        nuevoPtr->dato=dato;
        nuevoPtr->sigPtr=*topePtr;
        *topePtr=nuevoPtr;
    }
}   

void imprimir(Nodo *topePtr){
    Nodo *contador;
    contador = topePtr;
    if(topePtr!=NULL){
    while(contador!=NULL){
        printf("Nodo %d", contador->dato);
        contador = contador->sigPtr;
    }
    }else
    printf("Pila Vacia");
    
}

void eliminar(Nodo **topePtr){

     if(*topePtr !=NULL){
        Nodo *aux;
        aux=*topePtr;
            printf("%d",(*topePtr)->dato);
            *topePtr=(*topePtr)->sigPtr;
            free(aux);
    }

}