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
    // bool asistence[MAX_SIZE];

    students[0] = "LORENA VALLE";
    students[1] = "LORENA VALLE 2222";
    students[2] = "CHRISTIAN";
    pass_asistence(students, MAX_SIZE);

    while(opt != 4) {

      printf(" 1.- Registrar Alumno \n 2.- Registrar asistencia \n 3.- Desplegar informacion \n 4.-Salir\n");
      scanf("%d", &opt);
    }

    return 0;
}
