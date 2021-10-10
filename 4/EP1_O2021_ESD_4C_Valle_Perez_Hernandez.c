/*
EQUIPO: Valle Gonzalez Lorena
        Perez Baltazar Mitzi Guadalupe
        Hernandez Najera Christian

GRADO Y GRUPO: 4.C ITI

REPOSITORIO: https://github.com/TheGolurk/university/blob/master/4/EP1_O2021_ESD_4C_Valle_Perez_Hernandez.c
*/

// Links a recursos que nos puede ayudar a hacer esta cosa
// https://gist.github.com/rdleon/d569a219c6144c4dfc04366fd6298554
// https://github.com/rafaeltardivo/C-Queue/blob/master/queue.c
// https://gist.github.com/fenrig/2624655

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int insert(struct queue **start, struct queue **finish, struct Register data);
struct Register delete(struct queue **start, struct queue **finish);
int empty(struct queue *start);
struct Register first(struct queue *start); 
struct Register read(struct Register newdata);


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


int insert(struct queue **start, struct queue **finish, struct Register newdata)
{
    struct queue *new;
    new=(struct queue*)malloc(sizeof(struct queue));
    if (new == NULL) {
        return 0;
    }

    newdata = read(newdata);

    new->data = newdata;
    new->next = NULL;
    if (*start == NULL)
    {
        *start = new;

    }
    *finish=new;
    return 1;
}

struct Register delete(struct queue **start, struct queue **finish)
{
    struct Register dataRemoved;
    if (*start == NULL){
        return dataRemoved;
    }

    struct queue toRemove = *start;
    dataRemoved =toRemove-> data;

    *start = toRemove->next;
    if (*start == NULL)
    {
        *finish == NULL;
    }
    free(toRemove);

    return dataRemoved;    
}

int empty(struct queue *start){

    if (start == NULL)
    {
        return 1;
    }
    return 0;

}

struct Register read(struct Register newdata) {
   printf("ingresa la fecha \n");
   scanf("%d", &newdata.date);
   
   printf("ingrese hora de entrada \n");
   scanf("%f", &newdata.checkin);

   printf("ingrese el modelo \n");
   scanf("%[^\n]%*c", &newdata.model);

   printf("ingrese el color \n");
   scanf("%[^\n]%*c", &newdata.color);

   printf("ingrese el nombre \n");
   scanf("%[^\n]%*c", &newdata.name);

   printf("ingrese las placas \n");
   scanf("%[^\n]%*c", &newdata.carplates);

   return newdata; 
}
