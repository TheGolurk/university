#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto {
    int ID;
    char descripcion[100];
    float precio;
    float precio_provedor;
    char marca[30];
    int piezas_disponibles;
    struct Producto *izq;
    struct Producto *der;
};

struct elemento {
	struct Producto *dato;
	struct elemento *sig;
};

int insertar(struct Producto nuevoDato, struct Producto **raiz);

int main(int argc, char const *argv[])
{

    // [x] insertar
    // [] mostrar
    // [] vaciar
    // [] nivel de un producto en particular
    // [] menu

    int o = 1;

    while (o != 5) {

        printf("1 agregar\n 2 mostrar \n 3 vaciar \n 4 buscar y mostrar nivel \n 5 salir"); 
        scanf("%d", &o);

        if (o == 1)
        {

        } else if (o == 2) {

        } else if (o == 3) {

        } else if (o == 4) {

        }      

    }

    return 0;
}

int insertar(struct Producto nuevoDato, struct Producto **raiz) {
	if (*raiz == NULL) {
		struct Producto *nuevo;
		nuevo = (struct Producto*)malloc(sizeof(struct Producto));

		if (nuevo == NULL) {
			return 0;
		}

		nuevo->ID = nuevoDato.ID; 
        strcpy(nuevo->descripcion, nuevoDato.descripcion);
        nuevo->precio = nuevoDato.precio;
        nuevo->precio_provedor = nuevoDato.precio_provedor;
        strcpy(nuevo->marca, nuevoDato.marca);
        nuevo->piezas_disponibles = nuevoDato.piezas_disponibles;
		nuevo->izq = NULL;
		nuevo->der = NULL;

		*raiz = nuevo;

		return 1;
	}

    // izquierda menor
	if (nuevoDato.ID < (*raiz)->ID)
	{
		return insertar(nuevoDato, &((*raiz)->izq));
	} else {
		// quitamos el if si quieremos repetidos
		if (nuevoDato.ID > (*raiz)->ID)
		{
			return insertar(nuevoDato,  &((*raiz)->der));
		} else {
			return 0;
		}
		
	}
	
}