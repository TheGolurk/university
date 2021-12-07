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
int eliminarNumeroDeContactoV2(long numero, struct Nodo **raiz, struct Nodo *raizB);
int eliminarNumero(long numero, struct nodoLista **raiz);
int buscarTelefonos(long telefonoV2, struct nodoLista *datos);


void consultarContactos(struct Nodo *raiz);
void consultarContactosCiudad(struct Nodo *raiz);
void consularContactoPorTelefono(struct Nodo *raiz);
void consultarTodo(struct Nodo **raiz);
void inOrden(struct Nodo *raiz);
void inOrderNombres(char* nombre, struct Nodo *raiz);
void inOrderNombresV2(char* nombre, struct Nodo *raiz);
void inOrderNombresV3(long telefonoV2,struct Nodo *raiz);
void imprimirListaContactos(struct nodoLista *datos);

int modificarContacto(struct contacto contacto, struct datostelefono datostelefono ,struct Nodo **raiz);

struct contacto leerDatos();
struct datostelefono leerDatosTelefono();
struct contacto leerNombresCompletos(); 
long leerNumero();
long leerDatostelefonoV2();
const char* leerNombresCompletosV2();
void inicializar(struct Nodo **raiz);
int insertarV2(struct contacto c, struct datostelefono telefonos,struct Nodo **raiz);

void liberarMemoria(struct Nodo **raiz);

int validarTexto(char aPaterno[15], char aMaretno[15], char nombre[15], 
                    char aPaternoRaiz[15], char aMaretnoRaiz[15], char nombreRaiz[15]);

int main()
{
    struct Nodo *raiz = NULL;
    inicializar(&raiz);

    struct contacto nombres;
    struct datostelefono telefonos;
    int insertado = 0;
    int eliminado = 0;
    const char* nombreV2;
    long telefonoV2;

    int opcion = 0;
    while (opcion !=11)
    {
        
        printf("1.-Agregar contacto \n2.-Agregar telefono \n3.-Eliminar contacto por nombre");
        printf("\n4.-Eliminar telefono de contacto \n5.-Eliminar telefono \n6.-Consultar telefonos de contacto");
        printf("\n7.-Consultar por nombres \n8.-Consultar contacto por telefono \n9.-Modificar contacto ");
        printf("\n10.-Mostrar contactos \n11.-Salir\n");
        scanf("%d",&opcion);
        
        switch(opcion)
        {

            case 1:
                insertado = insertar( leerDatos(), &raiz );
                if (insertado == 1) {
                    printf("Contacto insertado\n");
                }
                
                break;
                
            case 2:

                nombres = leerNombresCompletos();

                insertado = insertarNumero(nombres.aPaterno, nombres.aMaterno, nombres.nombre, leerDatosTelefono(), &raiz);
                if (insertado == 1) {
                    printf("numero insertado\n");
                }

                break;

            case 3:
                nombres =leerNombresCompletos();
                eliminado = eliminarContacto(nombres.aPaterno, nombres.aMaterno, nombres.nombre,&raiz);
                if (eliminado == 1) {
                    printf("contacto eliminado\n");
                }
                break;

            case 4:
                nombres =leerNombresCompletos();
                eliminado = eliminarNumeroDeContacto(nombres, leerNumero() ,&raiz, raiz);
                if (eliminado == 1)
                {
                    printf("telefono eliminado\n");
                }else{
                    printf("telefono no encontrado\n");
                }
                
                break;

            case 5:
                eliminado = eliminarNumeroDeContactoV2(leerNumero(), &raiz, raiz);
                if (eliminado == 1)
                {
                    printf("telefono eliminado\n");
                }else{
                    printf("telefono no encontrado\n");
                }

                break;

            case 6:
                nombres =leerNombresCompletos();
                inOrderNombresV2(nombres.nombre, raiz);
                break;

            case 7:
                nombreV2 = leerNombresCompletosV2();
                inOrderNombres(nombreV2, raiz);
                
                break;

            case 8:
                telefonoV2 = leerDatostelefonoV2();;
                inOrderNombresV3(telefonoV2, raiz);
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
                break;
        }
    }

    liberarMemoria(&raiz);
    
    return 0;
}


