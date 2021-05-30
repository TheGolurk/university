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

  const char* out = Draw(3, 13);
  printf("%s", out);

  return 0;
}

const char * Draw(int size, int lenght) {

  if (size < 3 || lenght < 13)
  {
    handlerErr("Out of lenght values");
  }
  
  static char array[] = "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"; // Need to write string then

  int general = lenght - 5;
  int secondTriangle = (general / 2) + 1;
  int firstTriangle = general - secondTriangle;

  printf("Calculate: %d %d %d \n", general, firstTriangle, secondTriangle);

  int spaces = firstTriangle + 3;
  int limit = 1;

  for (size_t i = i; i <= secondTriangle; i++)
  {
    if (i < 3)
    {
      for (size_t j = 0; j < spaces; j++)
      {
        printf(" ");
      }
    } else {
      for (size_t j = 0; j < spaces-(firstTriangle+1); j++)
      {
        printf(" ");
      }
    }

    for (size_t t = 1; t <= limit; t++)
    {
      printf("*");
    }
    
    limit += 1;
    
    

    /*
    for (size_t j = 0 ; j < firstTriangle-i; j++)
    {
      printf(" ");
    }

    for (size_t k = 1; k <= i; k++)
    {
      printf("*");
    } */
    
    
    printf("\n");
  }
  

  // snprintf(array, sizeof(array), " test %d", 10);
  
  

  return array;
}