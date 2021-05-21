#include <stdio.h>

char firsResult(int number);
char secondResult(int number);
char thirdResult(int number);

int main(int argc, char const *argv[])
{
    
    int aciertos = 0;
    char note;

    printf("Ingresa tu numero de aciertos: \n");
    scanf("%d", &aciertos);

    /* if */
    note = firsResult(aciertos);
    printf("Resultado de la nota metodo 1 %c \n", note);

    /* if else */
    note = secondResult(aciertos);
    printf("Resultado de la nota metodo 2 %c \n", note);


    /* switch */
    note = thirdResult(aciertos);
    printf("Resultado de la nota metodo 3 %c \n", note);

    return 0;
}

// firsResult using if
char firsResult(int number) 
{
    char note;
    if (number >= 1 && number <= 9)
    {
        note = 'E';
    }

    if (number == 10 || number == 11 || number == 12)
    {
        note = 'D';
    }

    if (number == 13 || number == 14 || number == 15)
    {
        note = 'C';
    }

    if (number == 16 || number == 17 || number == 18)
    {
        note = 'B';
    }

    if (number == 19 || number == 20)
    {
        note = 'A';
    }
    
    
    return note;
}

// secondResult using if else
char secondResult(int number) 
{
    char note;

    if (number >= 1 && number <= 9)
    {
        note = 'E';
    } else if (number == 10 || number == 11 || number == 12)
    {
        note = 'D';
    } else if (number == 13 || number == 14 || number == 15)
    {
        note = 'C';
    } else if (number == 16 || number == 17 || number == 18)
    {
        note = 'B';
    } else if (number == 19 || number == 20)
    {
        note = 'A';
    }

    return note;
}

// thirdResult using switch
char thirdResult(int number) 
{
    char note;

    switch (number)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        note = 'E';    
        break;
        
    case 10:
    case 11:
    case 12:
        note = 'D';    
        break;

    case 13:
    case 14:
    case 15:
        note = 'C';    
        break;

    case 16:
    case 17:
    case 18:
        note = 'B';    
        break;

    case 19:
    case 20:
        note = 'A';    
        break;
    
    default:
        break;
    }

    return note;
}
