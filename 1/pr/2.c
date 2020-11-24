#include <stdio.h>
#include <math.h>

float discrim;

float ecuacion(float a, float b, float c) {
	discrim=((b*b)-(4*a*c));
	if (discrim<=0) return 0;
	else return discrim;
}

int main() {
	float a = 0, b = 0, c = 0;
	printf("Vamos a resolver una ecuacion del tipo ax^2+bx+c=0");
	printf("\n introduce el valor de a");
	scanf("%f", &a);
	printf("\n introduce el valor de b");
	scanf("%f", &b);
	printf("\n introduce el valor de c");
	scanf("%f", &c);

	if (ecuacion(a,b,c)==0) {
		printf("La ecuacion no tiene solucion");
	}
	if (ecuacion(a,b,c)!=0) {
		float num1, num2;
		float den;
		float solucion1, solucion2;

		num1 = (-b + sqrt(discrim));
		num2 = (-b + sqrt(discrim));

		den = 2*a;

		solucion1 = num1/den;
		solucion2 = num2/den;

		printf("\n La primera solucion es %f", solucion1);
		printf("\n La segunda solucion es %f", solucion2);
		printf("\n");

	}

	return 0;
}
