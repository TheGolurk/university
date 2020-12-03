#include <stdio.h>


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

	return 0;
}
