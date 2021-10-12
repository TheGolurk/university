/*
Recorridos
-Profundidad
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
-Amplitud
*/

#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int dato;
	struct Nodo *izq;
	struct Nodo *der;
};

int insertar(int nuevoDato, struct Nodo **raiz);
void inOrden(struct Nodo *raiz);

int main() {
	struct Nodo *raiz = NULL;
	insertar(5, &raiz);
	insertar(15, &raiz);
	insertar(9, &raiz);
	insertar(10, &raiz);
	insertar(3, &raiz);

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

void inOrden(struct Nodo *raiz) {
	if (raiz == NULL) {
		return;
	}

	inOrden(raiz->izq);
	printf("%d, ", raiz->dato);
	inOrden(raiz->der);
}