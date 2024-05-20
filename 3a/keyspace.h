#ifndef KEYSPACE_H
#define KEYSPACE_H

typedef struct  {
	unsigned int key;
	unsigned int par;
	unsigned int* info;
} KeySpace;

void InsertKeySpace(KeySpace* ks, int i, unsigned int key, unsigned int par, unsigned int* info);
int FreeKeySpace(KeySpace* ks);
void PrintKeySpace(KeySpace* ks);

#endif
