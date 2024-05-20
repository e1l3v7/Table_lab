#include "interface.h"
#include <stdio.h>

void Start()
{
	printf("1. Создать таблицу\n");
	printf("2. Добавить элемент\n");
	printf("3. Удалить элемент\n");
	printf("4. Поиск элемента\n");
	printf("5. Вывести таблицу\n");
	printf("6. Выход\n");
	int command;
	int fl=Scanf(&command);
	if(fl == 0)
	{
		return;
	}
	Table* table=NULL;
	while(command != 6)
	{
		if(command == 1)
		{
			printf("Введите размер таблицы\n");
			int tsize;
			fl=Scanf(&tsize);
			if(fl == 0)
			{
				return;
			}
			table = CreateTable(tsize);
		}
		else if(command == 2)
		{
			printf("Введите key\n");
			unsigned int key;
			fl=Scanf(&key);
			if(fl == 0)
			{
				return;
			}
			printf("Введите parent\n");
			unsigned int par;
			fl=Scanf(&par);
			if(fl == 0)
			{
				return;
			}
			printf("Введите info\n");
			unsigned int* info = (unsigned int*)malloc(sizeof(unsigned int));
			fl=Scanf(info);
			if(fl == 0)
			{
				return;
			}
			int flag = Insert(table, key, par, info);
			if(flag == 0)
			{
				printf("Повторите ввод\n");
			}
		}
		else if(command == 3)
		{
			printf("Введите key\n");
			unsigned int key;
			fl=Scanf(&key);
			if(fl == 0)
			{
				return;
			}
			printf("Введите parent\n");
			unsigned int par;
			fl=Scanf(&par);
			if(fl == 0)
			{
				return;
			}
			int flag = Delete(table, key, par);
			if(flag == 0)
			{
				printf("Повторите ввод\n");
			}
		}
		else if(command == 4)
		{
			printf("Введите key\n");
			unsigned int key;
			fl=Scanf(&key);
			if(fl == 0)
			{
				return;
			}
			Table* t = Search(table, key);
			if(t == NULL)
			{
				printf("Повторите ввод\n");
			}
			else
			{
				PrintTable(t);
			}
		}
		else if(command == 5)
		{
			PrintTable(table);
		}
		else
		{
			printf("Неверный ввод\n");
			printf("Повторите ввод\n");
		}
		printf("\n\n");
		printf("1. Создать таблицу\n");
		printf("2. Добавить элемент\n");
		printf("3. Удалить элемент\n");
		printf("4. Поиск элемента\n");
		printf("5. Вывести таблицу\n");
		printf("6. Выход\n");
		fl=Scanf(&command);
		if(fl == 0)
		{
			return;
		}
	}
	FreeTable(table);
}
