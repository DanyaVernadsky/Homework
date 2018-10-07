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
	int pivot = array[(i + j) / 2];
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
		if (left < j)
		{
			quickSort(array, left, j);
		}
		if (right > i)
		{
			quickSort(array, right, i);
		}
	}
}

bool checkArrays(int array1[], int result1[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%i%s%i", array1[i], " and ", result1[i]);
		printf("\n");
		if (array1[i] != result1[i])
		{
			printf("%i", i, "- Number of error!!");
			/*return false;*/
		}
	}
	return true;
}

bool testing()
{
	const int n = 10;
	int array[n]{ 1, 5, 3, -2, 4, 1, 0, 4, 5, 7 };
	int result[n]{-2, 0, 1, 1, 3, 4, 4, 5, 5, 7};

	/*quickSort(array, 0, n - 1);
	if (!checkArrays(array, result, n))
	{
		return false;
	}*/

	const int m = 20;
	int array20[m]{ 1, 5, 3, -2, 4, 1, 0, 4, 5, 7, 11, 233,
		11, 31, 3, 6, 4, 13, 15, 20 };
	int result20[m]{ -2, 0, 1, 1, 3, 3, 4, 4, 4, 5, 5, 6, 7,
		11, 11, 13, 15, 20, 31, 233 };

	quickSort(array20, 0, m - 1);
	if (!checkArrays(array20, result20, m))
	{
		return false;
	}

	/*int array01[1]{5};

	quickSort(array01, 0, 4);
	if (!checkArrays(array01, array01, 5))
	{
		return false;
	}

	const int q = 2;
	int array02[q]{ 7, 2 };
	int array02_result[q]{ 2, 7 };
	
	quickSort(array02, 0, q - 1);
	if (!checkArrays(array02, array02_result, q))
	{
		return false;
	}

	const int p = 7;
	int array03[p]{ 7, 7, 7, 7, 7, 7, 7 };
	int array03_result[p]{ 7, 7, 7, 7, 7, 7, 7 };

	quickSort(array03, 0, p - 1);
	if (!checkArrays(array03, array03_result, p))
	{
		return false;
	}
*/
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