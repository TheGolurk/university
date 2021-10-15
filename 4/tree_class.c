/*
Recorridos
-Profundidad: Solo recorre en derecha o izquierda
	-Pre orden
		-visitar raiz
		- recorrer en preorden sub arbol izquierdo
		- recorrer en preorden sub arbol derecho 
	-In orden
		- recorrer en in orden sub arbol izquierdo
		- visitar raiz
		- recorrer en in orden sub arbol derecho
	-Post Orden
		-recorrer en post orden sub arbol izq
		-recorrer en post orden sub arbol der
		-visitar raiz
-Amplitud: 
*/

// REPOR: https://github.com/TheGolurk/university/tree/master/4 

#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int dato;
	struct Nodo *izq;
	struct Nodo *der;
};

struct elemento {
	struct Nodo *dato;
	struct elemento *sig;
};

int insertar(int nuevoDato, struct Nodo **raiz);
void inOrden(struct Nodo *raiz);
void preOrden(struct Nodo *raiz);
void postOrden(struct Nodo *raiz);
void recAmplitud(struct Nodo *raiz);
int eliminar(struct Nodo **raiz, int datoEliminado);


int main() {
	struct Nodo *raiz = NULL;
	insertar(5, &raiz);
	insertar(15, &raiz);
	insertar(9, &raiz);
	insertar(10, &raiz);
	insertar(3, &raiz);
	insertar(1, &raiz);
	insertar(4, &raiz);
	insertar(11, &raiz);
	insertar(19, &raiz);

	inOrden(raiz);

	recAmplitud(raiz);

	eliminar(&raiz, 1);
	inOrden(raiz);

	return 0;
}

int insertar(int nuevoDato, struct Nodo **raiz) {
	if (*raiz == NULL) {
		struct Nodo *nuevo;
		nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
		
		if (nuevo == NULL) {
			return 0;
		}

		nuevo->dato = nuevoDato;
		nuevo->izq = NULL;
		nuevo->der = NULL;

		*raiz = nuevo;

		return 1;
	}

	// No permitiendo repetidos (alternativa recursiva)
	if (nuevoDato < (*raiz)->dato)
	{
		return insertar(nuevoDato, &((*raiz)->izq));
	} else {
		// quitamos el if si quieremos repetidos
		if (nuevoDato > (*raiz)->dato)
		{
			return insertar(nuevoDato,  &((*raiz)->der));
		} else {
			return 0;
		}
		
	}
	
}

int eliminar(struct Nodo **raiz, int datoEliminado) {
	if (*raiz == NULL)
	{
		return -1;
	}

	if (datoEliminado < (*raiz)->dato)
	{
		return eliminar( &((*raiz))->izq , datoEliminado);
	} else {
		
		if (datoEliminado > (*raiz)->dato)
		{
			return eliminar( &((*raiz))->der , datoEliminado);
		} else {

			// Dato enctronado
			struct Nodo *eliminado;
			int datoEliminado;
			eliminado = *raiz;
			datoEliminado = eliminado->dato;
			if (eliminado->izq == NULL && eliminado->der == NULL)
			{
				*raiz = NULL;
			} else {

				if (eliminado->der == NULL) // hijo izquierdo
				{
					*raiz = eliminado->izq;
				} else {
					
					if (eliminado->izq == NULL) //hijo derecho
					{
						*raiz = eliminado->der;
					} else {

						struct Nodo *auxHijo = eliminado->der, *auxPadre = eliminado;
						while (auxHijo->izq != NULL)
						{
							auxPadre = auxHijo;
							auxHijo = auxHijo->izq;	
						}

						auxPadre->izq = auxHijo->der;
						auxHijo->izq = eliminado->izq;
						auxHijo->der = eliminado->der;
						*raiz = auxHijo;

					}
					
				}
				
			}
			

			free(eliminado);
			return datoEliminado;
		}
		

	}
	
	
}

void inOrden(struct Nodo *raiz) {
	if (raiz == NULL) {
		return;
	}

	inOrden(raiz->izq);
	printf("%d, ", raiz->dato);
	inOrden(raiz->der);
}

void preOrden(struct Nodo *raiz) {
	if (raiz == NULL) {
		return;
	}

	printf("%d, ", raiz->dato);
	preOrden(raiz->izq);
	preOrden(raiz->der);
}

void postOrden(struct Nodo *raiz) {
	if (raiz == NULL) {
		return;
	}

	postOrden(raiz->izq);
	postOrden(raiz->der);
	printf("%d, ", raiz->dato);
}

int insertarCola(struct elemento **inicio, struct elemento **fin, struct Nodo *datoNuevo) {
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

struct Nodo * eliminarCola(struct elemento **inicio, struct elemento **fin) {
    struct Nodo *datoEliminado = NULL; 
    if (*inicio == NULL){
        return datoEliminado;
    }

    struct elemento*eliminado = *inicio;
    datoEliminado = eliminado->dato;

    *inicio = eliminado->sig;
    if (*inicio == NULL){
        *fin = NULL;
    }

    free(eliminado);

    return datoEliminado;
}

int estaVacia(struct elemento *inicio) {
	if (inicio == NULL)
	{
		return 1;
	}
	
	return 0;
}

struct Nodo * primero(struct elemento *inicio) {
	struct Nodo *info = NULL;
	if (estaVacia(inicio) == 1)
	{
		return info;
	}
	
	return inicio->dato;
}

void recAmplitud(struct Nodo *raiz) {
	struct elemento *inicio=NULL, *fin=NULL;

	insertarCola(&inicio, &fin, raiz);

	struct Nodo *aux;

	while(!estaVacia(inicio)) {
		aux = eliminarCola(&inicio, &fin);
		printf("%d \n", aux->dato);
		
		if (aux->izq != NULL)
		{
			insertarCola(&inicio, &fin, aux->izq);
		}
		if (aux->der!= NULL)
		{
			insertarCola(&inicio, &fin, aux->der);
		}
	}


	printf("\n");
}