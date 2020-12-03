#include <stdio.h>

<<<<<<< HEAD

int main() {

	int x = 0;
	int a = 1, s = 1, b = 1;
	do {

		printf("%d \n", s);
		a = b;
		b = s;
		s = a + b;
		++x;

	} while(x <= 10);
=======
int main(int argc, char **argv) {

	int number, number2;
	printf("Number of iterations ");
	scanf("%d", &number);

	printf("Number of multiplications ");
	scanf("%d", &number2);

	for (int i = 1; i <= number; i++) {
		printf("%d x %d = %d \n", number2, i, number2 * i);
	}
>>>>>>> 071b89bd714db213c92b2d2265608c3a617e5b3d

	return 0;
}
