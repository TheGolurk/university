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
        return -1;
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
    FILE *ptrArchivo_seat;
    ptrArchivo_seat = fopen ("vuelos.dat","r+b");
    struct flight reg_flights;

    if(ptrArchivo_seat == NULL)
    {
        return;
    }

    while(fread(&reg_flights, sizeof(struct flight), 1, ptrArchivo_seat))
    {
        if(reg_passenger.id_flight != reg_flights.ID)
        {
            continue;
        }

        fseek(ptrArchivo_seat, (sizeof(reg_flights)), SEEK_SET);
        reg_flights.available = reg_flights.available - 1;
        
        fwrite(&reg_flights, sizeof(reg_flights), 1, ptrArchivo_seat);
        break;
    }

    fclose(ptrArchivo_seat);
}

void add_flight() {
    FILE *ptrArchivo;
    ptrArchivo = fopen ("vuelos.dat","a+");
    
    FILE *ptrArchivo_seats;
    ptrArchivo_seats = fopen ("pasajeros.dat","a+");

    if(ptrArchivo == NULL || ptrArchivo_seats == NULL)
    {
        printf("No se puedo abrir el archivo \n");
        return;
    }

    int check = 0;
    
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
        check = 1;
        if(reg_flights.ID == reg.ID || reg_flights.date ==reg.date || reg_flights.time_f == reg.time_f)
        {

            printf("ID o Fecha ya utilizados\n");
            break;
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
    
    if (check = 0)
    {
        fwrite(&reg_flights, sizeof(struct flight), 1, ptrArchivo);
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
 


int main(int argc, char const *argv[])
{
    int option = 0;
    int ID;
    int avalaible_flights[max_size];
    int size;

    while (option != 8)
    {
        fflush(stdin);
        printf("1.- Agregar un vuelo \n2- Agregar un asiento \n3.- Modificar un vuelo \n4.- Modificar informacion de asiento vendido \n5.- Consultar informacion de un asiento\n");
        printf("6.- Consultar informacion completa de un vuelo \n7.- Consultar asientos disponibles en todos los vuelos \n8.- Salir \n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                add_flight();
                break;

            case 2:
                printf("2");

                break;

            case 3:

                printf("3");
                break;

            case 4:

                printf("4");

                break;
                
            case 5:

                printf("5");

                break;

            case 6:

                printf("6");

                break;

            case 7:

                printf("7");

                break;

            case 8:

                printf("8");
                break;

            default:
                printf("Opcion incorrecta\n");
        
        }

    }

    return 0;
}
