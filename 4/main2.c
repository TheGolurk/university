#include<stdio.h>
#include<stdlib.h>

int main() {

	int iii = 1;
	while(iii == 1) {
		int numero = (rand() % (2 - 1 + 1) + 1);
		printf("%d \n", numero);
	}

	return 0;
}
