#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <cstdlib>

int const quantity = 100;
struct library
{
	__int64 number;
	char name[30];
} person[quantity];

void addInfo()
{
	printf("%s", "������� ���-�� �������: \n");
	int k = 0;
	scanf("%i", &k);
	for (int i = 0; i < k; ++i) {
		printf("%s", "������� �����: \n");
		scanf("%i", &person[k].number);
		printf("%s", "������� ���: \n");
		scanf("%i", &person[k].name);
	}
}

void searchName(char name[])
{
	for (int i = 0; i < quantity; ++i) 
	{
		if (strcmp(name, person[i].name) == 0) 
		{
			printf("%s\n", person[i].name);
		}
		else
		{
			printf("%s", "�� ������� ���������� \n");
		}
	}
}

void searchNumber(__int64 number)
{
	for (int i = 0; i < quantity; ++i) 
	{
		if (person[i].number == number) 
		{
			printf("%i\n", person[i].number);
		}
		else
		{
			printf("%s", "�� ������� ���������� \n");
		}
	}
}

void printAll()
{
	printf("%s", "���    ");
	printf("%s%s", "�����\n");
	for (int i = 0; i < quantity; ++i)
	{
		printf("%s", "person[i].name  ");
		printf("%__int64", person[i].number, "\n");
	}
}

void menu()
{
	int decision = 1;
	while (decision != 0)
	{
		printf("%s", "������� �����:");
		scanf("%i", &decision);
		switch (decision) {
		case 0:
			decision = 0;
			break;
		case 1:
			addInfo();
			break;
		case 2:
			printAll();
			break;
		case 3:
			printf("%s", "������� ���: ");
			char name[50];
			scanf("%s", name);
			searchName(name);
			break;
		case 4:

			break;
		default :
			break;
		}
		scanf("%i", &decision);
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	printf("%s", "�������� ��������� �������� : \n0 - ����� ...\n1 - �������� ������ (��� � �������) ...\n");
	printf("%s", "2 - ����������� ��� ��������� ������ ...\n3 - ����� ������� �� ����� ...\n");
	printf("%s", "4 - ����� ��� �� �������� ...\n5 - ��������� ������� ������ � ����  ...\n");
	
	menu();

	printf("%s", "�����!");
	int m = 0;
	scanf("%i", &m);
	return 0;
}