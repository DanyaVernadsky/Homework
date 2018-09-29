#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>

void randomArray(int array[], int length) 
{
	for (int i = 0; i < length ; i++)
	{
		array[i] = rand();
	
	}
}

void algoritm(int array[], int length)
{
	if (length != 1) {

		int example = array[0];
		int i = 1;
		int j = length - 1;
		for (int q = 0; q < length / 2; ++q)
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
				int zz = array[i];
				array[i] = array[j];
				array[j] = zz;
				i++;
				j--;
			}
		}
	}
}


int main() 
{
	const int n = 10;
	int array[n]{};
	randomArray(array, n);
	printf("%s\n", "Output sort array");
	algoritm(array, n);
	for (int i = 0; i < n; i++)
	{
		printf("%i ", array[i]);
	}
	scanf("%i", n);
	return 0;
}