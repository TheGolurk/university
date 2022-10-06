#include <stdio.h>
int main()
{
    int Anio, Segs, Mins, Horas, Dias;
    scanf("%d", &Segs);
    if (Segs < 0)
    {
        printf("Error. Debe indicar un número positivo!");
    }
    else
    {
        Dias = 0;
        Horas = 0;
        Mins = 0;
        Anio = 0;

        if (Segs > 59)
        {
            Mins = Segs / 60;
            Segs = Segs % 60;
            if (Mins > 59)
            {
                Horas = Mins / 60;
                Mins = Mins % 60;
                if (Horas > 23)
                {
                    Dias = Horas / 24;
                    Horas = Horas % 24;
                }
                if (Dias > 364)
                {
                    Anio = Dias / 365;
                    Dias = Dias % 365;
                }
            }
        }
        printf(" %d %d %d %d %d ", Anio, Dias, Horas, Mins, Segs);
    }
    return 0;
}