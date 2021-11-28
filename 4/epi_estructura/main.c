/*
AUTORES: 
HERNÁNDEZ NÁJERA CHRISTIAN
VALLE GONZÁLEZ LORENA
EPI_EVIDENCIA DE PRODUCTO INTEGRADORA
26-NOVIEMBRE-2021
*/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct contacto{
    char aPaterno[15];
    char aMaterno[15];
    char nombre[15];
    struct tm fechaNacimiento;
    int edad;
    char ciudad[20];
    char puesto[15];
    char empresa[20];
    long numero;
    struct nodoLista *nodoLista;
};

struct Nodo {
    struct contacto contactos;
    struct Nodo *izq;
    struct Nodo *der;
};

struct datostelefono{
    long telefonoFijo;
    long telefonoTrabajo;
    long telefonoCasa;
    long telefonoPersonal;
    char direccion[30];
    char nombreFamiliar[30];
};

struct nodoLista {
    struct datostelefono d;
    struct nodoLista *sig;    
};

int insertar(struct contacto c, struct Nodo **raiz);
int insertarNumero(char nombre[], struct datostelefono datostelefono, struct Nodo **raiz);
int eliminarContacto(char nombre[], struct Nodo **raiz);
int eliminarNumeroDeContacto(char nombre[], long numero, struct Nodo **raiz);
int eliminarNumeroDesconocido(long numero, struct Nodo **raiz);

void consultarContactos(struct Nodo *raiz);
void consultarContactosCiudad(struct Nodo *raiz);
void consularContactoPorTelefono(struct Nodo *raiz);
void consultarTodo(struct Nodo **raiz);

int modificarContacto(struct contacto contacto, struct datostelefono datostelefono ,struct Nodo **raiz);

struct contacto leerDatos();
struct datostelefono leerDatosTelefono();

int validarInsertar(char aPaterno[15], char aMaretno[15], char nombre[15], 
                    char aPaternoRaiz[15], char aMaretnoRaiz[15], char nombreRaiz[15]);

int main()
{
    int opcion;
    printf("1.-Agregar contacto\n  2.-Agregar telefono\n 3.-Eliminar contacto\n 4.-  \n  5.-\n ");
     printf("6.-   7.-   8.-   9.-  10.-");
    while (opcion !=10)

    {
        switch(opcion)
        {

            case 1:
                break;
                
            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                break;

            case 10:
                break;

            default:
                break;


        }
    }
    


    return 0;

}

// -1 Para menor
// 1 Para mayor
// 0 ninguno
int validarInsertar(char aPaterno[15], char aMaterno[15], char nombre[15], 
                    char aPaternoRaiz[15], char aMaternoRaiz[15], char nombreRaiz[15])
{
    if ( strcmp(nombre, nombreRaiz) < 0 && strcmp(aPaterno, aPaternoRaiz) < 0 && strcmp(aMaterno, aMaternoRaiz) < 0  )
    {
        return -1;
    } else if ( strcmp(nombre, nombreRaiz) > 0 && strcmp(aPaterno, aPaternoRaiz) > 0 && strcmp(aMaterno, aMaternoRaiz) > 0  )
    {
        return 1;
    }
    
    return 0;
}

int insertar(struct contacto c, struct Nodo **raiz) {
	if (*raiz == NULL) {
		struct Nodo *nuevo;
		nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
		
		if (nuevo == NULL) {
			return 0;
		}

        // meterlo los datos
        // nuevo->dato = nuevoDato;
		nuevo->izq = NULL;
		nuevo->der = NULL;

		*raiz = nuevo;

		return 1;
	}

    int insertarValidado = validarInsertar(c.aPaterno, c.aMaterno, c.nombre, 
                (*raiz)->contactos.aPaterno, (*raiz)->contactos.aMaterno, (*raiz)->contactos.nombre);

	if (insertarValidado == -1)
	{
		return insertar(c, &((*raiz)->izq));
	} else {
		if (insertarValidado == 1)
		{
			return insertar(c,  &((*raiz)->der));
		} else {
			return 0;
		}
	}
}