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

  const char* out = Draw(3, 20);
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

  int spaces = firstTriangle + 3;
  int limit = 1;
  int spacesFirst = 3;

  int firstTriangleTMP = firstTriangle;
  
  // General size for the first and second triangle.
  for (size_t i = 1; i <= secondTriangle; i++)
  {

    // there are 2 spaces of height from second triangle to first triangle
    if (i < 3)
    {

      for (size_t j = 0; j < spaces; j++)
      {
        printf(" ");
      }

    } else {  // We can start to print the first triangle once the spaces of height was passed
    
     printf("  ");

      for (size_t q = 1; q <= firstTriangleTMP-1; q++)
      {
        printf(" ");
      }

      // repeat across the lenght of first triangle and only print the character outline 
      for (size_t q = firstTriangleTMP; q <= firstTriangle; q++)
      {        
        if (q == firstTriangleTMP || i == secondTriangle || q == firstTriangle)
        {
          printf("*");
        }else {
          printf(" ");
        }
        
      }

      firstTriangleTMP--;

      printf(" ");

    }

    // second triangle
    for (size_t t = 1; t <= limit; t++)
    {
      if (t == 1 || i == secondTriangle || t == limit)
      {
        printf("*");  
      } else if (t > 1) {
        printf(" ");
      }
    }
    
    limit += 1;
    
    printf("\n");
  }
  
  // Base
  for (size_t i = 0; i < lenght; i++)
  {
    printf("*");
  }
  
  printf("\n");

  // the middle of the base, have a character only in the spaces of (lenght variable)-1
  for (size_t i = 0; i < lenght; i++)
  {
    printf(" ");
    if (i == 0 || i == lenght-4)
    {
      printf("*");
    }
    
  }

  printf("\n");

  for (size_t i = 0; i < 2; i++)
  {
    printf(" ");
  }
  for (size_t i = 0; i < lenght-4; i++)
  {
    printf("*");
  }

  // snprintf(array, sizeof(array), " test %d", 10);
  return array;
}
