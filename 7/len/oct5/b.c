#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, index = 1, serp = 0;
    scanf("%d %d", &a, &b);

    for (size_t i = 0; i < a; i++)
    {
        for (size_t j = 0; j < b; j++)
        {
            if (serp == 1)
            {
                printf("%d ", index);
                index--;
            }
            else
            {
                printf("%d ", index);
                index++;
            }
        }

        if (serp == 0) {
            serp = 1;
            index += (b - 1);
        } else {
            serp = 0;
            index  += (b + 1);
        }

        printf("\n");
    }

    return 0;
}
