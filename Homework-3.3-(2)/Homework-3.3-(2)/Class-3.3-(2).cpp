#include <stdio.h>
#include <stdlib.h>

// ������� ���������� ���������� ��������
void mergeSort(int *a, int l, int r)
{
	if (l == r) return; // ������� ����������
	int mid = (l + r) / 2; // ���������� �������� ������������������
						   // � ���������� �������� ������� ���������� ��� ������ ��������
	mergeSort(a, l, mid);
	mergeSort(a, mid + 1, r);
	int i = l;  // ������ ������� ����
	int j = mid + 1; // ������ ������� ����
	int *tmp = (int*)malloc(r * sizeof(int)); // �������������� ������
	for (int step = 0; step < r - l + 1; step++) // ��� ���� ��������� ��������������� �������
	{
		// ���������� � ����������� ������������������ ������� �� ��������� ���� �����
		// ��� ������� ������� ���� ���� j > r
		if ((j > r) || ((i <= mid) && (a[i] < a[j])))
		{
			tmp[step] = a[i];
			i++;
		}
		else
		{
			tmp[step] = a[j];
			j++;
		}
	}
	// ������������ �������������� ������������������ � �������� ������
	for (int step = 0; step < r - l + 1; step++)
	{
		a[l + step] = tmp[step];
	}
}

int searchMaxInSortArray(int array[], int length)
{
	int	count = 0;
	int max = 0;
	int templ = 0;
	for (int i = 0; i < length - 1; i++)
	{
		if (array[i] == array[i + 1])
		{
			count++;
			if (count > max)
			{
				templ = i;
				max++;
			}
			
		}
		else
		{
			count = 0;
		}
	}
	return array[templ];
}

bool testing()
{
	const int n = 10;
	const int m = 30;
	int array1[n]{ 1, 5, 3, 4, 4, 1, 0, 4, 5, 7 };
	int result1 = 4;
	mergeSort(array1, 0, n - 1);
	int resultProgram = searchMaxInSortArray(array1, n);
	if (result1 != resultProgram)
	{
		printf("%i ", resultProgram);
		return false;
	}

	int result2 = 4;
	int array2[m]{ 1, 5, 3, 4, 4, 1, 0, 4, 5, 7,
		1, 5, 3, 4, 4, 1, 0, 10, 5, 7,
		1, 0, 3, -2, 4, 1, 0, 4, 5, 7 };
	mergeSort(array2, 0, m - 1);
	resultProgram = searchMaxInSortArray(array2, m);
	if (result2 != resultProgram)
	{
		printf("%i ", resultProgram);
		return false;
	}

	const int q = 5;
	int result3 = 1;
	int array3[q]{ 1, 2, 3, 4, 5 };
	mergeSort(array3, 0, q - 1);
	resultProgram = searchMaxInSortArray(array3, q);
	if (result3 != resultProgram)
	{
		printf("%i ", resultProgram);
		return false;
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
		return 0;
	}

	int const length = 60;
	int array[length];
	for (int i = 0; i < length; i++)
	{
		array[i] = (rand() % 100);
		printf("%d ", array[i]);
	}
	mergeSort(array, 0, length - 1);
	printf("\n");

	// ������� ��������������� ������
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	// ���������
	printf("%i", searchMaxInSortArray(array, length));
	getchar();
	return 0;
}