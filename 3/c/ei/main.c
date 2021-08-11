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
    int time_f;       //hora     1745
    int available[available_size];
};

struct passenger
{
    char name[max_size]; //nombre del pasajero
    int id_flight;   //identificador de vuelo
    int id_seat; // identificador único de asiento 
};


void modify_sold() {
    
}

void add_seat() {
    FILE *ptrArchivo;
    ptrArchivo= fopen ("pasajeros.dat","a+");

    if(ptrArchivo == NULL)
    {
        return;
    }
    struct passenger reg_passenger, pass;

    int res = 0;
    while(fread(&pass, sizeof(struct passenger, 1, ptrArchivo)))
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

void add_flight() {
    FILE *ptrArchivo;
    ptrArchivo= fopen ("vuelos.dat","a+");

    if(ptrArchivo == NULL)
    {
        return;
    }
    struct tickets reg_flights, reg;

    while(fread(&reg, sizeof(struct tickets, 1, ptrArchivo)))
    {

        if(reg_flights.ID == reg.ID || reg_flights.date ==reg.date || reg_flights.time_f == reg.time_f)
        {

            printf("Clave ya registrado\n");
            printf("Horario del vuelo  ya registrado\n");
            
            return;
        }

        fwrite(&reg_flights, sizeof(struct tickets), 1,ptrArchivo);

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

void modify_seat() {

}

void flights() {
    FILE *ptrArchivo
    struct tickets reg_flights;

    ptrArchivo = fopen("vuelos.dat", "r");
    if(ptrArchivo == NULL)
    {
        return;
    }

    while(fread(&reg_flights, sizeof(struct tickets),1,ptrArchivo))
    {
        printf("ID: %d\n  Origin: %s\n Destiny:%s\n  Date:%d\n  Time:%d\n ",reg_flights.ID,reg_flights.origin, reg_flights.origin, reg_flights.destiny, reg_flights.date, reg_flights.time_f);
    }

    fclose(ptrArchivo);
}

void inf_complete() {
    
}

void available_s() {

}

void get_seats() {
    
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
