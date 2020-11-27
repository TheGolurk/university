#include <stdio.h>

int main () {

	int age;
	printf("Cual es tu edad? ");
	scanf("%d", &age);

	if (age >= 18)
		printf("Mayor de edad");
	else
		printf("Menor de edad");

	return 0;
}
