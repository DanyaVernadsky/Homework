#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int searchMax—omb(int array[], int length)
{
	int maxComb = 0;
	int result = 0;
	int* array2 = new int[length] {};
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length - i; ++j)
		{
			if ((array[j] == array[i])&&(array[j] != _CRT_INT_MAX))
			{
				int valueSecondArray = ++array2[i];
				if (maxComb < valueSecondArray)
				{
					maxComb = valueSecondArray;
					result = i;
				}
			}
		}
		array[i] = _CRT_INT_MAX;
	}
	return array[result];
}


int main() {
	const int n = 10;
	int array[n]{ 3, 2, 5, 3, 1, 0, -1, 2, 5, 5 };
	printf("%i", searchMax—omb(array, 10));
	scanf("%i", &n);
	return 0;
}