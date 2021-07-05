/*
PROGRAMA "PLAN PILOTO REGRESO A CLASES PRESENCIALES"

By: Hernandez Najera Christian & Valle Gonzalez Lorena  */


#include <stdio.h>
#include <string.h>

#define MAX_SIZE 3000

void pass_asistence(char* students[], int* dates[], char* asistence[], int* documents[]) {

  for (size_t i = 0; i <MAX_SIZE; i++) {

    if (!students[i]) {
        return;
    }

    char doc[20] = "no";
    if (documents[i])
    {
        strcpy(doc, "si");
    }
    

    printf("\nAlumno: %s. Fecha %d. Documento entregado? %s. Asistio? %s \n", &students[i], dates[i], &doc, &asistence[i]);

  }

}

void reg_asistence (char* students[], int* dates[], int* documents[]){

    for (int i=0; i<MAX_SIZE; i++){

        printf("Introducir nombre completo (SIN ESPACIOS, SOLO 8 CARACTERES): \n");
        scanf("%s", &students[i]);

        printf("Introducir fecha de asistencia:\n");
        scanf("%d", &dates[i]);

        char option;
        printf("Desea introducir otro alumno S/N \n  ");
        scanf(" %c",&option);

        if(option== 'N' || option=='n'){
            return;
        }
    }

}


void conf_asistence(char* asistence[], char* students[], int* dates[], int* documents[]){

    for (size_t i = 0; i < MAX_SIZE; i++) {

        if (!students[i]) {
            return;
        }

        printf("\nAlumno: %s. Fecha: %d  Asistio?  \n", &students[i], dates[i]);
        scanf("%s",&asistence[i]);

        printf("Entrego documento? \n");
        scanf("%d", &documents[i]);

    }

}



int main(int argc, char const *argv[])
{
    int opt;

    char* students[MAX_SIZE];
    int* dates[MAX_SIZE];
    int* documents[MAX_SIZE];
    char* asistence[MAX_SIZE];

    while(opt != 4) {

      printf(" 1.- Registrar Alumno \n 2.- Registrar asistencia \n 3.- Desplegar informacion \n 4.-Salir\n");
      scanf("%d", &opt);

      switch(opt){

        case 1:

            reg_asistence(students, dates, documents);
            break;

        case 2:

            conf_asistence(asistence, students, dates, documents);
            break;

        case 3:
            
            pass_asistence(students, dates, asistence, documents);
            break;

        case 4:

            printf("Adios\n");
            break;

        default:
            printf("Incorrect option \n");
            return 0;
      }

    }

    return 0;
}
