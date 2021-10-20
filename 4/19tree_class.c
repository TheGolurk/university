#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
    char dato[30];
	struct Nodo *izq;
	struct Nodo *der;
};

struct elemento {
	struct Nodo *dato;
	struct elemento *sig;
};

int insertar(char nuevoDato[], struct Nodo **raiz);
char * eliminar(struct Nodo **raiz, char  datoE[]);
void inOrden(struct Nodo *raiz);
void preOrden(struct Nodo *raiz);
void postOrden(struct Nodo *raiz);
void recAmplitud(struct Nodo *raiz);
int buscar(struct Nodo *raiz, char datoB[]);


int main() {
	struct Nodo *raiz = NULL;
	insertar("morado", &raiz);
	insertar("azul", &raiz);
	insertar("amarillo", &raiz);
	insertar("blanco", &raiz);
	insertar("verde", &raiz);
	insertar("negro", &raiz);
	insertar("violeta", &raiz);
	insertar("rojo", &raiz);
	insertar("gris", &raiz);

	inOrden(raiz);
	//recAmplitud(raiz);

/*
	printf("\n");
	eliminar(&raiz, 1);
	inOrden(raiz);
	recAmplitud(raiz);

	printf("\n");
	eliminar(&raiz, 10);
	inOrden(raiz);
	recAmplitud(raiz);
*/

	printf("\n");
	eliminar(&raiz, "verde");
	inOrden(raiz);
	recAmplitud(raiz);

	return 0;
}

int insertar(char nuevoDato[], struct Nodo **raiz) {
	if (*raiz == NULL) {
		struct Nodo *nuevo;
		nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
		
		if (nuevo == NULL) {
			return 0;
		}

		strcpy(nuevo->dato, nuevoDato);
		nuevo->izq = NULL;
		nuevo->der = NULL;

		*raiz = nuevo;

		return 1;
	}

	// No permitiendo repetidos (alternativa recursiva)
	if (strcmp(nuevoDato, (*raiz)->dato) < 0)
	{
		return insertar(nuevoDato, &((*raiz)->izq));
	} else {
		// quitamos el if si quieremos repetidos
		if (strcmp(nuevoDato, (*raiz)->dato) > 0)
		{
			return insertar(nuevoDato,  &((*raiz)->der));
		} else {
			return 0;
		}
		
	}
	
}

char * eliminar(struct Nodo **raiz, char  datoE[]){
	if(*raiz==NULL){
		return NULL;
	}
	
	if(strcmp(datoE, (*raiz)->dato)<0){
		return  eliminar(&((*raiz)->izq), datoE);
	}else{
		if(strcmp(datoE, (*raiz)->dato)>0){
			return  eliminar(&((*raiz)->der), datoE);
		}else{
			struct Nodo *eliminado;
			char*  datoEliminado;//="";
			datoEliminado=(char*)malloc(50);
			eliminado=*raiz;
			strcpy(datoEliminado,eliminado->dato);
			if(eliminado->izq==NULL &&  eliminado->der==NULL){
				*raiz=NULL;
			
			}else{
				if( eliminado->der==NULL){ //Tiene un sólo hijo el izquierdo
					*raiz=eliminado->izq;
				}else{
					if( eliminado->izq==NULL){ //Tiene un sólo hijo, el derecho
					*raiz=eliminado->der;
					}else{
						struct  Nodo *auxHijo=eliminado->der, *auxPadre=eliminado;
						while(auxHijo->izq!=NULL){
							auxPadre=auxHijo;
							auxHijo=auxHijo->izq;
						}
						auxPadre->izq=auxHijo->der;
						auxHijo->izq=eliminado->izq;
						auxHijo->der=eliminado->der;
						*raiz=auxHijo;
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
	printf("%s, ", raiz->dato);
	inOrden(raiz->der);
}

void preOrden(struct Nodo *raiz) {
	if (raiz == NULL) {
		return;
	}

	printf("%s, ", raiz->dato);
	preOrden(raiz->izq);
	preOrden(raiz->der);
}

void postOrden(struct Nodo *raiz) {
	if (raiz == NULL) {
		return;
	}

	postOrden(raiz->izq);
	postOrden(raiz->der);
	printf("%s, ", raiz->dato);
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
		printf("%s ", aux->dato);
		
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

int buscar(struct Nodo *raiz, char datoB[]) {
    if(raiz  == NULL) {
        return 0;
    }

    if (strcmp(datoB, raiz->dato) == 0) {
        return 1;
    }
    
    if(strcmp(datoB, raiz->dato) < 0) {
        return buscar(raiz->izq, datoB);
    } else {
        return buscar(raiz->der, datoB);
    }
}