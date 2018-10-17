#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sortSelection(int array[], int length)
{
	int min = 0;
	for (int j = 0; j < length; ++j)
	{
		for (int i = j; i < length; ++i)
		{
			if (array[i] < array[min])
			{
				min = i;
			}
		}
		int templ = array[j];
		array[j] = array[min];
		array[min] = templ;
		min = j + 1;
	}
}

void menu()
{
	printf("%s", "Enter array: \n");
	int const length = 10;
	int array[length]{};
	for (int i = 0; i < length; i++)
	{
		scanf("%i", &array[i]);
	}
	sortSelection(array, length);
	printf("%s", "Output sort array: \n");
	for (int i = 0; i < length; i++)
	{
		printf("%i ", array[i]);
	}
	scanf("%i", &array[0]);
}

bool testing()
{
	int const length = 10;
	int array1[length]{ 9, 8, 3, 4, 2, -2, 4, 0, 1, 5 };
	int result1[length]{ -2, 0, 1, 2, 3, 4, 4, 5, 8, 9 };
	for (int i = 0; i < length; ++i)
	{
		if (array1[i] != result1[i])
		{
			return false;
		}
	}

	int array2[length]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int result2[length]{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < length; ++i)
	{
		if (array2[i] != result2[i])
		{
			return false;
		}
	}

	return true;
}

int main() {
	if (testing)
	{
		printf("%s", "Testing is positive!\n");
	}
	else
	{
		printf("%s", "Testing is negative!\n");
		return 0;
	}
	menu();
	return 0;
}