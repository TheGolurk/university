/*
Author: Christian Hernandez Najera & Lorena Valle Gonzalez
Github: https://github.com/TheGolurk

Analisis: Se debe crear un programa que imprima un arbol y este se 
debe llenar con una susecion numerica, esta sucesión fué tomada en cuenta
de arriba hacía abajo, de tal manera que es descendente y cada que se alcanza
el número 9 éste debe volver al numero 0 es decir: 0 9 8 7 6 5 4 3 2 1 0 1 2 3 4 5 6 7 8 9 0 1 2 ....  */

#include <stdio.h>

int main(int argc, char const *argv[]) {

  int nums = 1;
  int space = 10;
  
  int base = 9;
  int baseleft = base;
  int baseright = base;

  for (size_t t = 10; t > 0; t--)
  { 

    for (size_t i = 0; i < space; i++)
    { 
      printf(" ");
    }

    for (size_t i = 0; i < nums; i++)
    {
      printf("%d", baseleft);
      baseleft--;

      if (baseleft < 0) {
        baseleft = 9;
      }

    }

    baseright = baseleft + 2;

    for (size_t i = 1; i < nums; i++)
    {

      if (baseright > 9) {
        baseright = 0;
      }

      printf("%d", baseright);
      baseright++;
  
    }

    nums++;
    space--;
  
    base--;
    baseleft = base;
    baseright = base;

    printf("\n");

  }

  return 0;
}