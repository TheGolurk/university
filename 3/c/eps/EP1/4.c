/*
Author: Christian Hernandez Najera & Lorena Valle Gonzalez
Github: https://github.com/TheGolurk

Analisis: 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * Draw(int size, int lenght);

void handlerErr(const char *err) {
    fprintf(stderr, "you have entered a wrong number. Error[ %s ] \n", err);
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {

  const char* out = Draw(10,10);
  printf("%s", out);

  return 0;
}

const char * Draw(int size, int lenght) {

  if (size < 3 || lenght < 13)
  {
    handlerErr("Out of lenght values");
  }
  
  static char array[] = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"; // Need to write string then


  snprintf(array, sizeof(array), " test %d", 10);
  
  

  return array;
}