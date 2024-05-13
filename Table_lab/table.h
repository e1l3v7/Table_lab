#ifndef TABLE_H
#define TABLE_H
#include "keyspace.h"

typedef struct
{
	KeySpace* ks;
	int msize;
	int csize;
} Table;

Table* CreateTable(int msize);
int FreeTable(Table** t);
int Insert(Table** t, unsigned int key, unsigned int* info);
int Delete(Table** t, unsigned int key, unsigned int par);
Table* Search(Table* t, unsigned int key);
void PrintTable(Table* t);

#endif