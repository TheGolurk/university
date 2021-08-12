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

// TODO: rename all the structs names of tickets to flights or whatever fuck, also rename wrong function names
// When another seat is added, available should have the value of = n - 1 


struct tickets
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
        if(reg_passenger.id_flight != pass.id_flight && reg_passenger.id_seat != pass.id_seat)
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


//AQUI REALIZAR
//modificar vuelos vendidos
void modify_sold(int id) 
{
    FILE *ptrArchivo;
    ptrArchivo= fopen ("vuelos.dat","r+b");
    struct tickets reg_flights;

    if(ptrArchivo == NULL)
    {
        return;
    }

    while(fread(&reg_flights, sizeof(struct tickets), 1, ptrArchivo))
    {
        if(id != reg_flights.ID)
        {
            printf("ID no encontrado");
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

    while(fread(&reg_passenger, sizeof(struct products), 1, ptrArchivo))
    {
        if(id_s != reg_passenger.id_seat)
        {
            continue;
        }
     fseek(ptrArchivo, (sizeof(reg_passenger)), SEEK_SET);

        printf("Nombre del pasajero:\n");
        scanf("%s", &reg_passenger.name);
        
        printf("Introducir identificador de vuelo:\n");
        scanf("%d", &reg_passenger.id_flight);
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
    struct tickets flights;

    ptrArchivo= fopen ("vuelos.dat","r");
    if(ptrArchivo == NULL)
    {
        return;
    }
    
    while(fread(&flights, sizeof(struct tickets), 1,ptrArchivo))
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
void available_s() {
    FILE *ptrArchivo;
    struct tickets flights;

    ptrArchivo= fopen ("pasajeros.dat","r");
    if(ptrArchivo == NULL)
    {
        return;
    }
    
    while(fread(&flights, sizeof(struct tickets), 1,ptrArchivo))
    {
        printf("Vuelo: %d cuenta con %d asientos disponibles", flights.ID, flights.available);
    }

    fclose(ptrArchivo);
    

}

void get_seats() {
    FILE *ptrArchivo;
    ptrArchivo= fopen ("vuelos.dat","r");
    

    // What's the point of this function? If the previous function you can see the seats available per flight, 
}


int main(int argc, char const *argv[])
{
    int option;
    int ID;
    int id;
    int id_s


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
            scanf("%d", &id);

            modify_sold(id);

            break;

        case 4:

            printf("Ingrese el ID del asiento a modificar:\n");
            scanf("%d", &id_s);
            
            modify_seat(id_s);

            break;
            
        case 5:

            printf("Ingrese el ID del asiento \n");
            scanf("%d", &ID);

            get_seat(ID);

            break;

        case 6:

            inf_complete_flight(ID);

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
