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

    // restar
    for (size_t i = 0; i < nums; i++)
    {
      printf("%d", baseleft);
      baseleft--;

      if (baseleft < 0) {
        baseleft = 9;
      }

    }

    baseright = baseleft+2;
    

    // sumar
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