void inicializar(struct Nodo **raiz) {
    
    struct contacto c;
    struct datostelefono d;

    // 1    
    strcpy(c.nombre, "Carla");
    c.numero = 7771009823;
    strcpy(c.aPaterno, "Aguilar");
    strcpy(c.aMaterno, "Vidal");
    c.fechaNacimiento.tm_year = 2000; 
    c.fechaNacimiento.tm_mon = 9;
    c.fechaNacimiento.tm_mday = 23;
    c.edad = 25;
    strcpy(c.ciudad, "Cuernavaca");
    strcpy(c.puesto, "Cajera");
    strcpy(c.empresa, "Banamex");
    
    strcpy(d.direccion, "REVOLUCION");
    d.telefonoPersonal = 7710930323;
    strcpy(d.nombreFamiliar, "Luis");
    d.telefonoCasa = 7740124721;
    d.telefonoFijo = 7723349432;
    d.telefonoTrabajo = 7733489133;
    
    insertarV2(c,d, raiz);

    strcpy(d.direccion, "TORRES");
    d.telefonoPersonal = 7710930323;
    strcpy(d.nombreFamiliar, "Habacuc");  
    d.telefonoCasa = 7778902444;
    d.telefonoFijo = 7773056789;
    d.telefonoTrabajo = 7733459233;
    insertarNumero(c.aPaterno, c.aMaterno, c.nombre, d, raiz);

    strcpy(d.direccion, "CIVAC");
    d.telefonoPersonal = 7710945323;
    strcpy(d.nombreFamiliar, "JUAN");
    d.telefonoCasa = 7740920021;
    d.telefonoFijo = 7703049432;
    d.telefonoTrabajo = 7733434133;
    insertarNumero(c.aPaterno, c.aMaterno, c.nombre, d, raiz);

    //2
    strcpy(c.nombre, "Lola");
    c.numero = 7773209823;
    strcpy(c.aPaterno, "Perez");
    strcpy(c.aMaterno, "Garcenes");
    c.fechaNacimiento.tm_year = 2000; 
    c.fechaNacimiento.tm_mon = 12;
    c.fechaNacimiento.tm_mday = 12;
    c.edad = 99;
    strcpy(c.ciudad, "Tejalpa");
    strcpy(c.puesto, "Ayudante");
    strcpy(c.empresa, "Pizzeria");
    
    strcpy(d.direccion, "ATLAHUACAN");
    d.telefonoPersonal = 7710930378;
    strcpy(d.nombreFamiliar, "Ortiz");
    d.telefonoCasa = 7740928731;
    d.telefonoFijo = 7723049332;
    d.telefonoTrabajo = 7734554133;
    
    insertarV2(c,d, raiz);

    strcpy(d.direccion, "MARGARITA");
    d.telefonoPersonal = 7710933423;
    strcpy(d.nombreFamiliar, "Olivia");
    d.telefonoCasa = 7737824721;
    d.telefonoFijo = 7723045432;
    d.telefonoTrabajo = 7734454133;
    insertarNumero(c.aPaterno, c.aMaterno, c.nombre, d, raiz);

    strcpy(d.direccion, "TEXCLA");
    d.telefonoPersonal = 7745930323;
    strcpy(d.nombreFamiliar, "PEREZ");
    d.telefonoCasa = 7740924451;
    d.telefonoFijo = 7723049442;
    d.telefonoTrabajo = 7733114133;
    insertarNumero(c.aPaterno, c.aMaterno, c.nombre, d, raiz);

    //3
    strcpy(c.nombre, "Eduardo");
    c.numero = 7771390233;
    strcpy(c.aPaterno, "Reyes");
    strcpy(c.aMaterno, "Juarez");
    c.fechaNacimiento.tm_year = 1999; 
    c.fechaNacimiento.tm_mon = 4;
    c.fechaNacimiento.tm_mday = 2;
    c.edad = 25;
    strcpy(c.ciudad, "Cuautla");
    strcpy(c.puesto, "Plomero");
    strcpy(c.empresa, "Cemex");

    strcpy(d.direccion, "BENITOJUAREZ");
    d.telefonoPersonal = 7710930323;
    strcpy(d.nombreFamiliar, "Kira");
    d.telefonoCasa = 7770924341;
    d.telefonoFijo = 7723040032;
    d.telefonoTrabajo = 7773899133;

    insertarV2(c,d, raiz);

    strcpy(d.direccion, "CAPIRI");
    d.telefonoPersonal = 7710930453;
    strcpy(d.nombreFamiliar, "JAIME");
    d.telefonoCasa = 7740924743;
    d.telefonoFijo = 7723049400;
    d.telefonoTrabajo = 7733455633;
    insertarNumero(c.aPaterno, c.aMaterno, c.nombre, d, raiz);

    strcpy(d.direccion, "CENTRO");
    d.telefonoPersonal = 7710934523;
    strcpy(d.nombreFamiliar, "KAREN");
    d.telefonoCasa = 7740924451;
    d.telefonoFijo = 7728049032;
    d.telefonoTrabajo = 7773564133;
    insertarNumero(c.aPaterno, c.aMaterno, c.nombre, d, raiz);

    //4
    strcpy(c.nombre, "Julio");
    c.numero = 7777789023;
    strcpy(c.aPaterno, "Duarte");
    strcpy(c.aMaterno, "Loises");
    c.fechaNacimiento.tm_year = 1978; 
    c.fechaNacimiento.tm_mon = 11;
    c.fechaNacimiento.tm_mday = 16;
    c.edad = 23;
    strcpy(c.ciudad, "  Jojutla");
    strcpy(c.puesto, "Abogado");
    strcpy(c.empresa, "Vega");
    
    strcpy(d.direccion, "Texcal");
    d.telefonoPersonal = 7710465593;
    strcpy(d.nombreFamiliar, "Yaqueline");
    d.telefonoCasa = 7777828731;
    d.telefonoFijo = 7723090332;
    d.telefonoTrabajo = 7713454133;
    
    insertarV2(c,d, raiz);

    strcpy(d.direccion, "CENTRAL");
    d.telefonoPersonal = 7710343423;
    strcpy(d.nombreFamiliar, "Julian");
    d.telefonoCasa = 7737824371;
    d.telefonoFijo = 7723045882;
    d.telefonoTrabajo = 7734664133;
    insertarNumero(c.aPaterno, c.aMaterno, c.nombre, d, raiz);

    strcpy(d.direccion, "TEJALPA");
    d.telefonoPersonal = 7745930893;
    strcpy(d.nombreFamiliar, "ICON");
    d.telefonoCasa = 7740924433;
    d.telefonoFijo = 7723888442;
    d.telefonoTrabajo = 7733901133;
    insertarNumero(c.aPaterno, c.aMaterno, c.nombre, d, raiz);

    //5
    strcpy(c.nombre, "RIGOR");
    c.numero = 7771390231;
    strcpy(c.aPaterno, "Segura");
    strcpy(c.aMaterno, "Tomia");
    c.fechaNacimiento.tm_year = 1995; 
    c.fechaNacimiento.tm_mon = 14;
    c.fechaNacimiento.tm_mday = 22;
    c.edad = 25;
    strcpy(c.ciudad, "3 MARIAS");
    strcpy(c.puesto, "Pintor");
    strcpy(c.empresa, "Comex");

    strcpy(d.direccion, "SAN ISIDRO");
    d.telefonoPersonal = 7710930013;
    strcpy(d.nombreFamiliar, "Elena");
    d.telefonoCasa = 7770924351;
    d.telefonoFijo = 7723040902;
    d.telefonoTrabajo = 7773319133;

    insertarV2(c,d, raiz);

    strcpy(d.direccion, "REVOLUCION");
    d.telefonoPersonal = 7710930412;
    strcpy(d.nombreFamiliar, "ELSA");
    d.telefonoCasa = 7740924767;
    d.telefonoFijo = 7723049491;
    d.telefonoTrabajo = 7733452333;
    insertarNumero(c.aPaterno, c.aMaterno, c.nombre, d, raiz);

    strcpy(d.direccion, "PROGRESO");
    d.telefonoPersonal = 7710912523;
    strcpy(d.nombreFamiliar, "JULIO");
    d.telefonoCasa = 7740924331;
    d.telefonoFijo = 7724549032;
    d.telefonoTrabajo = 7773454133;
    insertarNumero(c.aPaterno, c.aMaterno, c.nombre, d, raiz);
}

