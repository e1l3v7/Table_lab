#include "keyspace.h"
#include <stdio.h>
#include <stdlib.h>

void InsertKeySpace(KeySpace* ks, int i, unsigned int key, unsigned int par, unsigned int* info) {	
	ks[i].key = key;
	ks[i].par = par;
	ks[i].info = info;
}

int FreeKeySpace(KeySpace* ks) {
	if(ks != NULL) {
		free(ks);
		return 1;
	}
	else {
		printf("ошибка: передан NULL\n");
		return 0;
	}
}

void PrintKeySpace(KeySpace* ks) {
	if(ks == NULL) {
		printf("Передан NULL");
		return;
	}
	else {
		printf("key: %d, par: %d, info: %d\n", ks->key, ks->par, *ks->info);
	}
}
