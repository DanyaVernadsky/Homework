#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void insertSort(int array[], int left, int right)
{
	for (int i = left; i < right; ++i)
	{
		int key = i + 1;
		int const templ = array[key];
		for (int j = i + 1; j > 0; --j)
		{
			if (templ < array[j - 1])
			{
				array[j] = array[j - 1];
				key = j - 1;
			}
		}
		array[key] = templ;
	}
}

void quickSort(int array[], int left, int right)
{
	int i = left;
	int j = right;

	if (left < j)
	{
		if (left - j >= 10)
		{
			quickSort(array, left, j);
		}
		else
		{
			insertSort(array, left, j);
		}
	}

	if (i < right) 
	{
		if (i - right >= 10)
		{
			quickSort(array, i, right);
		}
		else
		{
			insertSort(array, i, right);
		}
	}


	int pivot = array[(left + right) / 2];
	while (i <= j)
	{
		while (array[i] < pivot)
		{
			i++;
		}
		while (array[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			int const templ = array[i];
			array[i] = array[j];
			array[j] = templ;
			i++;
			j--;
		}
	}
}

bool testing()
{
	const int n = 10;
	int array[n]{ 1, 5, 3, -2, 4, 1, 0, 4, 5, 7 };
	int array1[n]{ 1, 5, 3, -2, 4, 1, 0, 4, 5, 7 };
	int result[n]{-2, 0, 1, 1, 3, 4, 4, 5, 5, 7};
	quickSort(array, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		if (array[i] != result[i])
		{
			return false;
		}
	}
	insertSort(array1, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		if (array1[i] != result[i])
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
		printf("%s\n", "Testing is positive");
	}
	else
	{
		printf("%s\n", "Testing is negative");
	}
	printf("%s", "Enter length of array: ");
	int n = 0;
	scanf("%i", &n);
	int* array = new int[n];
	printf("%s", "Enter array: ");
	for (int i = 0; i < n; ++i)
	{
		scanf("%i", &array[i]);
	}
	insertSort(array, 0, n - 1);
	printf("%s\n", "Result of sorting");
	for (int i = 0; i < n; ++i)
	{
		printf("%i ", array[i]);
	}
	delete []array;
	scanf("%i", &n);
	return 0;
}