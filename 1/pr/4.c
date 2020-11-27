#include <stdio.h>

int square(int n) { return n * n; }
int cube(int n) { return n * n * n; }

int main () {
	
	int number;
	printf("Enter a number:");
	scanf("%d", &number);

	if (number % 2 == 0)
		printf("%d", square(number));
	else 
		printf("%d", cube(number));

	return 0;
}
