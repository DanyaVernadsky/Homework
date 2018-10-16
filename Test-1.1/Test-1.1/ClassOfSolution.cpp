#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void summ(bool binaryNumber1[], bool binaryNumber2[], bool result[], int n)
{
	
	for (int i = n - 1; i >= 0; i--)
	{
		if (binaryNumber1[i] + binaryNumber2[i] + result[i + 1] == 2)
		{
			result[i + 1] = false;
			result[i]++;
		}
		else
		{
			if (binaryNumber1[i] + binaryNumber2[i] + result[i + 1] == 3)
			{
				result[i + 1] = true;
				result[i]++;
			}
			else
			{
				if (binaryNumber1[i] + binaryNumber2[i] + result[i + 1] == 1)
				{
					result[i + 1] = true;
				}
			}
		}
		
	}
}

int main() {
	const int n = 10;
	bool binaryNumber1[n]{ 1, 1, 0, 0, 0, 1, 0, 0, 1, 1 };
	bool binaryNumber2[n]{ 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 };
	bool *result = new bool[n + 1]{};
	summ(binaryNumber1, binaryNumber2, result, n);
	for (int i = 0; i <= n ; i++)
	{
		printf("%i", result[i]);
	}
	int k = 0;
	scanf("%i", &k);
	return 0;
}