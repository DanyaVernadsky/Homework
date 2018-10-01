#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int searchMax—omb(int array[], int length)
{
	int maxComb = 0;
	int result = 0;
	for (int i = 0; i < length; ++i)
	{
		int count = 0;
		for (int j = i + 1; j < length; ++j)
		{//œÓÏÂ˜‡˛ Ï‡ÍÒËÏÛÏÓÏ ˝Î-Ú˚ ÍÓÚÓ˚Â ÛÊÂ ÔÓÒ˜ËÚ‡Î
			if ((array[i] == array[j])&&(array[j] != _CRT_INT_MAX))
			{
				count++;
				if (maxComb < count)
				{
					maxComb = count;
					result = i;
					array[j] = _CRT_INT_MAX;
				}
			}
		}
	}
	return array[result];
}

bool testing()
{
	const int n = 10;
	int array[n]{ 1, 5, 3, 4, 4, 1, 0, 4, 5, 7 };
	int result = 4;
	if (result != searchMax—omb(array, n))
	{
		return false;
	}
	return true;
}

int main() {
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
	printf("%s", "Result: ");
	printf("%i", searchMax—omb(array, 10));
	scanf("%i", &n);
	return 0;
}