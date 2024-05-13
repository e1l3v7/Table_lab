#ifndef KEYSPACE_H
#define KEYSPACE_H

typedef struct  
{
	unsigned int key;
	unsigned int par;
	unsigned int* info;
} KeySpace;

KeySpace* CreateKeySpace(unsigned int key, unsigned int par, unsigned int* info);
int FreeKeySpace(KeySpace* ks);
void PirntKeySpace(KeySpace* ks);

#endif