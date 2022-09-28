#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *f;
    char ch;

    int index = 0, indexV2 = 0;
    int x;
    int a[100];

    f = fopen("ed2.txt", "r");
    if (f == NULL)
    {
        printf("Cannot open file \n");
        return 1;
    }

    ch = fgetc(f);
    while (ch != EOF)
    {
        int v = ch - '0';

        if (index == 0)
        {
            x = v;
        }
        else
        {
            if (ch == '\n' || ch == ' ')
            {
                ch = fgetc(f);
                continue;
            }
            a[indexV2] = v - 1;
            indexV2++;
        }

        ch = fgetc(f);

        index++;
    }

    int array[x][x];
    int sizeArr = sizeof(array[0]) / sizeof(int);
    for (size_t i = 0; i < sizeArr; i++)
    {
        for (size_t j = 0; j < sizeArr; j++)
        {
            array[i][j] = 0;
        }
    }

    for (size_t i = 0; i < 100; i+=2)
    {
        if (a[i] < 0 || a[i] > 9)
        {
            break;
        }

        if (i > x*2) {
            break;
        }

        int aa = a[i];
        int bb = a[i + 1];
        array[aa][bb] = 1;
    }

    for (size_t i = 0; i < sizeArr; i++)
    {
        for (size_t j = 0; j < sizeArr; j++)
        {
            printf("%d", array[i][j]);
        }
        printf("\n");
    }

    fclose(f);

    return 0;
}
