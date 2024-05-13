#include "keyspace.h"
#include <stdio.h>

KeySpace* CreateKeySpace(unsigned int key, unsigned int par, unsigned int* info)
{
	KeySpace* ks = NULL;
	ks = (KeySpace*)malloc(sizeof(KeySpace));
	if(ks != NULL)
	{
		ks->key = key;
		ks->par = par;
		ks->info = info;
		return ks;
	}
	else
	{
		printf("ошибка: не удалось выделить память для KeySpace\n");
		return ks;
	}
	
}

int FreeKeySpace(KeySpace* ks)
{
	if(ks != NULL)
	{
		free(ks);
		return 1;
	}
	else
	{
		printf("ошибка: передан NULL\n");
		return 0;
	}
	
}

void PrintKeySpace(KeySpace* ks)
{
	if(ks == NULL)
	{
		printf("Передан NULL");
		return;
	}
	else
	{
		printf("key: %d, par: %d, info: %d\n", ks->key, ks->par, *ks->info);
	}
}