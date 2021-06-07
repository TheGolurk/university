#include <stdio.h>

int * invert(int arr[], int size);

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int main(int argc, char const *argv[])
{
    int values[] = {1,2,3,4,5};
    int val = NELEMS(values)-1;
    int *new = invert(values, val);

    return 0;
}

int * invert(int arr[], int size) {
    int tmp[size];
    for (size_t i = 0; i <= size; i++)
    {
        tmp[size-i] = arr[i];
        tmp[i] = arr[size-i];
        printf("[%d]: %d \n", i, tmp[i]);
    }
    return tmp;
}