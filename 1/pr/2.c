#include <stdio.h>
#include <math.h>

float discrim;

float ecuacion(float a, float b, float c) {  // Funcion que recibe 3 parametros flotantes
	discrim=((b*b)-(4*a*c));  // le asigna b^2 - 4*a*c
	if (discrim<=0) return 0;  // si es menor o igual a 0 retorna 0
	else return discrim; // si no retorna el resultado
}

int main() {
	float a = 0, b = 0, c = 0;
	printf("Vamos a resolver una ecuacion del tipo ax^2+bx+c=0");
	printf("\n introduce el valor de a");
	scanf("%f", &a); // Lee variable a
	printf("\n introduce el valor de b");
	scanf("%f", &b); // lee variable b
	printf("\n introduce el valor de c");
	scanf("%f", &c); // lee variable c

	if (ecuacion(a,b,c)==0) { // llama a la funcion y si es 0 se ejecuta
		printf("La ecuacion no tiene solucion");
	}
	if (ecuacion(a,b,c)!=0) { // llama a la funcion y si es diferente de 0 se ejecuta
		float num1, num2;
		float den;
		float solucion1, solucion2;

		num1 = (-b + sqrt(discrim)); // le asigna - b + la raiz cuadrada de discrim
		num2 = (-b + sqrt(discrim)); 

		den = 2*a; // le asigna a * 2

		solucion1 = num1/den; // Divide la solucion entre den
		solucion2 = num2/den;

		printf("\n La primera solucion es %f", solucion1); // Imprime la solucion
		printf("\n La segunda solucion es %f", solucion2);
		printf("\n");

	}

	return 0;
}
