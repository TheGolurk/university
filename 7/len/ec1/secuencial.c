#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int char2int(char *array, size_t n);
int iterativeBinarySearch(int array[], int start_index, int end_index, int element);

int main()
{
    FILE *textfile;
    char line[MAX_LINE_LENGTH];
    int index = 0;
    int arrayLen;
    int *arr = malloc(0 * sizeof(int));
    int num = 0;
    int last = 0;
    int toSearch = 0;
    int posArray = 0;
    int sizeArr = 0;
    int indexIterative = -1;

    textfile = fopen("Matriz.txt", "r");
    if (textfile == NULL)
        return 1;

    while (fgets(line, MAX_LINE_LENGTH, textfile))
    {
        num = char2int(line, strlen(line));

        if (index == 1)
        {
            int *nuevo = realloc(arr, num * sizeof(arr));
            sizeArr = num;
        }

        if (index >= 3)
        {
            if (num == 0)
            {
                index++;
                last = 1;
                continue;
            }
            arr[posArray] = num;
            posArray++;
        }

        if (last == 1)
        {
            toSearch = num;
        }

        index++;
    }

    fclose(textfile);

    for (size_t i = 0; i < sizeArr; i++)
    {
        if (arr[i] == toSearch) {
            indexIterative = i;
        }
    }

    printf("Posicion indice: [%d] \n", indexIterative);

    return 0;
}

int char2int(char *array, size_t n)
{
    int number = 0;
    int mult = 1;

    n = (int)n < 0 ? -n : n;

    while (n--)
    {
        if ((array[n] < '0' || array[n] > '9') && array[n] != '-')
        {
            if (number)
                break;
            else
                continue;
        }

        if (array[n] == '-')
        { 
            if (number)
            {
                number = -number;
                break;
            }
        }
        else
        { 
            number += (array[n] - '0') * mult;
            mult *= 10;
        }
    }

    return number;
}