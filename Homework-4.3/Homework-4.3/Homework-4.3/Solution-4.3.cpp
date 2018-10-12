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

void addInfo(int &countAccount)
{
	printf("%s", "Введите кол-во записей: \n");
	int k = 0;
	scanf("%i", &k);	
	for (int i = countAccount; i < k + countAccount; ++i) {
		printf("%s", "Введите номер телефона владельца: \n");
		scanf("%i", &person[i].number);
		printf("%s", "Введите Имя: \n");
		scanf("%s", &person[i].name);
	}
	countAccount += k;
}

void searchName(char name[], int &countAccount)
{
	for (int i = 0; i < countAccount; ++i)
	{
		if (strcmp(name, person[i].name) == 0) 
		{
			printf("%s\n", person[i].number);
		}
		else
		{
			printf("%s", "Не найдено совпадения \n");
		}
	}
}

void searchNumber(__int64 number, int &countAccount)
{
	for (int i = 0; i < countAccount; ++i) 
	{
		if (person[i].number == number) 
		{
			printf("%u", person[i].number);
		}
		else
		{
			printf("%s", "Не найдено совпадения \n");
		}
	}
}

void printAll(FILE *myfile)
{
	printf("%s", "Имя    ");
	printf("%s", "Номер\n");
	int i = 0;
	while (fscanf(myfile, "%s%u", (person[i].name), &(person[i].number)) != EOF) 
	{
		printf("%s %u", person[i].name, person[i].number);
		i++;
	}

}

void saveData()
{

}

void menu()
{
	FILE *myfile;
	myfile = fopen("directory.txt", "a+");
	int decision = 1;
	int countAccount = 0;
	while (decision != 0)
	{
		printf("%s", "Введите операцию:");
		scanf("%i", &decision);
		switch (decision) {
		case 0:
			decision = 0;
			break;
		case 1:
		{
			addInfo(countAccount);
			break;
		}
		case 2:
		{
			printAll(myfile);
			break;
		}
		case 3:
		{
			printf("%s", "Введите имя: ");
			char name[30];
			scanf("%s", &name);
			searchName(name, countAccount);
			break;
		}
		case 4:
		{
			printf("%s", "Введите номер абонента: ");
			__int64 number = 0;
			scanf("%u", &number);
			searchNumber(number, countAccount);
			break;
		}
		case 5:
		{
			saveData();
			break;
		}
		default :
			break;
		}
	}
	fclose(myfile);
}


int main()
{
	setlocale(LC_ALL, "rus");
	printf("%s", "Выберите требуемое действие : \n0 - Выйти ...\n1 - Добавить запись (имя и телефон) ...\n");
	printf("%s", "2 - Распечатать все имеющиеся записи ...\n3 - Найти телефон по имени ...\n");
	printf("%s", "4 - Найти имя по телефону ...\n5 - Сохранить текущие данные в файл  ...\n");

	int countAccount = 0;
	menu();
	printf("%s", "Конец!");
	int m = 0;
	scanf("%i", &m);
	return 0;
}