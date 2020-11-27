#include <stdio.h>

int main() {

	int hour;
	printf("Que hora es? ");
	scanf("%d", &hour);

	if (hour > 19)
		printf("Ya es tarde");
	else
		printf("Es temprano");

	return 0;
}
