#include"bTree.h"
void createTree(tNode **node)
{
	*node = NULL;
}
tNode* addNode(tNode *tree, char *str)
{
	if (tree == NULL)
	{
		tree = (tNode*)malloc(sizeof(tNode));
		strcpy_s(tree->word, str);
		tree->count = 1;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if (strcmp(tree->word, str) == 0)
		tree->count += 1;
	else if (strcmp(tree->word, str) > 0)
		tree->left = addNode(tree->left, str);
	else tree->right = addNode(tree->right, str);
	
	return tree;
}
void delTree(tNode **tree)
{
	if (*tree != NULL)
	{
		delTree(&((*tree)->left));
		delTree(&((*tree)->right));
		free(*tree);
	}
	*tree = NULL;   //обнуляем адрес узла
}

//traverses

/*****depth-first search*****/
void preOrderT(tNode *tree)
{
	if (tree != NULL)
	{
		printf("%s %d\n", tree->word, tree->count);
		preOrderT(tree->left);
		preOrderT(tree->right);
	}
}
void inOrderT(tNode *tree)
{
	if (tree != NULL)
	{
		inOrderT(tree->left);
		printf("%s %d\n", tree->word, tree->count);
		inOrderT(tree->right);
	}
}
void postOrderT(tNode *tree)
{
	if (tree != NULL)
	{
		postOrderT(tree->left);
		postOrderT(tree->right);
		printf("%s %d\n", tree->word, tree->count);
	}
}
/*****breadth-first search*****/
void breadthFirst(tNode *tree)
{
	dList *queue = createDList();
	tNode *node = NULL;
	pushFront(queue, tree);
	while (queue->size != 0)
	{
		node = (tNode*)popBack(queue);

		printf("%s %d\n", node->word, node->count);
		if (node->left != NULL)
			pushFront(queue, node->left);
		if (node->right != NULL)
			pushFront(queue, node->right);
	}
	deleteDList(&queue);
}