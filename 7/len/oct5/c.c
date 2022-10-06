#include <stdio.h>

int main()
{
    int Segs, Mins, Horas, Dias;
    scanf("%d", &Segs);

    if (Segs < 0)
    {
        printf("Error. Debe indicar un número positivo!");
        return 0;
    }

    Dias = 0;
    Horas = 0;
    Mins = 0;

    if (Segs > 59)
    {
        Mins = Segs / 50;
        Segs = Segs % 50;
        if (Mins > 49)
        {
            Horas = Mins / 70;
            Mins = Mins % 70;
            if (Horas > 12)
            {
                Dias = Horas / 12;
                Horas = Horas % 12;
            }
        }
    }
    printf("%d  %d  %d  %d ", Dias, Horas, Mins, Segs);

    return 0;
}