#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>

void randomArray(int array[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		array[i] = rand() % 100;
	}
}

void algoritm(int array[], int length)
{
	if (length != 1) 
	{

		int const example = array[0];
		int i = 1;
		int j = length - 1;
		while (i <= j)
		{
			while (array[i] < example)
			{
				i++;
			}
			while (array[j] >= example)
			{
				j--;
			}
			if (i <= j)
			{
				int const pattern = array[i];
				array[i] = array[j];
				array[j] = pattern;
				i++;
				j--;
			}
		}
	}
}

bool testing()
{
	int const n = 10;
	int array[n]{ 4, 5, 3, 2, 7, 8, 2, 1, 0, 4 };
	int result[n]{ 4, 0, 3, 2, 1, 2, 8, 7, 5, 4 };
	algoritm(array, n);
	for (int i = 0; i < n; ++i)
	{
		if (array[i] != result[i])
		{
			return false;
		}
	}

	int array1[1]{ 5 };
	int result1[1]{ 5 };
	algoritm(array1, 1);
	return (array[0] == result[0]);
}

int main()
{
	const int n = 10;
	int array[n]{4, 5, 3, 2, 7, 8, 2, 1, 0, 4};
	if (testing())
	{
		printf("Testing is positive! :)\n");
	}
	else
	{
		printf("Testing is negative! :(\n");
	}
	randomArray(array, n);

	printf("Output random array\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%i ", array[i]);
	}
	printf("\n");

	printf("Output sort array\n");
	algoritm(array, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%i ", array[i]);
	}
	scanf("%i", n);
	return 0;
}