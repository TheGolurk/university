#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int dato;
	struct Nodo *izq;
	struct Nodo *der;
};

int insertar(int nuevoDato, struct Nodo **raiz);

int main() {
	struct Nodo *raiz = NULL;
	insertar(5, &raiz);
	insertar(15, &raiz);
	insertar(9, &raiz);
	insertar(10, &raiz);
	insertar(3, &raiz);

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
		if (nuevoDato > (*raiz)->dato)
		{
			return insertar(nuevoDato,  &((*raiz)->der));
		} else {
			return 0;
		}
		
	}
	

}
