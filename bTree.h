#pragma once
#include"headers.h"
#include"dlist.h"
typedef struct tNode {
	char word[20];
	int count;

	struct tNode *left;
	struct tNode *right;

} tNode;
void createTree(tNode **);
tNode* addNode(tNode*, char*);
void delTree(tNode**);
void preOrderT(tNode*);    //пр€мой
void inOrderT(tNode*);     //симметричный
void postOrderT(tNode*);   //в обратном пор€дке
void breadthFirst(tNode*); //в ширину