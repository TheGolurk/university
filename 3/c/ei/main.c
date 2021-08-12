/******************************************************************************
EI. Evidencia Integradora

PROGRMA: VENTA DE BOLETOS DE VUELO EN AVIÓN

By:Hernández Nájera Christian & Valle González Lorena 

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define available_size 30
#define max_size 9999

struct tickets
{
    int ID;  //identificador único de vuelo
    char origin[max_size];   //lugar de origen
    char destiny[max_size];    //destino
    int date;           //fecha de vuelo
    float time_f;       //hora 17:23
    int available[available_size];
};

struct passenger
{
    char*name[max_size]; //nombre del pasajero
    int id_flight;   //identificador de vuelo
    int id_seat; // identificador único de asiento 
};


//agregar un asiento
void add_seat() {
    FILE *ptrArchivo;
    ptrArchivo= fopen ("pasajeros.dat","a+");

    if(ptrArchivo == NULL)
    {
        return;
    }
    
    struct passenger reg_passenger, pass;

    printf("Nombre del pasajero:\n");
    scanf("%s", &reg_passenger.name);
    
    printf("Introducir identificador de vuelo:\n");
    scanf("%d", &reg_passenger.id_flight);
    
    printf(" Introducir identificador único de asiento:\n");
    scanf("%d", &reg_passenger.id_seat);
    
    int res = 0;
    while(fread(&pass, sizeof(struct passenger), 1, ptrArchivo))
    {
        if(reg_passenger.id_flight != pass.id_flight && reg_passenger.id_seat != pass.available)
        {
            res = 1;
        } else {
            res = 0;
        }   
    }

    if (res == 1) {
        fwrite(&reg_passenger, sizeof(struct passenger), 1,ptrArchivo);
        if(fwrite !=0)
        {
            printf("Escrito correctamente\n");
        }
        else{
            printf("ERROR");
        }
    }

    fclose(ptrArchivo);
}


//agregar vuelo del pasajero
void add_flight() {
    
    FILE *ptrArchivo;
    ptrArchivo= fopen ("vuelos.dat","a+");

    if(ptrArchivo == NULL)
    {
        return;
    }
    
    
    struct tickets reg_flights, reg;

    printf("Introducir ID único de vuelo:\n ");
    scanf("%d", &reg_flights.ID);
    
    printf("Lugar de Origen:\n");
    scanf("%s", &reg_flights.origin);
    
    printf("Lugar de Destino: \n");
    scanf("%s", &reg_flights.destiny);
    
    printf("HORARIO DE VUELO:\n\n");
    printf("Fecha:\n");
    scanf("%d", &reg_flights.date);
    
    printf("Hora:\n");
    scanf("%f", &reg_flights.time_f);
    


    while(fread(&reg, sizeof(struct tickets), 1, ptrArchivo))
    {

        if(reg_flights.ID == reg.ID || reg_flights.date ==reg.date || reg_flights.time_f == reg.time_f)
        {

            printf("ID único de vuelo ya registrado\n");
            printf("Horario de vuelo  ya registrado\n");
            
            return;
        }

        fwrite(&reg_flights, sizeof(struct tickets), 1, ptrArchivo);

        if(fwrite !=0)
        {
            printf("Escrito correctamente\n");
        }
        else{
            printf("ERROR");
        }
    }

    fclose(ptrArchivo);
}



//modificar vuelos
void modify_sold() {
    
    FILE *ptrArchivo;
    ptrArchivo= fopen ("vuelos.dat","r+b");
    
    
    
    
    
    
}



//modificar asiento
void modify_seat() {

    FILE *ptrArchivo;
    ptrArchivo= fopen ("pasajeros.dat","r+b");



}



//consultar información de un asiento
void flights() {
    FILE *ptrArchivo
    struct passenger reg_passenger;

    ptrArchivo = fopen("pasajeros.dat", "r");
    if(ptrArchivo == NULL)
    {
        return;
    }

    while(fread(&reg_passenger, sizeof(struct passenger), 1,ptrArchivo))
    {
        printf("ID: %d\n  Origin: %s\n Destiny: %s\n  Date:%d \n  Time:%f\n ",reg_passenger.ID,reg_passenger.origin, reg_passenger.origin, reg_passenger.destiny, reg_passenger.date, reg_passenger.time_f);
    }

    fclose(ptrArchivo);
}



//consultar información completa de un vuelo 
void inf_complete() {
    
    FILE *ptrArchivo;
    ptrArchivo= fopen ("vuelos.dat","r");
    
    
    
    
    
    
}



// consultar asientos disponibles en todos los vuelos
void available_s() {

    FILE *ptrArchivo;
    ptrArchivo= fopen ("pasajeros.dat","r");

}

void get_seats() {
    
    FILE *ptrArchivo;
    ptrArchivo= fopen ("vuelos.dat","r");
    
    
    
}







int main(int argc, char const *argv[])
{
    int option;

    printf("1.- Agregar un vuelo \n2- Agregar un asiento \n 3.- Modificar un vuelo \n4.- Modificar informacion de asiento vendido \n 5.- Consultar informacion de un asiento\n");
    printf("6.- Consultar informacion completa de un vuelo \n7.- Consultar asientos disponibles en todos los vuelos \n 8.- Salir \n");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            add_flight();
            break;

        case 2:
            add_seat();

            break;

        case 3:
            modify_sold();

            break;

        case 4:

            modify_seat();

            break;
            
        case 5:

            flights();

            break;

        case 6:

            inf_complete();

            break;

        case 7:

            available_s();
            get_seats();

            break;

        case 8:

            printf("Adios");
            break;

        default:
            printf("Opcion incorrecta\n");
            return;
    
    }


    return 0;
}
