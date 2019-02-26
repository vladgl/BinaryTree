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
void preOrderT(tNode*);    //������
void inOrderT(tNode*);     //������������
void postOrderT(tNode*);   //� �������� �������
void breadthFirst(tNode*); //� ������