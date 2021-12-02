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
void inOrden(struct Nodo *raiz);


int modificarContacto(struct contacto contacto, struct datostelefono datostelefono ,struct Nodo **raiz);

struct contacto leerDatos();
struct datostelefono leerDatosTelefono();


int validarInsertar(char aPaterno[15], char aMaretno[15], char nombre[15], 
                    char aPaternoRaiz[15], char aMaretnoRaiz[15], char nombreRaiz[15]);

int main()
{
    int opcion;
    printf("1.-Agregar contacto\n  2.-Agregar telefono\n 3.-Eliminar contacto por nombre\n");
    printf("4.-Eliminar telefono de contacto\n  5.-Eliminar telefono\n 6.-Consultar telefonos de contacto\n");
    printf("7.-Consultar contacto por telefono\n 8.-Modificar contacto\n 9.-Mostrar contactos\n 10.-Salir\n");
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
                printf("opcion incorrecta \n");
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
 
        strcpy( nuevo->contactos.aPaterno,c.aPaterno) ; 
        stpcpy( nuevo->contactos.aMaterno, c.aMaterno);
        strcpy( nuevo->contactos.nombre, c.nombre);
        nuevo->contactos.edad = c.edad;
        strcpy( nuevo->contactos.ciudad, c.ciudad);
        strcpy( nuevo->contactos.puesto, c.puesto);
        strcpy( nuevo->contactos.empresa, c.empresa);
        strcpy(nuevo->contactos.numero , c.numero);
        nuevo->contactos.fechaNacimiento = c.fechaNacimiento;
        nuevo->contactos.nodoLista->d = leerDatosTelefono();


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

struct contacto leerDatos() {
    struct contacto c;

    printf("ingresar nombre:\n");
    scanf("%s", c.nombre);
    printf("ingresar  primer apellido:\n");
    scanf("%s", c.aPaterno);
    printf("ingresar  segundo apellido:\n");
    scanf("%s", c.aMaterno);

    printf("ingresar fecha de nacimiento (año) :\n");
    scanf("%d", c.fechaNacimiento.tm_year);
    printf("ingresar fecha de nacimiento (mes) :\n");
    scanf("%d", c.fechaNacimiento.tm_mon);
    printf("ingresar fecha de nacimiento (dia) :\n");
    scanf("%d", c.fechaNacimiento.tm_mday);

    printf("ingresar  edad:\n");
    scanf("%d", c.edad);
    printf("ingresar ciudad:\n");
    scanf("%s", c.ciudad);
    printf("ingresar  puesto:\n");
    scanf("%s", c.puesto);
    printf("ingresar  empresa:\n");
    scanf("%s", c.empresa);
    
    
    return c;
}

struct datostelefono leerDatosTelefono() {
    struct datostelefono d;

    printf("ingresar telefono fijo:\n");
    scanf("%ld", d.telefonoFijo);
    printf("ingresar telefono  de casa:\n");
    scanf("%ld", d.telefonoCasa);
    printf("ingresar telefono de trabajo:\n");
    scanf("%ld",d.telefonoTrabajo);
    printf("ingresar telefono personal:\n");
    scanf("%ld", d.telefonoPersonal);
    printf("ingresa direccion\n");
    scanf("%s", d.direccion);
    printf("ingresa nombre de algun familiar\n");
    scanf("%s", d.nombreFamiliar);

    return d;}

void inOrden(struct Nodo *raiz) {
	if (raiz == NULL) {
		return;
	}

	inOrden(raiz->izq);
    
    // asi con todos los datos
	printf("%s, %s, %s ", raiz->contactos.nombre, raiz->contactos.aPaterno, raiz->contactos.aMaterno);
    printf("%d,%s, %s ");

	inOrden(raiz->der);
//me voy a salir , no se si nos llevemos la compu y alal ale seguimos
}
