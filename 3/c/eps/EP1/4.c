/*
Author: Christian Hernandez Najera & Lorena Valle Gonzalez
Github: https://github.com/TheGolurk

Analisis: 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * Draw(int lenght, int size);

void handlerErr(int number) {
    fprintf(stderr, "you have entered a wrong number: %d \n", number);
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {

  const char* z = Draw(10,10);
  printf("%s", z);

  return 0;
}

const char * Draw(int lenght, int size) {

  static char array[] = "";


  // strncat(array, "hola", sizeof("hola"));
  snprintf("hola", sizeof(array), "%d", 10);
  
  

  return array;
}