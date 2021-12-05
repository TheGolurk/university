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
int insertarNumero(char* aPaterno, char* aMaterno, char* nombre, struct datostelefono datostelefono, struct Nodo **raiz);
int eliminarContacto(char* aPaterno, char* aMaterno, char* nombre, struct Nodo **raiz);
int eliminarNumeroDeContacto(struct contacto nombres, long numero, struct Nodo **raiz, struct Nodo *raizB);
int eliminarNumeroDesconocido(long numero, struct Nodo **raiz);
int eliminarNumero(long numero, struct nodoLista** raiz);
int buscarTelefonos(struct datostelefono d, struct nodoLista *datos);

void consultarContactos(struct Nodo *raiz);
void consultarContactosCiudad(struct Nodo *raiz);
void consularContactoPorTelefono(struct Nodo *raiz);
void consultarTodo(struct Nodo **raiz);
void inOrden(struct Nodo *raiz);
void inOrderNombres(char* nombre, struct Nodo *raiz);
void inOrderNombresV2(char* nombre, struct Nodo *raiz);
void inOrderNombresV3(struct datostelefono d,struct Nodo *raiz);
void imprimirListaContactos(struct nodoLista *datos);



int modificarContacto(struct contacto contacto, struct datostelefono datostelefono ,struct Nodo **raiz);

struct contacto leerDatos();
struct datostelefono leerDatosTelefono();
struct contacto leerNombresCompletos(); 
long leerNumero();

int validarTexto(char aPaterno[15], char aMaretno[15], char nombre[15], 
                    char aPaternoRaiz[15], char aMaretnoRaiz[15], char nombreRaiz[15]);

int main()
{
    struct Nodo *raiz = NULL;

    int opcion;
    printf("1.-Agregar contacto\n  2.-Agregar telefono\n 3.-Eliminar contacto por nombre\n");
    printf("4.-Eliminar telefono de contacto\n  5.-Eliminar telefono\n 6.-Consultar telefonos de contacto\n");
    printf("7.-Consultar por nombres\n 8.-Consultar contacto por telefono\n 9.-Modificar contacto\n ");
    printf("10.-Mostrar contactos\n 11.-Salir\n");
    while (opcion !=11)
    {
        switch(opcion)
        {

            case 1:
                int insertado = insertar( leerDatos(), &raiz );
                if (insertado == 1) {
                    printf("Contacto insertado\n");
                }
                
                break;
                
            case 2:

                struct contacto nombres = leerNombresCompletos();

                int insertado = insertarNumero(nombres.aPaterno, nombres.aMaterno, nombres.nombre, leerDatosTelefono(), &raiz);
                if (insertado == 1) {
                    printf("numero insertado\n");
                }

                break;

            case 3:
                struct contacto nombres =leerNombresCompletos();
                int eliminado = eliminarContacto(nombres.aPaterno, nombres.aMaterno, nombres.nombre,&raiz);
                if (eliminado == 1) {
                    printf("contacto eliminado\n");
                }
                break;

            case 4:
                struct contacto nombres =leerNombresCompletos();
                int eliminado = eliminarNumeroDeContacto(nombres, leerNumero() ,&raiz, raiz);
                if (eliminado == 1)
                {
                    printf("telefono eliminado\n");
                }else{
                    printf("telefono no encontrado\n");
                }
                
                break;

            case 5:
                break;

            case 6:
                struct contacto nombres =leerNombresCompletos();
                inOrderNombresV2(nombres.nombre, raiz);
                break;

            case 7:
                struct contacto nombres =leerNombresCompletos();
                inOrderNombres(nombres.nombre, raiz);
                
                break;

            case 8:
                struct datostelefono telefonos =leerDatosTelefono();
                inOrderNombresV3(telefonos, raiz);
                break;

            case 9:
                break;

            case 10:
                inOrden(raiz);

                break;
            
            case 11:
                printf("Saliendo.... \n");
                break;

            default:
                printf("opcion incorrecta \n");
        }
    }
    
    return 0;
}

