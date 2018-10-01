#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>

void bubbleSort(int array[], int length)
{

	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				int const c = array[j];
				array[j] = array[j + 1];
				array[j + 1] = c;
			}
		}
	}
}

void counterSort(int array[], int length)
{
	int max = array[0];
	int min = array[0];
	for (int i = 1; i < length; ++i) // search max
	{
		if (array[i] > max)
		{
			max = array[i];
		}
		if (array[i] < min)
		{
			min = array[i];
		}
	}

	int length1 = max - min + 1;
	int *arrayCount = new int[length1] {}; //fill 2-nd array
	for (int i = 0; i < length; ++i)
	{
		arrayCount[array[i] - min]++;
	}

	for (int i = 0; i < length; ++i)
	{
		array[i] = 0;
	}
	int number = 0;
	for (int i = 0; i < length1; ++i)
	{
		while (arrayCount[i] != 0)
		{
			arrayCount[i]--;
			array[number] = i + min;
			number++;
		}
	}
	delete []arrayCount;
}

bool testing()
{
	const int n = 5;
	int array1[n]{ -1, 2, 3 , 0, -2 };
	int array2[n]{ -1, 2, 3 , 0, -2 };
	int arrayResult[n]{ -2, -1, 0, 2, 3 };
	bubbleSort(array1, n);
	for (int i = 0; i < n; ++i)
	{
		if (array1[i] != arrayResult[i])
		{
			return false;
		}
	}

	counterSort(array2, n);
	for (int i = 0; i < n; ++i)
	{
		if (array2[i] != arrayResult[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	if (testing())
	{
		printf("%s\n", "Test is positive");
	}
	else
	{
		printf("%s\n", "Test is negative");
		return 0;
	}
	const int n = 10;
	int array[n]{ 1, 4, 2, 6, 3, 8, 6, 3, 2, 8 };

	bubbleSort(array, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%i ", array[i]);
	}

	printf("\n");
	int array1[n]{ 1, 4, 2, 6, 3, 8, 6, 3, 2, 8 };
	counterSort(array, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%i ", array[i]);
	}

	scanf("%i", &n);
	return 0;
}