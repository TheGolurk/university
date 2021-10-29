/******
ÁRBOLES BINARIOS
HERNÁNDEZ NAJÉRA CHRISTIAN  HNCO200217 
4°C  ED2 
29/oct/2021 
*******/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto {
    int clave;
    char descripcion[100];
    float precio;
    float redondeo;
    char notas[100];
    int preciosugerido;
    struct Producto *izq;
    struct Producto *der;
};

struct elemento {
	struct Producto *dato;
	struct elemento *sig;
};

int insertar(struct Producto nuevoDato, struct Producto **raiz);
void inOrden(struct Producto *raiz);
struct Producto leer();

int main(int argc, char const *argv[])
{

    int opc = 1;
    struct Producto *raiz = NULL;

    do
    {

        printf("1-añadir\n 2-listar \n 3-vaciat todo el arbol \n 4-buscar \n 5-acabar"); 
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:

            insertar(leer(), &raiz);
            break;
        
        case 2:

            inOrden(raiz);

            break;
          
        }

    } while (opc != 5);
    

    return 0;
}

struct Producto leer() {
    struct Producto nuevoDato; 
            
    printf("ingrese la clave \n");
    scanf("%d", &nuevoDato.clave);
            
    printf("Ingrese la descripcion del producto:\n");
    scanf("%s",&nuevoDato.descripcion);

    printf("Ingrese precio\n");
    scanf("%f",&nuevoDato.precio);

    printf("Ingrese precio sugerido\n");
    scanf("%d",&nuevoDato.preciosugerido);

    printf("Ingrese notas:\n") ;
    scanf("%s",&nuevoDato.notas);
            
    printf("Ingrese redondeo:\n");
    scanf("%f",&nuevoDato.redondeo);

    return nuevoDato;
}

int insertar(struct Producto nuevoDato, struct Producto **raiz) {
	if (*raiz == NULL) {
		struct Producto *nuevo;
		nuevo = (struct Producto*)malloc(sizeof(struct Producto));

		if (nuevo == NULL) {
			return 0;
		}

        
		nuevo->clave = nuevoDato.clave; 
        nuevo->precio = nuevoDato.precio;
        nuevo->preciosugerido = nuevoDato.preciosugerido;
        nuevo->redondeo = nuevoDato.redondeo;

        strcpy(nuevo->notas, nuevoDato.notas);
        strcpy(nuevo->descripcion, nuevoDato.descripcion);

		nuevo->izq = NULL;
		nuevo->der = NULL;

		*raiz = nuevo;

		return 1;
	}

	if (nuevoDato.clave < (*raiz)->clave)
	{
		return insertar(nuevoDato, &((*raiz)->izq));
	} else {
		if (nuevoDato.clave > (*raiz)->clave)
		{
			return insertar(nuevoDato,  &((*raiz)->der));
		} else {
			return 0;
		}
		
	}
	
}

void inOrden(struct Producto *raiz) {
    if (raiz == NULL) {
		return;
	}

	inOrden(raiz->izq);
	printf("%d %s %f %f %s %d \n", raiz->clave,raiz->descripcion,raiz->precio,raiz->redondeo,raiz->notas,raiz->preciosugerido);
	inOrden(raiz->der);
}