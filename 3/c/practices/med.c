#include <stdio.h>
#include <stdlib.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int main(int argc, char const *argv[])
{
	
	int numbers[] = {5,2,1,4,3,6,7};
	int size = NELEMS(numbers);

	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++)
		{
			if (numbers[i] > numbers[j])
			{
				int newNumber = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = newNumber;
			}
			
		}		
	}

	int mid = size / 2;

	if (mid % 2 == 1)
	{
		printf("Middle %d \n", numbers[mid]);
	} else {
		printf("Middle %d \n", numbers[(numbers[mid -1] + numbers[mid + 2]) / 2]);
	}

	return 0;
}
