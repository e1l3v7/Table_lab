#include "table.h"
#include <stdio.h>

Table* CreateTable(int msize)
{
	Table* t = NULL;
	t = (Table*)malloc(sizeof(Table));
	if(t != NULL)
	{
		t->ks = (KeySpace**)malloc(msize*sizeof(KeySpace*));
		if(t->ks != NULL)
		{
			t->msize = msize;
			t->csize = 0;
			return t;
		}
		else
		{
			printf("ошибка: не удалось выделить память для KeySpace*\n");
			return NULL;
		}
	}
	else
	{
		printf("ошибка: не удалось выделить память для Table\n");
		return NULL;
	}
}

int Insert(Table** t, unsigned int key, unsigned int* info)
{
	if(*t == NULL)
	{
		printf("ошибка: передан NULL\n");
		return 0;
	}
	else
	{
		if((*t)->csize < (*t)->msize)
		{
			KeySpace* ks = NULL;
			ks = CreateKeySpace(key,(*t)->ks[(*t)->csize-1].key, info);
			if(ks == NULL)
			{
				return 0;
			}
			else
			{
				(*t)->ks[(*t)->csize] = *ks;
				(*t)->csize += 1;
				return 1;
			}
		}
		else
		{
			printf("ошибка: таблица полна\n");
			return 0;
		}
	}
}

int Delete(Table** t, unsigned int key, unsigned int par)
{
	if(*t == NULL)
	{
		printf("ошибка: передан NULL\n");
		return 0;
	}
	else
	{
		if((*t)->csize > 0)
		{
			int co = 0;
			for(size_t i = 0; i < (*t)->csize; i++)
			{
				if((*t)->ks[i].par == par && (*t)->ks[i].key == key)
				{
					co += 1;
					break;
				}
			}
			if(co == 1)
			{
				for(size_t i = 0; i < (*t)->csize; i++)
				{
					
					if((*t)->ks[i].par == par && (*t)->ks[i].key == key)
					{
						int flag = FreeKeySpace(&((*t)->ks[i]));
						if(flag == 0)
						{
							return 0;
						}
						else
						{
							(*t)->csize -= 1;
							return 1;
						}
						break;
					}
				}
			}
			else if(co == 0)
			{
				printf("ошибка: такого сочетания key-par нет в таблицe\n");
				return 0;
			}
			else
			{
				printf("ошибка: несколько таких сочетаний key-par в таблицe\n");
				return 0;
			}
		}
		else
		{
			printf("ошибка: таблица пуста\n");
			return 0;
		}
	}
	return 0;
}

Table* Search(Table* t, unsigned int key)
{
	if(t == NULL)
	{
		printf("ошибка: передан NULL\n");
		return NULL;
	}
	else
	{
		if(t->csize == 0)
		{
			printf("ошибка: таблица пуста\n");
			return NULL;
		}
		else
		{
			int size;
			for(size_t i = 0; i < t->csize; i++)
			{
				if(t->ks[i].key == key)
				{
					size += 1;
				}
			}
			if(size == 0)
			{
				printf("ошибка: такого элемента нет в таблице\n");
				return NULL;
			}
			else
			{
				Table* t1 = NULL;
				t1 = CreateTable(size);
				if(t1 == NULL)
				{
					return NULL;
				}
				else
				{
					for(size_t i = 0; i < t->csize; i++)
					{
						if(t->ks[i].key == key)
						{
							int flag = Insert(&t1, t->ks[i].key, t->ks[i].info);
							if(flag == 0)
							{
								return NULL;
							}
						}
					}
					return t1;
				}
			}
		}
	}
}

int FreeTable(Table** t)
{
	for(size_t i = 0; i < (*t)->csize; i++)
	{
		KeySpace* ks = &((*t)->ks[i]);
		int flag = FreeKeySpace(&(ks));
		if(flag == 0)
		{
			return 0;
		}
	}
	free(*t);
	return 1;
	
}

void PrintTable(Table* t)
{
	if(t == NULL)
	{
		printf("ошибка: передан NULL\nПовторите ввод\n");
		return;
	}
	else
	{
		for(size_t i = 0; i < t->csize; i++)
		{
			PrintKeySpace(&t->ks[i]);
		}
	}
}