// 2 texto igual
// 1 Para mayor
// -1 Para menor
// 0 ninguno
int validarTexto(char aPaterno[15], char aMaterno[15], char nombre[15], 
                    char aPaternoRaiz[15], char aMaternoRaiz[15], char nombreRaiz[15])
{
    if ( strcmp(nombre, nombreRaiz) < 0 )
    {
        return -1;
    } else if ( strcmp(nombre, nombreRaiz) > 0 )
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
        nuevo->contactos.numero = c.numero;
        nuevo->contactos.fechaNacimiento = c.fechaNacimiento;

        nuevo->contactos.nodoLista = (struct nodoLista*)malloc(sizeof(struct nodoLista));
        if (nuevo->contactos.nodoLista == NULL) {
            return 0;
        }

        struct datostelefono telefonos;
        telefonos = leerDatosTelefono();
        
        strcpy(nuevo->contactos.nodoLista->d.direccion, telefonos.direccion);
        strcpy(nuevo->contactos.nodoLista->d.nombreFamiliar, telefonos.nombreFamiliar);
        nuevo->contactos.nodoLista->d.telefonoCasa = telefonos.telefonoCasa; 
        nuevo->contactos.nodoLista->d.telefonoFijo = telefonos.telefonoFijo;
        nuevo->contactos.nodoLista->d.telefonoPersonal = telefonos.telefonoPersonal;
        nuevo->contactos.nodoLista->d.telefonoTrabajo = telefonos.telefonoTrabajo;

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

int insertarV2(struct contacto c, struct datostelefono telefonos,struct Nodo **raiz) {
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
        nuevo->contactos.numero = c.numero;
        nuevo->contactos.fechaNacimiento = c.fechaNacimiento;

        nuevo->contactos.nodoLista = (struct nodoLista*)malloc(sizeof(struct nodoLista));
        if (nuevo->contactos.nodoLista == NULL) {
            return 0;
        }
        
        strcpy(nuevo->contactos.nodoLista->d.direccion, telefonos.direccion);
        strcpy(nuevo->contactos.nodoLista->d.nombreFamiliar, telefonos.nombreFamiliar);
        nuevo->contactos.nodoLista->d.telefonoCasa = telefonos.telefonoCasa; 
        nuevo->contactos.nodoLista->d.telefonoFijo = telefonos.telefonoFijo;
        nuevo->contactos.nodoLista->d.telefonoPersonal = telefonos.telefonoPersonal;
        nuevo->contactos.nodoLista->d.telefonoTrabajo = telefonos.telefonoTrabajo;

		nuevo->izq = NULL;
		nuevo->der = NULL;

		*raiz = nuevo;

		return 1;
	}

    int insertarValidado = validarTexto(c.aPaterno, c.aMaterno, c.nombre, 
                (*raiz)->contactos.aPaterno, (*raiz)->contactos.aMaterno, (*raiz)->contactos.nombre);

	if (insertarValidado == -1)
	{
		return insertarV2(c, telefonos, &((*raiz)->izq));
	} else {
		if (insertarValidado == 1)
		{
			return insertarV2(c, telefonos,  &((*raiz)->der));
		} else {
			return 0;
		}
	}
}

