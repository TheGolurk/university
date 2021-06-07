#include <stdio.h>

int * invert(int arr[], int size);

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int main(int argc, char const *argv[])
{
    int values[] = {1,2,3,4,5};
    int size = NELEMS(values)-1;
    int reversed[size];
    
    for (size_t i = 0; i <= size; i++)
    {
        reversed[size-i] = values[i];
        reversed[i] = values[size-i];
        printf("[%d]: %d \n", i, reversed[i]);
    }
    
    return 0;
}