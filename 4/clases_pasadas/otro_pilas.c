// Created by user on 20/09/2021.
// Clase de pilas

#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int dato;
    struct elemento *sig;//para que termine el ciclo
};

int insertar(struct elemento **cima, int datoNuevo);
//Para insertar necesitas los datos nuevos y la pila que apunta a ese elemento nuevo
//Devuelve un entero como booleano [si o no puedo insertar]
int eliminar(struct elemento **cima);
////Puede regresar el tipo de dato que se está eliminando
////Necesita la pila para eliminar el elemento deseado
int estaVacia(struct elemento *cima);
//Necesita la pila para saber si esta vacia
//Solo usa un asterisco porque no cambia nada, solo es apuntador
//Devuelve un entero como booleano [si o no puedo esta vacia]
int primero(struct elemento *cima);
////Devuelve un entero [valor del dato que existe]

int main() {
    struct elemento *pilaA = NULL;//Inicializamos en vacio
    struct elemento *pilaB = NULL;
    struct elemento *CimaC = NULL;

    insertar(&pilaA, 7);
    insertar(&pilaA, 6);
    insertar(&pilaA, 3);
    //Se manda con & por el doble apuntador
    insertar(&CimaC, 7);
    insertar(&CimaC, 6);
    insertar(&CimaC, 3);

    //while (pilaA != NULL)
    //while (estaVacia(pilaA) == 0){
    while (!estaVacia(pilaA)) {
        printf("%d", eliminar(&pilaA));
    }
    return 0;
}

int insertar(struct elemento **cima, int datoNuevo){

    struct elemento *nuevo;//Nuevo tipo de dato

    nuevo = (struct elemento *)malloc(sizeof (struct elemento));
    //Validamos que nos den la memoria o que esté disponible
    if (*cima==NULL){
        return 0;
        //Si no podemos insertar, terminamos la funcion y regresamos un cero
    }

    nuevo->dato = datoNuevo;
    //Cuando esta vacia apunta a el primer dato registrado en su campo dato
    nuevo->sig = *cima;//NULL;
    *cima = nuevo;
    //No se elimina la memoria hasta que no necesitemos la informacion más
    //Observacion
    /*if (*cima == NULL){//se valida si la cima esta vacia
        nuevo->sig = *cima;//NULL;
        *cima = nuevo ;//Esto es lo mismo que lo de abajo
    }else{
        nuevo->sig = *cima;
        *cima = nuevo ;//Esto es lo mismo que lo de arriba
    }*/
    return 1; //Si se puedo insertar, entonces regresas un entero
    //del tipo de dato que utilizas
}

int eliminar(struct elemento **cima){
    //Se llama la funcion estaVacia para saber si podemos eliminar o no
    if (estaVacia(*cima)==1){
        return -100000;//Regresa un valor que no puede estar ahi, ya que no puede eliminar
    }
    //Aquí no se pide memoria porque esos datos se deben perder
    struct elemento *eliminado;
    eliminado = *cima;//Respaldo del nodo o toda la info
    int datoE = eliminado->dato;//*cima->dato;//Info del dato a eliminar

    //Cima es igual a eliminado->sig porque asi ya no tendra la estructura
    //donde tiene el dato a eliminar
    *cima = eliminado->sig;
    //*cima->sig = *cima;
    free(eliminado);

    return datoE;
}

int estaVacia(struct elemento *cima){
    if (cima==NULL){
        return 1;//Si esta vacio regresamos un 1
    }//min 46:16
    return 0;//Si no esta vacia regresa un 0
}

int primero(struct elemento *cima){
    if (estaVacia(cima)==1){
        return -100000;//Valor que no está en la pila
    }
    return cima->dato;
}