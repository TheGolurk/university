/*
AUTORES: 
HERNÁNDEZ NÁJERA CHRISTIAN
PEREZ BALTAZAR MITZI GUADALUPE
VALLE GONZÁLEZ LORENA
EP2_Implementación y uso de listas de datos
13-NOVIEMBRE-2021
*/
//https://www.tutorialspoint.com/learn_c_by_examples/linked_list_programs_in_c.htm
//https://www.cplusplus.com/reference/ctime/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct evento{
    char nombreEvento[30];
    char descripcion;
    int invitados[30];
    struct tm fecha;
    int horaFin;
};

struct elemento{
    struct evento dato;
    struct elemento *ant;
    struct elemento *sig;
};

int insertar(int datoNuevo, struct elemento **inicio, struct elemento **fin);
int insertarInicio(int datoNuevo, struct elemento **inicio, struct elemento **fin);
struct evento eliminar (struct evento datoE, struct elemento **inicio, struct elemento **fin);
void mostrarTodos(struct elemento *inicio);
void mostrarEvento(struct elemento *inicio);
void modificar(struct elemento *inicio);
int validarDia(struct tm primeraFecha, struct tm segundaFecha);

//NOTAS
//Agregar evento (no debe rpetirse fecha y hora) estar ordenados por la fecha
//eliminar por nombre del evento o fecha
//mostrar  todos los eventos y mostrar su contenido, requerir al usuario la fecha actual
//mostrar eventos de un día (por fecha específica)
//modificar descripción o invitados


int insertar(int datoNuevo, struct elemento **inicio, struct elemento **fin)
{
    if(*inicio == NULL){
        return insertarInicio(datoNuevo,inicio,fin);
    }
    struct elemento *aux1 = *inicio, *aux2 =*inicio;

    while (aux1 != NULL)
    {
        if (datoNuevo > aux1->dato)
        {
            aux1 =aux1->sig;
        }
        break;
    }

    if (aux1->sig == NULL)
    {
        return insertarInicio(datoNuevo, inicio,fin);
    }
    
}

int insertarInicio(int datoNuevo, struct elemento **inicio, struct elemento **fin)
{
    struct elemento *nuevo;
    nuevo=(struct elemento *)malloc(sizeof(struct elemento));
    if(nuevo==NULL){
        return 0;
    }
    nuevo->dato=datoNuevo;
    nuevo->ant=NULL;
    nuevo->sig=*inicio;
    
    if(*inicio==NULL){
        *fin=nuevo;
    }else{
        (*inicio)->ant=nuevo;
    }
    *inicio=nuevo;
    return 1;

}


struct evento eliminar (struct evento datoE, struct elemento **inicio, struct elemento **fin)
{



}

void modificar(struct elemento *inicio)
{



}


void agregar() {
    struct evento e;

    printf("Ingresa el nombre de evento: \n");
    scanf("%s",e.nombreEvento);

    printf(" Introduzca el dia para el evento:\n ");
    scanf("%d", &e.fecha.tm_mday);

    printf(" Introduzca el mes en numero: \n ");
    scanf("%d", &e.fecha.tm_mon);

    printf(" Introduzca el año: \n");
    scanf("%d",&e.fecha.tm_year);

    printf("Hora inicial del evento: \n");
    scanf("%i",&e.fecha.tm_hour);

    printf("Minutos: \n");
    scanf("%d",&e.fecha.tm_min);
 
    printf("Agregar descripción: \n");
    scanf("%s",e.descripcion);

    printf("Nombre del invitado\n");
    scanf("%s",e.invitados);

    printf("Hora de finalización: \n");
    scanf("%d", &e.horaFin);
}


int main (int argc, char **argv)
{
    struct elemento *inicio=NULL, *fin=NULL;
    int i, dato;

    int opcion = 0;

    while (opcion != 6)
    {
        printf("--------------------AGENDA------------------------");
        printf("1.-Agendar evento\n  2.- Eliminar  evento\n 3.-Modificar evento \n ");
        printf("4.-Consultar eventos\n 5.-Consultar evento por fecha \n 6.- Salir");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:

            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            mostrarTodos(inicio);
            break;

        case 5:
            mostrarEvento(inicio);
            break;

        case 6:
            printf("HASTA LUEGO\n");
            break;

        default:
            printf("Opcion incorrecta, intente de nuevo\n");
            break;
        }
    }
}

void mostrarTodos(struct elemento *inicio) {
    if (inicio == NULL) {
        printf("Sin datos\n");
        return;
    }

    while (inicio != NULL)
    {
        printf("|%s| (%s) anio: %d. mes: %d. dia: %d. hora: %d. Invitado: %s", inicio->dato.nombreEvento,
        inicio->dato.descripcion, inicio->dato.fecha.tm_year,inicio->dato.fecha.tm_mon,
        inicio->dato.fecha.tm_mday, inicio->dato.fecha.tm_hour, inicio->dato.invitados);

        inicio = inicio->sig;
    }
}

int validarDia(struct tm primeraFecha, struct tm segundaFecha) {
    double sec = difftime(primeraFecha, segundaFecha);
    if (sec == 0) {
        return 1;
    }

    return 0;
}

void mostrarEvento(struct elemento *inicio) {
    if (inicio == NULL) {
        printf("Sin datos\n");
        return;
    }
    
    struct tm fechaReq;
    printf("Ingrese el anio \n");
    scanf("%d", &fechaReq.tm_year);

    printf("Ingrese el mes \n");
    scanf("%d", &fechaReq.tm_mon);

    printf("Ingrese el dia \n");
    scanf("%d", &fechaReq.tm_mday);

    char opc = ' ';
    int flag = 0;

    while (inicio != NULL || opc == 'n') {

        if (flag != 0) {
            return;
        }

        if ( validarDia(inicio->dato.fecha, fechaReq) == 0 ) {
            inicio = inicio->sig;
            continue;
        }

        printf("|%s| (%s) anio: %d. mes: %d. dia: %d. hora: %d. Invitado: %s", inicio->dato.nombreEvento,
        inicio->dato.descripcion, inicio->dato.fecha.tm_year,inicio->dato.fecha.tm_mon,
        inicio->dato.fecha.tm_mday, inicio->dato.fecha.tm_hour, inicio->dato.invitados);

        printf("Mostrar siguiente(s), anterior(a) o salir(n)? a/s/n");
        scanf("%c", opc);

        switch (opc)
        {
        case 's':
            inicio = inicio->sig;
            flag = 1;
            break;
        
        case 'a': 
            inicio = inicio->ant;
            flag = 1;
            break;
 
        case 'n':
            flag = 1; 
            break;
 
        default:
            printf("opcion incorrecta \n");
            opc = 'n';
            break;
        }
    }
}