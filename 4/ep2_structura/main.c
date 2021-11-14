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
#include <string.h>

struct evento{
    char nombreEvento[30];
    char descripcion[30];
    char invitados[30];
    struct tm fecha;
    int horaFin;
};

struct elemento{
    struct evento dato;
    struct elemento *ant;
    struct elemento *sig;
};

int insertar(struct evento datoNuevo, struct elemento **inicio, struct elemento **fin);
int insertarInicio(struct evento datoNuevo, struct elemento **inicio, struct elemento **fin);
int insertarMedio(struct evento datoNuevo, struct elemento *anterior);

struct evento eliminar (struct evento datoE, struct elemento **inicio, struct elemento **fin);

void mostrarTodos(struct elemento *inicio);
void mostrarEvento(struct elemento *inicio);

void modificar(struct elemento *inicio);

int validarDia(struct tm primeraFecha, struct tm segundaFecha);
int esMayor(struct tm primeraFecha, struct tm segundaFecha);

struct evento agregar(); 


//NOTAS
//Agregar evento (no debe rpetirse fecha y hora) estar ordenados por la fecha
//eliminar por nombre del evento o fecha
//mostrar  todos los eventos y mostrar su contenido, requerir al usuario la fecha actual
//mostrar eventos de un día (por fecha específica)
//modificar descripción o invitados

int main (int argc, char **argv)
{
    struct elemento *inicio=NULL, *fin=NULL;
    int i, dato;

    int opcion = 0;

    while (opcion != 6)
    {
        printf("\n--------------------AGENDA------------------------\n");
        printf(" 1.-Agendar evento\n 2.- Eliminar  evento\n 3.-Modificar evento");
        printf("\n 4.-Consultar eventos\n 5.-Consultar evento por fecha \n 6.- Salir\n");
        scanf("%d", &opcion);

        switch (opcion)
        { 
        case 1:
            insertar(agregar(), &inicio, &fin);
            break;

        case 2:
            // eliminar();
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

int insertar(struct evento datoNuevo, struct elemento **inicio, struct elemento **fin)
{
    if(*inicio == NULL){
        return insertarInicio(datoNuevo,inicio,fin);
    }
    struct elemento *aux1 = *inicio, *aux2 =*inicio;

    while (aux1 != NULL)
    {
        if (esMayor(datoNuevo.fecha, aux1->dato.fecha) == 1)
        {
            aux1 =aux1->sig;
        }
        break;
    }

    if (aux1->sig == NULL)
    {
        return insertarInicio(datoNuevo, inicio,fin);
    }

    return insertarMedio(datoNuevo, aux1); 
}

int insertarInicio(struct evento datoNuevo, struct elemento **inicio, struct elemento **fin)
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

int insertarMedio(struct evento datoNuevo, struct elemento *anterior)
{
    struct elemento *nuevo;
    nuevo =(struct elemento *)malloc(sizeof(struct elemento));

    if (nuevo == NULL)
    {
        return 0;
    }

    nuevo->dato = datoNuevo;
    nuevo->ant = anterior;
    nuevo->sig = anterior->sig;
    

    nuevo->sig->ant = nuevo;
    anterior->sig = nuevo;
    return 1;
}



struct evento eliminar (struct evento datoE, struct elemento **inicio, struct elemento **fin)
{

}

void modificar(struct elemento *inicio)
{


}


struct evento agregar() {
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

    return e;
}


void mostrarTodos(struct elemento *inicio) {
    if (inicio == NULL) {
        printf("Sin datos\n");
        return;
    }

    while (inicio != NULL)
    {
        printf("|%s| (%s) anio: %d. mes: %d. dia: %d. hora: %d. Invitado: %s\n", inicio->dato.nombreEvento,
        inicio->dato.descripcion, inicio->dato.fecha.tm_year,inicio->dato.fecha.tm_mon,
        inicio->dato.fecha.tm_mday, inicio->dato.fecha.tm_hour, inicio->dato.invitados);

        inicio = inicio->sig;
    }
}

int validarDia(struct tm primeraFecha, struct tm segundaFecha) {

    if (primeraFecha.tm_year == segundaFecha.tm_year && 
    primeraFecha.tm_mon == segundaFecha.tm_mon && 
    primeraFecha.tm_mday == segundaFecha.tm_mday)
    {
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

    int opc = 0;

    while (inicio != NULL) {
        if ( validarDia(inicio->dato.fecha, fechaReq) == 0 ) {
            inicio = inicio->sig;
            continue;
        }
        break; 
    }

    if (inicio == NULL) {
        printf("Sin datos\n");
        return;
    }

        printf("Evento: |%s| (%s) año: %d. mes: %d. dia: %d. hora: %d. Invitado: %s \n", inicio->dato.nombreEvento,
        inicio->dato.descripcion, inicio->dato.fecha.tm_year,inicio->dato.fecha.tm_mon,
        inicio->dato.fecha.tm_mday, inicio->dato.fecha.tm_hour, inicio->dato.invitados);

        printf("Mostrar siguiente(1), anterior(2) o salir(0)? 0/1/2\n");
        scanf("%d", &opc);

    switch (opc)
    {
        case 1:
            if (inicio->sig == NULL) {
                printf("Sin datos\n");
                return;
            }

            inicio = inicio->sig;

            printf("|%s| (%s) año: %d. mes: %d. dia: %d. hora: %d. Invitado: %s \n", inicio->dato.nombreEvento,
            inicio->dato.descripcion, inicio->dato.fecha.tm_year,inicio->dato.fecha.tm_mon,
            inicio->dato.fecha.tm_mday, inicio->dato.fecha.tm_hour, inicio->dato.invitados);
            break;
        
        case 2: 
            if (inicio->ant == NULL) {
                printf("Sin datos\n");
                return;
            }

            inicio = inicio->ant;

            printf("|%s| (%s) año: %d. mes: %d. dia: %d. hora: %d. Invitado: %s \n", inicio->dato.nombreEvento,
            inicio->dato.descripcion, inicio->dato.fecha.tm_year,inicio->dato.fecha.tm_mon,
            inicio->dato.fecha.tm_mday, inicio->dato.fecha.tm_hour, inicio->dato.invitados);
            break;
 
        case 0: 
            break;
 
        default:
            printf("opcion incorrecta \n");
            break;
    }
}

int esMayor(struct tm primeraFecha, struct tm segundaFecha) {
    if (primeraFecha.tm_year > segundaFecha.tm_year &&
        primeraFecha.tm_mon > segundaFecha.tm_mon &&
        primeraFecha.tm_mday > segundaFecha.tm_mday &&
        primeraFecha.tm_hour > segundaFecha.tm_hour)
    {
        return 1;
    } else {
        return 0;
    }
    
    return 0;
}