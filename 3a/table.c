#include "table.h"
#include <stdio.h>
#include <stdlib.h>

Table* CreateTable(int msize)
{
	Table* t = NULL;
	t = (Table*)calloc(1, sizeof(Table));
	if(t != NULL) {
		t->ks =(KeySpace*)calloc(msize, sizeof(KeySpace));;
		if(t->ks != NULL) {
			t->msize = msize;
			t->csize = 0;
			return t;
		}
		else {
			printf("ошибка: не удалось выделить память для KeySpace*\n");
			return NULL;
		}
	}
	else {
		printf("ошибка: не удалось выделить память для Table\n");
		return NULL;
	}
}

int Insert(Table* t, unsigned int key, unsigned int par, unsigned int* info) {
	if(t == NULL) {
		printf("ошибка: передан NULL\n");
		return 0;
	}
	else {
		if(t->csize < t->msize) {
			int flag = 0;
			if(par != 0) {
				for(size_t i = 0; i < t->csize; i++) {
					if(t->ks[i].key == par) {
						flag = 1;
						break;
					}
				}
			}
			else {
				flag = 1;
			}
			if(flag) {
				flag = 0;
				for(size_t i = 0; i < t->csize; i++) {
					if(t->ks[i].par == par && t->ks[i].key == key) {
						flag = 1;
						break;
					}
				}
				if(!flag) {
					if(t->csize == 0) {
						InsertKeySpace(t->ks, 0, key, par, info);
					}
					else {
						for(size_t i = 0; i < t->csize; i++) {
							if(t->ks[i].par >= par) {
								for(size_t j = t->csize; j > i; j--) {
									t->ks[j] = t->ks[j-1];
								}
								InsertKeySpace(t->ks, i, key, par, info);
								break;
							}
							else if(i == t->csize - 1) {
								InsertKeySpace(t->ks, i + 1, key, par, info);
								break;
							}
						
						}
					}
					t->csize += 1;
					return 1;
				}
				else {
					printf("ошибка: элемент с такими ключами уже существует\n");
					return 0;
				}
			}
			else {
				printf("ошибка: элемент с таким ключом не существует\n");
				return 0;
			}
		}
		else {
			printf("ошибка: таблица полна\n");
			return 0;
		}
	}
}

int Delete(Table* t, unsigned int key, unsigned int par) {
	if(t == NULL) {
		printf("ошибка: передан NULL\n");
		return 0;
	}
	else {
		if(t->csize > 0) {
			int co = 0;
			for(size_t i = 0; i < t->csize; i++) {
				if(t->ks[i].par == par && t->ks[i].key == key) {
					co += 1;
				}
			}
			if(co == 1) {
				KeySpace* new_ks = NULL;
				new_ks = (KeySpace*)calloc(t->msize,sizeof(KeySpace));
				int bi = 0;
				for(size_t i = 0; i < t->csize; i++) {
					if(t->ks[i].par == par && t->ks[i].key == key) 
						bi += 1;
					else
						new_ks[i-bi] = t->ks[i];
				}
				free(t->ks);
				t->ks = new_ks;
				t->csize -= 1;
				return 1;
			}
			else if(co == 0) {
				printf("ошибка: такого сочетания key-par нет в таблицe\n");
				return 0;
			}
			else {
				printf("ошибка: несколько таких сочетаний key-par в таблицe\n");
				return 0;
			}
		}
		else {
			printf("ошибка: таблица пуста\n");
			return 0;
		}
	}
}

Table* Search(Table* t, unsigned int key)
{
	if(t == NULL) {
		printf("ошибка: передан NULL\n");
		return NULL;
	}
	else {
		if(t->csize == 0) {
			printf("ошибка: таблица пуста\n");
			return NULL;
		}
		else {
			int size;
			for(size_t i = 0; i < t->csize; i++) {
				if(t->ks[i].key == key) {
					size += 1;
				}
			}
			if(size == 0) {
				printf("ошибка: такого элемента нет в таблице\n");
				return NULL;
			}
			else {
				Table* t1 = NULL;
				t1 = CreateTable(size);
				if(t1 == NULL) {
					return NULL;
				}
				else {
					for(size_t i = 0; i < t->csize; i++) {
						if(t->ks[i].key == key) {
							int flag = Insert(t1, t->ks[i].key, t->ks[i].par, t->ks[i].info);
							if(flag == 0) {
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

int FreeTable(Table* t) {
	for(size_t i = 0; i < t->csize; i++) {
		int flag = FreeKeySpace(t->ks+i));
		if(flag == 0) {
			return 0;
		}
	}
	return 1;
	
}

void PrintTable(Table* t) {
	if(t->ks == NULL) {
		printf("ошибка: передан NULL\nПовторите ввод\n");
		return;
	}
	else {
		for(size_t i = 0; i < t->csize; i++) {
			PrintKeySpace(t->ks+i);
		}
	}
}
