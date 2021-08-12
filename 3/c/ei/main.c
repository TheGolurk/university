/******************************************************************************
EI. Evidencia Integradora

PROGRMA: VENTA DE BOLETOS DE VUELO EN AVIÓN

By:Hernández Nájera Christian & Valle González Lorena 

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define available_size 20
#define max_size 9999

struct flight
{
    int ID;  //identificador único de vuelo
    char origin[max_size];   //lugar de origen
    char destiny[max_size];    //destino
    int date;           //fecha de vuelo
    float time_f;       //hora 17:23
    int available;
};

struct passenger
{
    char*name[max_size]; //nombre del pasajero
    int id_flight;   //identificador de vuelo
    int id_seat; // identificador único de asiento 
    int available;
};


int available_flights(int ID) {
    FILE *ptrArchivo;
    struct flight flights;

    int available_seats = 0;

    ptrArchivo= fopen ("vuelos.dat","r");
    if(ptrArchivo == NULL)
    {
        return;
    }
    
    while(fread(&flights, sizeof(struct flight), 1,ptrArchivo))
    {
        if (ID == flights.ID)
        {
            if (flights.available == 0)
            {
                available_seats = 0;
            } else {
                available_seats = flights.available;
            }
            break;
        }
    }

    fclose(ptrArchivo);
    return available_seats;
}

//agregar un asiento
void add_seat() {
    FILE *ptrArchivo;
    ptrArchivo= fopen ("pasajeros.dat","a+");

    if(ptrArchivo == NULL)
    {
        return;
    }
    
    struct passenger reg_passenger, pass;

    int vuelo = 0;
    printf("Nombre del pasajero:\n");
    scanf("%s", &reg_passenger.name);
    
    printf("Introducir identificador de vuelo:\n");
    scanf("%d", &vuelo);
    
    printf(" Introducir identificador único de asiento:\n");
    scanf("%d", &reg_passenger.id_seat);
    
    int av = available_flights(reg_passenger.id_flight);
    if (av == 0) {
        printf("Ya no hay asientos disponibles para ese vuelo\n");
        return;
    }

    int res = 0;
    while(fread(&pass, sizeof(struct passenger), 1, ptrArchivo))
    {
        if(vuelo != pass.id_flight && reg_passenger.id_seat != pass.id_seat && pass.available == 0)
        {
            res = 1;
        } else {
            res = 0;
        }   
    }

    if (res == 1) {
        reg_passenger.available = 1;
        fwrite(&reg_passenger, sizeof(struct passenger), 1,ptrArchivo);
        if(fwrite !=0)
        {
            printf("Escrito correctamente\n");
        }
        else{
            printf("ERROR");
        }
    } else {
        printf("El asiento esta ocupado\n");
    }

    fclose(ptrArchivo);

    // Restamos uno a los asientos disponibles
    FILE *ptrArchivo;
    ptrArchivo= fopen ("vuelos.dat","r+b");
    struct flight reg_flights;

    if(ptrArchivo == NULL)
    {
        return;
    }

    while(fread(&reg_flights, sizeof(struct flight), 1, ptrArchivo))
    {
        if(reg_passenger.id_flight != reg_flights.ID)
        {
            continue;
        }

        fseek(ptrArchivo, (sizeof(reg_flights)), SEEK_SET);
        reg_flights.available = reg_flights.available - 1;
        
        fwrite(&reg_flights, sizeof(reg_flights), 1, ptrArchivo);
        break;
    }

    fclose(ptrArchivo);
}

//agregar vuelo del pasajero
void add_flight() {
    
    FILE *ptrArchivo;
    ptrArchivo= fopen ("vuelos.dat","a+");
    
    FILE *ptrArchivo_seats;
    ptrArchivo_seats = fopen ("pasajeros.dat","a+");

    if(ptrArchivo == NULL || ptrArchivo_seats)
    {
        return;
    }
    
    struct flight reg_flights, reg;
    struct passenger pass;

    printf("Introducir ID unico de vuelo:\n ");
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

    reg_flights.available = available_size;

    while(fread(&reg, sizeof(struct flight), 1, ptrArchivo))
    {

        if(reg_flights.ID == reg.ID || reg_flights.date ==reg.date || reg_flights.time_f == reg.time_f)
        {

            printf("Buscando si existen vuelos...\n");
            continue;
        }

        fwrite(&reg_flights, sizeof(struct flight), 1, ptrArchivo);
        if(fwrite !=0)
        {
            printf("Escrito correctamente\n");
        }
        else{
            printf("ERROR");
        }
    }
    fclose(ptrArchivo);

    // Agregar los boletos para el vuelo 
    for (size_t i = 0; i < reg_flights.available; i++)
    {
        pass.id_flight = reg_flights.ID;
        // Available: 0 esta libre, 1 esta ocupado.
        pass.available = 0;
        fwrite(&pass, sizeof(struct passenger), 1, ptrArchivo_seats);
    }
        
    fclose(ptrArchivo_seats);
}
 

//AQUI REALIZAR
//modificar vuelos vendidos
void modify_sold(int id) 
{
    FILE *ptrArchivo;
    ptrArchivo= fopen ("vuelos.dat","r+b");
    struct flight reg_flights;

    if(ptrArchivo == NULL)
    {
        return;
    }

    while(fread(&reg_flights, sizeof(struct flight), 1, ptrArchivo))
    {
        if(id != reg_flights.ID)
        {
            continue;
        }
    
        fseek(ptrArchivo, (sizeof(reg_flights)), SEEK_SET);
        
        printf(" Nuevo Lugar de Origen:\n");
        scanf("%s", &reg_flights.origin);
        
        printf("Nuevo Lugar de Destino: \n");
        scanf("%s", &reg_flights.destiny);
        
        printf("NUEVO HORARIO DE VUELO:\n\n");
        printf("Fecha:\n");
        scanf("%d", &reg_flights.date);
        
        printf("Hora:\n");
        scanf("%f", &reg_flights.time_f);

        fwrite(&reg_flights, sizeof(reg_flights), 1, ptrArchivo);

        if (fwrite != 0) 
        {
            printf("MODIFICADO CORECTAMENTE! \n");
        }
        fclose(ptrArchivo);
        break;
    }         
         
}


//AQUÍ REALIZAR
//modificar asiento
void modify_seat(int id_s) 
{
    FILE *ptrArchivo;
    ptrArchivo= fopen ("pasajeros.dat","r+b");

    struct passenger reg_passenger;

    if(ptrArchivo == NULL)
    {
        return;
    }

    while(fread(&reg_passenger, sizeof(struct passenger), 1, ptrArchivo))
    {
        if(id_s != reg_passenger.id_seat)
        {
            continue;
        }
        fseek(ptrArchivo, (sizeof(reg_passenger)), SEEK_SET);

        printf("Nombre del pasajero:\n");
        scanf("%s", &reg_passenger.name);
        
        fwrite(&reg_passenger, sizeof(struct passenger), 1, ptrArchivo);
    }
}

// consultar información de un asiento
void get_seat(int ID) {
    FILE *ptrArchivo;
    struct passenger _passenger;

    ptrArchivo = fopen("pasajeros.dat", "r");
    if(ptrArchivo == NULL)
    {
        return;
    }

    while(fread(&_passenger, sizeof(struct passenger), 1,ptrArchivo))
    {
        if (ID == _passenger.id_seat)
        {
            printf("ID asiento: %d, ID del vuelo: %d, Nombre: %d", _passenger.id_seat, _passenger.id_flight, _passenger.name);
            break;
        }
    }

    fclose(ptrArchivo);
}


//consultar información completa de un vuelo 
void inf_complete_flight(int ID) {
    FILE *ptrArchivo;
    struct flight flights;

    ptrArchivo= fopen ("vuelos.dat","r");
    if(ptrArchivo == NULL)
    {
        return;
    }
    
    while(fread(&flights, sizeof(struct flight), 1,ptrArchivo))
    {
        if (ID == flights.ID)
        {
            printf("ID: %d\n Origen: %s\n  Destino: %s\n  Fecha: %d \n Asientos disponibles: %d\n Hora: %d\n", flights.ID, flights.origin, flights.destiny, flights.date, flights.available, flights.time_f);
            break;
        }
    }

    fclose(ptrArchivo);
}


// consultar asientos disponibles en todos los vuelos
void available_s(int *available_seats[max_size], int *size) {
    FILE *ptrArchivo;
    struct flight flights;

    int index = 0;

    ptrArchivo= fopen ("pasajeros.dat","r");
    if(ptrArchivo == NULL)
    {
        return;
    }
    
    while(fread(&flights, sizeof(struct flight), 1,ptrArchivo))
    {
        if (flights.available > 0) {
            available_seats[index] = flights.ID;
            index++;
        }
    }

    fclose(ptrArchivo);
    size = index;
}

void get_seats(int available_seats[max_size], int size) {
    FILE *ptrArchivo;
    ptrArchivo= fopen ("vuelos.dat","r");

    struct passenger _passenger;
    
    while(fread(&_passenger, sizeof(struct passenger), 1,ptrArchivo))
    {
        
        for (size_t i = 0; i < size; i++)
        {
            if (available_seats[i] == _passenger.id_flight && _passenger.available == 0)
            {
                printf("Vuelo %d y asiento %d cuenta con disponibilidad", _passenger.id_flight, _passenger.id_seat);
            }
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    int option;
    int ID;
    int avalaible_flights[max_size];
    int size;

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

            printf("Ingrese el ID del vuelo a modificar:\n");
            scanf("%d", &ID);

            modify_sold(ID);

            break;

        case 4:

            printf("Ingrese el ID del asiento a modificar:\n");
            scanf("%d", &ID);
            
            modify_seat(ID);

            break;
            
        case 5:

            printf("Ingrese el ID del asiento \n");
            scanf("%d", &ID);

            get_seat(ID);

            break;

        case 6:

            printf("Ingrese el ID del vuelo \n");
            scanf("%d", &ID);
            inf_complete_flight(ID);

            break;

        case 7:

            available_s(*available_flights, &size);
            get_seats(available_flights, size);

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