int insertarNumero(char* aPaterno, char* aMaterno, char* nombre, struct datostelefono datostelefono, struct Nodo **raiz) {
    struct nodoLista *current = (*raiz)->contactos.nodoLista;

    int insertarValidado =validarTexto(aPaterno, aMaterno, nombre,
                (*raiz)->contactos.aPaterno,(*raiz)->contactos.aMaterno, (*raiz)->contactos.nombre);

    if (insertarValidado == 2)
    {
        while (current->sig != NULL) {
            current = current->sig;
        }

        current->sig = (struct nodoLista*)malloc(sizeof(struct nodoLista));
        current->sig->d = datostelefono;
        current->sig->sig =  NULL;

        return 1;
    }

    if(insertarValidado == -1) {
        return insertarNumero(aPaterno, aMaterno, nombre,datostelefono, &((*raiz))->izq);
    } else {
        if(insertarValidado == 1) {
            return insertarNumero(aPaterno, aMaterno, nombre,datostelefono, &((*raiz))->der);
        }
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
		return eliminarContacto(aPaterno, aMaterno, nombre, &((*raiz))->izq);
	} else {
		
		if (eliminarValidado == 1)
		{
			return eliminarContacto( aPaterno, aMaterno, nombre, &((*raiz))->der);
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
    scanf("%d", &c.fechaNacimiento.tm_year);
    printf("ingresar fecha de nacimiento (mes) :\n");
    scanf("%d", &c.fechaNacimiento.tm_mon);
    printf("ingresar fecha de nacimiento (dia) :\n");
    scanf("%d", &c.fechaNacimiento.tm_mday);

    printf("ingresar  edad:\n");
    scanf("%d", &c.edad);
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
    scanf("%ld", &d.telefonoFijo);
    printf("ingresar telefono  de casa:\n");
    scanf("%ld", &d.telefonoCasa);
    printf("ingresar telefono de trabajo:\n");
    scanf("%ld",&d.telefonoTrabajo);
    printf("ingresar telefono personal:\n");
    scanf("%ld", &d.telefonoPersonal);
    printf("ingresa direccion\n");
    scanf("%s", d.direccion);
    printf("ingresa nombre de algun familiar\n");
    scanf("%s", d.nombreFamiliar);

    return d;
}

long leerDatostelefonoV2() {
    long telefonoV2;

    printf("ingresar telefono personal:\n");
    scanf("%ld", &telefonoV2);

    return telefonoV2;
}

void inOrderNombres(char nombre[], struct Nodo *raiz) {
    if (raiz == NULL) {
		return;
	}

	inOrderNombres(nombre, raiz->izq);
    if ( strcmp(nombre, raiz->contactos.nombre) == 0 )
    {
        printf("%s, %s, %s ", raiz->contactos.nombre, raiz->contactos.aPaterno, raiz->contactos.aMaterno);
        printf("%d ", raiz->contactos.edad);
        printf("%d/%d/%d ", raiz->contactos.fechaNacimiento.tm_year, raiz->contactos.fechaNacimiento.tm_mon, raiz->contactos.fechaNacimiento.tm_mday);
        printf("%s ", raiz->contactos.ciudad);
        printf("%s ", raiz->contactos.puesto);
        printf("%s ", raiz->contactos.empresa);
        imprimirListaContactos(raiz->contactos.nodoLista);
        return;
    }
	inOrderNombres(nombre, raiz->der);
}

void inOrderNombresV2(char* nombre, struct Nodo *raiz) {
    if (raiz == NULL) {
		return;
	}

	inOrderNombresV2(nombre, raiz->izq);
    if ( strcmp(nombre, raiz->contactos.nombre) == 0 )
    {
        printf("%s, %s, %s ", raiz->contactos.nombre, raiz->contactos.aPaterno, raiz->contactos.aMaterno);
        printf("%d ", raiz->contactos.edad);
        printf("%d/%d/%d ", raiz->contactos.fechaNacimiento.tm_year, raiz->contactos.fechaNacimiento.tm_mon, raiz->contactos.fechaNacimiento.tm_mday);
        printf("%s ", raiz->contactos.ciudad);
        printf("%s ", raiz->contactos.puesto);
        printf("%s ", raiz->contactos.empresa);
        imprimirListaContactos(raiz->contactos.nodoLista);
        return;
    }
	inOrderNombresV2(nombre, raiz->der);
}

void inOrderNombresV3(long telefonoV2,struct Nodo *raiz) {
    if (raiz == NULL) {
		return;
	}

	inOrderNombresV3(telefonoV2, raiz->izq);
    if ( buscarTelefonos(telefonoV2, raiz->contactos.nodoLista) == 0 )
    {
        printf("%s, %s, %s ", raiz->contactos.nombre, raiz->contactos.aPaterno, raiz->contactos.aMaterno);
        printf("%d ", raiz->contactos.edad);
        printf("%d/%d/%d ", raiz->contactos.fechaNacimiento.tm_year, raiz->contactos.fechaNacimiento.tm_mon, raiz->contactos.fechaNacimiento.tm_mday);
        printf("%s ", raiz->contactos.ciudad);
        printf("%s ", raiz->contactos.puesto);
        printf("%s ", raiz->contactos.empresa);
        imprimirListaContactos(raiz->contactos.nodoLista);
        return;
    }
	inOrderNombresV3(telefonoV2, raiz->der);
}

int buscarTelefonos(long telefonoV2, struct nodoLista *datos) {
     while(datos != NULL) {        
        
        if ( telefonoV2 == datos->d.telefonoPersonal )
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
    printf("%d ", raiz->contactos.fechaNacimiento);
    printf("%s ", raiz->contactos.ciudad);
    printf("%s ", raiz->contactos.puesto);
    printf("%s ", raiz->contactos.empresa);
    imprimirListaContactos(raiz->contactos.nodoLista);
    

	inOrden(raiz->der);
}

void imprimirListaContactos(struct nodoLista *datos) {
    printf("Lista de contactos:\n");
    while(datos != NULL) {        
        printf("\n%s %s ", datos->d.direccion, datos->d.nombreFamiliar);
        printf("\n%ld %ld ", datos->d.telefonoFijo, datos->d.telefonoCasa);
        printf("\n%ld %ld \n", datos->d.telefonoPersonal, datos->d.telefonoTrabajo);

        datos = datos->sig; 
    }
}

struct contacto leerNombresCompletos() {
    struct contacto c;
    
    printf("ingresar nombre:\n");
    scanf("%s", c.nombre);
    return c;
}

const char* leerNombresCompletosV2() {
    char* nombre;

    printf("ingresar  nombre a buscar:\n");
    scanf("%s", nombre);


    return nombre;
}

int eliminarNumero(long numero, struct nodoLista** raiz)
{
    struct nodoLista* temp = *raiz;
    struct nodoLista* previous;

    if (temp->sig == NULL) {
        *raiz = NULL;
        free(temp); 
        return 1;
    }

    if(temp!=NULL && temp->d.telefonoPersonal == numero) {
        *raiz = temp->sig;
        free(temp);
        return 1;
    }

    while (temp != NULL && temp->d.telefonoPersonal != numero) {
        previous = temp;
        temp = temp->sig;
    }
 
    if (temp == NULL) {
        return 0;
    }

    previous->sig = temp->sig;

    free(temp);

    return 1;
}

int eliminarNumeroDeContacto(struct contacto nombres, long numero, struct Nodo **raiz, struct Nodo *raizB) {
	if (raizB == NULL) {
		return 0;
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
        int eliminado = eliminarNumero(numero, &(*raiz)->contactos.nodoLista);
        if (eliminado == 1) {
            return 1;   
        } else {
            return 0;
        }
    
    }

	eliminarNumeroDeContacto(nombres, numero, raiz, raizB->der);
}

int eliminarNumeroDeContactoV2(long numero, struct Nodo **raiz, struct Nodo *raizB) {
	if (raizB == NULL) {
		return 0;
	}

	eliminarNumeroDeContactoV2(numero, raiz, raizB->izq);

    
    if ( buscarTelefonos(numero, raizB->contactos.nodoLista) == 0 )
    {
        int eliminado = eliminarNumero(numero, &(*raiz)->contactos.nodoLista);
        if (eliminado == 1) {
            return 1;   
        } else {
            return 0;
        }
    
    }

	eliminarNumeroDeContactoV2(numero, raiz, raizB->der);
}


long leerNumero() {
    long num = 0;

    printf("ingresa numero personal \n");
    scanf("%ld", &num);
    
    return num;
}



void liberarMemoria(struct Nodo **raiz) {
    if (raiz)
    {
        liberarMemoria(&((*raiz))->izq);
        liberarMemoria(&((*raiz))->der);
        free(raiz);
    } 
}