#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Operation(char type, int firstNumber, int secondNumber);

void handlerErr(char type) {
    fprintf(stderr, "Cannot execute this function with character %c \n", type);
    exit(EXIT_FAILURE);
}


int main(int argc, char const *argv[])
{
    int firstNumber, secondNumber;
    printf("Ingresa 2 numeros: \n");
    scanf("%d %d", &firstNumber, &secondNumber);

    char type;
    printf("Ingresa un caracter\n suma: + \n resta: - \n multiplicacion: * \n division: / \n potencia: ^ \n");
    scanf(" %c", &type);

    int res = Operation(type, firstNumber, secondNumber);
    printf("El resultado es: %d\n", res);

    return 0;
}

int Operation(char type, int firstNumber, int secondNumber) {
    int res = 0;

    switch (type)
    {
    case '+':
        res = firstNumber + secondNumber;
        break;
    
    case '-':
        res = firstNumber - secondNumber;
        break;

    case '/':
        res = firstNumber / secondNumber;
        break;

    case '*':
        res = firstNumber * secondNumber;
        break;
    
    case '^':
        res = (int) pow(firstNumber, secondNumber);
        break;
        
    default:
        handlerErr(type);
    }

    return res;
}