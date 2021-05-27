#include <stdio.h>

int main() {

  int nums = 1;
  int space = 10;

  for (size_t t = 0; t < 10; t++)
  { 

    for (size_t i = 0; i < space; i++)
    {
      printf(" ");
    }

    for (size_t i = 0; i < nums; i++)
    {
      printf("%d",i);
    }

    for (size_t i = 1; i < nums; i++)
    {
      printf("%d",i);
    }

    nums++;
    space--;
    printf("\n");

  }

  return 0;
}