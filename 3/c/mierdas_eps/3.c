#include <stdio.h>

int main() {

  int nums = 1;
  int space = 10;
  int count = 0;

  for (size_t t = 10; t > 1; t--)
  { 

    for (size_t i = 0; i < space; i++)
    {
      printf(" ");
    }

    for (size_t i = 0; i < nums; i++)
    {
      printf("*");
    }

    for (size_t i = 1; i < nums; i++)
    {
      printf("*");
    }

    nums++;
    space--;
    count++;
    printf("\n");

  }

  printf("final count", count);

  return 0;
}