#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
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
void preOrderT(tNode*);    //прямой
void inOrderT(tNode*);     //симметричный
void postOrderT(tNode*);   //в обратном порядке
void breadthFirst(tNode*); //в ширину
