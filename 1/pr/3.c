#include <stdio.h> // Inventado
#include <math.h>

int GetInt(float number); 

int main() {
	
	float Number;
	printf("Introduce un numero \n");
	scanf("%f", &Number);

	int ToInt = GetInt(Number);
	printf("%d", ToInt);

	return 0;
}

int GetInt(float number) {
	return fabs(number);
}
