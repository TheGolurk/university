#include <stdio.h>

int main(int argc, char **argv) {

	int number, number2;
	printf("Number of iterations ");
	scanf("%d", &number);

	printf("Number of multiplications ");
	scanf("%d", &number2);

	for (int i = 1; i <= number; i++) {
		printf("%d x %d = %d \n", number2, i, number2 * i);
	}

	return 0;
}
