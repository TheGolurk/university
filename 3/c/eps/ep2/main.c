/*
PROGRAMA "PLAN PILOTO REGRESO A CLASES PRESENCIALES"

By: Hernandez Najera Christian & Valle Gonzalez Lorena  */


#include <stdio.h>
#include <string.h>

#define MAX_SIZE 3000

void pass_asistence(char* students[], int size) {

  for (size_t i = 0; i < size; i++) {

    if (!students[i]) {
        return;
    }

    printf("Alumno: %s \n Fecha de asistencia \n  Confirmacion de Asistencia \n  ", &students[i]);

  }

}

void reg_asistence (char* students[], int* dates[]){

    for (int i=0; i<MAX_SIZE; i++){
        printf(" Introducir nombre completo: \n");
        scanf("%s", &students[i]);

        printf("Introducir fecha de asistencia:\n");
        scanf("%d",&dates[i]);

        char option;
        printf("Desea introducir otro morro S N \n  ");
        scanf(" %c",&option);

        if(option== 'N'){
            return;
        }
    }

}

int main(int argc, char const *argv[])
{
    int opt;

    char* students[MAX_SIZE];
    int* dates[MAX_SIZE];
    char* asistence[MAX_SIZE];

    /*
    students[0] = "Lorena Valle Gonzalez";
    dates[0] = 01072021;
    asistence[0] = "si";

    students[1] = "Christian Hernandez Najera";
    dates[1] = 02072021;
    asistence[1] = "no";
    */

    while(opt != 4) {

      printf(" 1.- Registrar Alumno \n 2.- Registrar asistencia \n 3.- Desplegar informacion \n 4.-Salir\n");
      scanf("%d", &opt);


      switch(opt){

        case 1:

            reg_asistence(students, dates);

            break;

        case 2:



            break;

        case 3:
            pass_asistence(students, MAX_SIZE);


            break;

        case 4:


            break;

        default:
            printf("Incorrect option \n");
            return 0;
      }


    }

    return 0;
}
