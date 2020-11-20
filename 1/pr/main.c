#include <stdio.h>

void printLine();
void printFirstHeader();
void printSubHeader();
void printBody();
void printSubLine();
int printNumbers(int actual);

int main()
{

	printLine();
	printFirstHeader();
	printLine();
	printSubHeader();
	printLine();
	printBody();
	printLine();

	return 0;
}

void printLine()
{
	printf("|");
	for (int i = 1; i <= 21; i++)
	{
		printf("-");
	}
	printf("|\n");
}

void printFirstHeader()
{
	printf("|Propiedad de ABCDEFGH|\n");
}

void printSubHeader()
{
	printf("| Calculadora \"Casio\" |\n");
}

void printBody()
{
	int number = 1;
	for (int i = 1; i <= 11; i++)
	{
		printf("|");
		if (i == 2 || i == 4 || i == 5 || i == 7 || i == 8 || i == 10)
		{
			printSubLine();
		}
		else if (i == 3 || i == 6 || i == 9)
		{
			number = printNumbers(number);
		}
		else
		{
			for (int j = 1; j <= 21; j++)
			{
				printf(" ");
			}
			printf("|\n");
		}
	}
}

void printSubLine()
{
	for (int i = 1; i <= 22; i++)
	{
		if (i < 5 || i > 19)
		{
			printf(" ");
		}
		if (i == 5 || i == 10 || i == 14 || i == 19)
		{
			printf("|");
		}
		else if ((i > 5 && i < 10) || (i > 10 && i < 14) || (i > 15 && i < 19))
		{
			printf("-");
		}
	}
	printf("|\n");
}

int printNumbers(int actual)
{
	for (int i = 1; i <= 22; i++)
	{
		if (i < 5 || i > 19)
		{
			printf(" ");
		}
		if (i == 5 || i == 10 || i == 14 || i == 19)
		{
			printf("|");
		}
		else if ((i > 5 && i < 10) || (i > 10 && i < 14) || (i > 15 && i < 19))
		{
			if (i == 8 || i == 12 || i == 16)
			{
				printf("%d", actual);
				actual++;
			}
			else
			{
				printf(" ");
			}
		}
	}
	printf("|\n");

	return actual;
}
