/*
EQUIPO: Valle Gonzalez Lorena
        Perez Baltazar Mitzi Guadalupe
        Hernandez Najera Christian

GRADO Y GRUPO: 4.C ITI

REPOSITORIO: https://github.com/TheGolurk/university/blob/master/4/EP1_O2021_ESD_4C_Valle_Perez_Hernandez.c
*/

#include <stdio.h>
#include <stdlib.h>

// struct
struct Register {
    char  carplates[30];
    char  model[30];
    char  color[30];
    int   date;
    float checkin;
    float checkout;
    char  name[30];
    
};

struct queue{
    struct Register data;
    struct queue *next;
};

// Links a recursos que nos puede ayudar a hacer esta cosa
// https://gist.github.com/rdleon/d569a219c6144c4dfc04366fd6298554
// https://github.com/rafaeltardivo/C-Queue/blob/master/queue.c
// https://gist.github.com/fenrig/2624655



// aqui las definiciones nadamas. despues del main van las funciones
void check_in();
void check_out();
void show();
void Menu();

int main(int argc, char const *argv[])
{
    Menu();

    return 0;
}

void Menu(){
    int opt;
    printf("Ingresa una opcion \n");
    printf(" 1.- Registrar entrada \n 2.- Registrar Salida \n 3.- Mostrar \n 4.- Salir \n");
    scanf("%d", &opt);


    while (opt != 4)
    {

        switch (opt)
        {
        case 1:
            break;

        case 2:
            break;
        
        case 3:
            break;
            
        case 4:
            break;
        
        default:
            break;
        }

    }

}

void check_in() {

}

void check_out() {

}

void show() {

}