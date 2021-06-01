/*
Entrada
Ingresar un numero entero con un maximo de 6 digitos
Proceso
Cada dígito  del número ingresado,  se sumará los pares con los pares  y los impares con impares, hasta evaluar si la suma de ambas es equivalente o no.
Salida
Se mostrará en pantalla si la suma de los dígitos pares  es igual a la suma de los números impares o de lo contrario, no son iguales.
 */

#include <stdio.h>


int main()
{

int num, digito=0, impar=0;

    printf("Ingresa un numero entero (maximo 6 digitos): \n");
    scanf("%d", &num);

 while ( num !=0)
    {


        if ((num %10) %2 == 0 )
        {
            digito += num % 10;
        }else if ((num %10) %2 != 0 ){
            impar+= num % 10;
        }

        num = num / 10;
    }
    printf(" \n La Suma de los digitos pares es igual a : %d \n",digito);
    printf(" \n La Suma de los digitos impares es igual a : %d \n",impar);

    if(digito == impar)
    {
        printf(" La suma de los numeros pares e impares son iguales");

    }else{

        printf(" La suma de los numeros pares e impares no son iguales");
    }

return 0;
}
