#pragma once
#include "headers.h"
#include<string.h>
typedef struct Node {
	void *node;
	struct Node *prev;
	struct Node *next;
} Node;
typedef struct dList {
	int size;
	Node *head;
	Node *tail;
} dList;
dList* createDList();
void deleteDList(dList**);
void pushFront(dList *, void*);
void* popFront(dList*);
void pushBack(dList*, void*);
void* popBack(dList*);
Node *getNth(dList*, int);
void insert(dList*, int, void*);
void deleteNth(dList*, int);