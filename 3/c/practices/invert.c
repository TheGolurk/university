#include <stdio.h>

int * invert(int arr[], int size);

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int main(int argc, char const *argv[])
{
    
    int values[] = {1,2,3,4,5};
    int tmp[NELEMS(values)-1];
    int val = NELEMS(values)-1;
    int *new = invert(values, val);

    for (size_t i = 0; i <= val; i++)
    {
        tmp[i] = values[val-i];
        printf("[%d]: %d %d \n", i, tmp[i], new[i]);
    }

    return 0;
}

int * invert(int arr[], int size) {
    for (size_t i = 0; i <= size; i++)
    {
        arr[i] = arr[size-i];
    }
    return arr;
}