/*
    
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 3000

#define GET_SIZE(x)  (sizeof(x) / sizeof((x)[0]))

void pass_asistence(char* students[], int size) {

  for (size_t i = 0; i < size; i++) {
    
    if (!students[i]) {
        return;
    }

    printf("List: %s \n", students[i]);
  
  }

}

int main(int argc, char const *argv[])
{
    int opt;

    char* students[MAX_SIZE];
    int dates[MAX_SIZE];
    char* asistence[MAX_SIZE];

    students[0] = "Lorena";
    dates[0] = 03072021;
    asistence[0] = "si";

    students[1] = "Luis";
    dates[1] = 31122021;
    asistence[1] = "no";

    

    while(opt != 4) {

      printf(" 1.- Registrar Alumno \n 2.- Registrar fecha de asistencia \n 3.- Desplegar informacion \n 4.-Salir\n");
      scanf("%d", &opt);


      switch(opt){

        case 1:
        break;

        case 2:
        break;

        case 3:
          pass_asistence(students, MAX_SIZE);
          break;
        
        case 4:
        break;

        default: 
          printf("Incorrect option\n");
          return 0;
      }


    }

    return 0;
}
