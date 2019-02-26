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
void preOrderT(tNode*);    //ïðÿìîé
void inOrderT(tNode*);     //ñèììåòðè÷íûé
void postOrderT(tNode*);   //â îáðàòíîì ïîðÿäêå
void breadthFirst(tNode*); //â øèðèíó
