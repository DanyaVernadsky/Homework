#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>

int degreeSimple(int n, int degree)
{
	if (degree == 0 && n == 0)
	{
		return INT_MAX;
	}
	int result = 1;
	for (int i = 0; i < degree; ++i)
	{
		result = result * n;
	}
	if (degree < 0)
	{
		return (1 / result);
	}
	else
	{
		return result;
	}
}

int degreeComplicated(int n, int degree)
{
	if (degree == 0 && n == 0)
	{
		return INT_MAX;
	}
	else
	{
		if (degree == 0)
		{
			return 1;
		}
	}
	if (degree % 2 == 1)
	{
		return degreeComplicated(n, degree - 1) * n;
	}
	else
	{
		{
			int result = degreeComplicated(n, degree / 2);
			return result * result;
		}
	}
}

bool testing()
{
	const int n = 5;
	int arrayNumber[n]{ 2, 0, 1, 3, 5 };
	int arrayDegree[n]{ 5, 0, 100, 4, 10 };
	int arrayResult[n]{ 32, INT_MAX, 1, 81, 9765625 };
	for (int i = 0; i < n; ++i)
	{
		if (degreeComplicated(arrayNumber[i], arrayDegree[i]) != arrayResult[i])
		{
			return false;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (degreeSimple(arrayNumber[i], arrayDegree[i]) != arrayResult[i])
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
	}

	printf("%s", "Enter integer number and integer degree: ");
	int n = 0;
	int degree = 0;
	scanf("%i%i", &n, &degree);

	double resultDegreeSimple = degreeSimple(n, degree);
	if (resultDegreeSimple == INT_MAX)
	{
		printf("%s\n", "Undetermained");
	}
	else
	{
		printf("%i\n", degreeSimple(n, degree));
	}

	double resultDegreeComplicated = degreeComplicated(n, degree);
	if (resultDegreeComplicated == INT_MAX)
	{
		printf("%s\n", "Undetermained");
	}
	else
	{
		printf("%i\n", degreeComplicated(n, degree));
	}
	scanf("%i", &n);
	return 0;
}