// 2 texto igual
// 1 Para mayor
// -1 Para menor
// 0 ninguno
int validarTexto(char aPaterno[15], char aMaterno[15], char nombre[15], 
                    char aPaternoRaiz[15], char aMaternoRaiz[15], char nombreRaiz[15])
{
    if ( strcmp(nombre, nombreRaiz) < 0 && strcmp(aPaterno, aPaternoRaiz) < 0 && strcmp(aMaterno, aMaternoRaiz) < 0  )
    {
        return -1;
    } else if ( strcmp(nombre, nombreRaiz) > 0 && strcmp(aPaterno, aPaternoRaiz) > 0 && strcmp(aMaterno, aMaternoRaiz) > 0  )
    {
        return 1;
    } else if (strcmp(nombre,nombreRaiz) == 0 && strcmp(aPaterno,aPaternoRaiz) == 0 && strcmp(aMaterno,aMaternoRaiz) == 0)
    { 
        return 2;
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

    int insertarValidado = validarTexto(c.aPaterno, c.aMaterno, c.nombre, 
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


int insertarNumero(char* aPaterno, char* aMaterno, char* nombre, struct datostelefono datostelefono, struct Nodo **raiz) {
    if(raiz  == NULL) {
        return 0;
    }
    int insertarValidado =validarTexto(aPaterno, aMaterno, nombre,
                (*raiz)->contactos.aPaterno,(*raiz)->contactos.aMaterno, (*raiz)->contactos.nombre);

    if (insertarValidado == 2)
    {
        (*raiz)->contactos.nodoLista = (struct nodoLista*)malloc(sizeof(struct nodoLista));
        (*raiz)->contactos.nodoLista->d = datostelefono;
        (*raiz)->contactos.nodoLista->sig =  NULL;

        return 1;
    }

    if(insertarValidado == -1) {
        return buscar(aPaterno, aMaterno, nombre, &((*raiz))->izq);
    } else {
        return buscar(aPaterno, aMaterno, nombre, &((*raiz))->der);
    }
    
    return 0;
}

int eliminarContacto(char* aPaterno, char* aMaterno, char* nombre, struct Nodo **raiz) {
	if (*raiz == NULL)
	{
		return -1;
	}
    
    int eliminarValidado = validarTexto(
                aPaterno, 
                aMaterno, 
                nombre, 
                (*raiz)->contactos.aPaterno, 
                (*raiz)->contactos.aMaterno, 
                (*raiz)->contactos.nombre);
    
    if (eliminarValidado == 0)
    {
        return -1;
    }
    
	if ( eliminarValidado == -1  )
	{
		return eliminar(aPaterno, aMaterno, nombre, &((*raiz))->izq);
	} else {
		
		if (eliminarValidado == 1)
		{
			return eliminar( aPaterno, aMaterno, nombre, &((*raiz))->der);
		} else {
            
			struct Nodo *eliminado;
			eliminado = *raiz;
			if (eliminado->izq == NULL && eliminado->der == NULL)
			{
				*raiz = NULL;
			} else {

				if (eliminado->der == NULL) 
				{
					*raiz = eliminado->izq;
				} else {
					
					if (eliminado->izq == NULL) 
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
			return 0;
		}
		
	}
	
    return 0;
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

    return d;
}

void inOrderNombres(char* nombre, struct Nodo *raiz) {
    if (raiz == NULL) {
		return;
	}

	inOrden(raiz->izq);
    if ( strcmp(nombre, raiz->contactos.nombre) == 0 )
    {
        printf("%s, %s, %s ", raiz->contactos.nombre, raiz->contactos.aPaterno, raiz->contactos.aMaterno);
        printf("%d ", raiz->contactos.edad);
        printf("%d", raiz->contactos.fechaNacimiento);
        printf("%s", raiz->contactos.ciudad);
        printf("%s", raiz->contactos.puesto);
        printf("%s", raiz->contactos.empresa);
        imprimirListaContactos(raiz->contactos.nodoLista);
    }
	inOrden(raiz->der);
}

void inOrderNombresV2(char* nombre, struct Nodo *raiz) {
    if (raiz == NULL) {
		return;
	}

	inOrden(raiz->izq);
    if ( strcmp(nombre, raiz->contactos.nombre) == 0 )
    {
        printf("%s, %s, %s ", raiz->contactos.nombre, raiz->contactos.aPaterno, raiz->contactos.aMaterno);
        printf("%d ", raiz->contactos.edad);
        printf("%d", raiz->contactos.fechaNacimiento);
        printf("%s", raiz->contactos.ciudad);
        printf("%s", raiz->contactos.puesto);
        printf("%s", raiz->contactos.empresa);
        imprimirListaContactos(raiz->contactos.nodoLista);
        return;
    }
	inOrden(raiz->der);
}

void inOrderNombresV3(struct datostelefono d,struct Nodo *raiz) {
    if (raiz == NULL) {
		return;
	}

	inOrden(raiz->izq);
    if ( buscarTelefonos(d, raiz->contactos.nodoLista) == 0 )
    {
        printf("%s, %s, %s ", raiz->contactos.nombre, raiz->contactos.aPaterno, raiz->contactos.aMaterno);
        printf("%d ", raiz->contactos.edad);
        printf("%d", raiz->contactos.fechaNacimiento);
        printf("%s", raiz->contactos.ciudad);
        printf("%s", raiz->contactos.puesto);
        printf("%s", raiz->contactos.empresa);
        imprimirListaContactos(raiz->contactos.nodoLista);
        return;
    }
	inOrden(raiz->der);
}

int buscarTelefonos(struct datostelefono d, struct nodoLista *datos) {
     while(datos != NULL) {        
        
        if ( d.telefonoPersonal == datos->d.telefonoPersonal &&
             d.telefonoCasa == datos->d.telefonoCasa && 
             d.telefonoTrabajo == datos->d.telefonoTrabajo && 
             d.telefonoFijo == datos->d.telefonoFijo)
        {
            return 0;
        }

        datos = datos->sig; 
    }

    return 1;
}


void inOrden(struct Nodo *raiz) {
	if (raiz == NULL) {
		return;
	}

	inOrden(raiz->izq);
    
	printf("%s, %s, %s ", raiz->contactos.nombre, raiz->contactos.aPaterno, raiz->contactos.aMaterno);
    printf("%d ", raiz->contactos.edad);
    printf("%d", raiz->contactos.fechaNacimiento);
    printf("%s", raiz->contactos.ciudad);
    printf("%s", raiz->contactos.puesto);
    printf("%s", raiz->contactos.empresa);
    imprimirListaContactos(raiz->contactos.nodoLista);
    

	inOrden(raiz->der);
}

void imprimirListaContactos(struct nodoLista *datos) {
    while(datos != NULL) {        
        printf("%s %s ,", datos->d.direccion, datos->d.nombreFamiliar);
        printf("%ld %ld ,", datos->d.telefonoFijo, datos->d.telefonoCasa);
        printf("%ld %ld ,", datos->d.telefonoPersonal, datos->d.telefonoTrabajo);

        datos = datos->sig; 
    }
}

struct contacto leerNombresCompletos() {
    struct contacto c;
    
    printf("ingresar nombre:\n");
    scanf("%s", c.nombre);
    printf("ingresar  primer apellido:\n");
    scanf("%s", c.aPaterno);
    printf("ingresar  segundo apellido:\n");
    scanf("%s", c.aMaterno);

    return c;
}

int eliminarNumero(long numero, struct nodoLista** raiz)
{
    struct nodoLista *temp = *raiz, *prev;
 
    if (temp != NULL && temp->d.telefonoPersonal == numero) {
        *raiz = temp->sig; 
        free(temp); 
        return 1;
    }
 

    while (temp != NULL && temp->d.telefonoPersonal != numero) {
        prev = temp;
        temp = temp->sig;
    }
 
    if (temp == NULL)
        return 0;

    prev->sig = temp->sig;

    free(temp);

    return 1;
}

int eliminarNumeroDeContacto(struct contacto nombres, long numero, struct Nodo **raiz, struct Nodo *raizB) {
	if (raizB == NULL) {
		return;
	}

	eliminarNumeroDeContacto(nombres, numero, raiz, raizB->izq);

    
    if ( validarTexto(
        nombres.aPaterno, 
        nombres.aPaterno, 
        nombres.nombre,
        raizB->contactos.aPaterno,
        raizB->contactos.aMaterno, 
        raizB->contactos.nombre) == 0 )
    {
        int eliminado = eliminarNumero(numero, (*raiz)->contactos.nodoLista); 
        if (eliminado == 1) {
            return 1;   
        } else {
            return 0;
        }
    
    }

	eliminarNumeroDeContacto(nombres, numero, raiz, raizB->der);
}

long leerNumero() {
    long num = 0;

    printf("ingresa numero personal \n");
    scanf("%ld", &num);
    
    return num;
}