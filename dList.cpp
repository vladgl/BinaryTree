#include"dList.h"
dList* createDList()
{
	dList *tmp = (dList*)malloc(sizeof(dList));
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;
	return tmp;
}
void deleteDList(dList **plist)
{
	Node *tmp = (*plist)->head;
	Node *next = NULL;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*plist);
	(*plist) = NULL;
}
void pushFront(dList *list, void *node)
{
	Node *tmp = (Node*)malloc(sizeof(Node));

	tmp->node = node;
	tmp->next = list->head;
	tmp->prev = NULL;

	if (list->head != NULL)
		list->head->prev = tmp;

	if (list->tail == NULL)
		list->tail = tmp;
	list->head = tmp;
	(list->size)++;
}
void* popFront(dList *list)
{
	if (list->head != NULL)
	{
		void *node = NULL;
		Node *tmp = NULL;
		tmp = list->head;
		if (list->head == list->tail)
			list->head = list->tail = NULL;
		else {
			list->head = list->head->next;
			list->head->prev = NULL;
		}

		node = tmp->node;
		free(tmp);
		(list->size)--;
		return node;
	}
	return NULL;
}
void pushBack(dList *list, void *node)
{
	Node *tmp = (Node*)malloc(sizeof(Node));

	tmp->node = node;
	tmp->prev = list->tail;
	tmp->next = NULL;

	if (list->tail != NULL)
		list->tail->next = tmp; 

	if (list->head == NULL)
		list->head = tmp;
	list->tail = tmp;

	(list->size)++;
}
void* popBack(dList *list)
{
	if (list->tail != NULL)
	{
		void *node = NULL;
		Node *tmp = NULL;
		tmp = list->tail;
		if (list->head == list->tail)
			list->head = list->tail = NULL;
		else {
			list->tail = list->tail->prev;
			list->tail->next = NULL;
		}
		node = tmp->node;
		free(tmp);
		(list->size)--;
		return node;
	}
	return NULL;
}
Node *getNth(dList *list, int n)  //нумерация элементов списка начинается с нуля!
{
	Node *tmp = list->head;

	int i = 0;

	while ((tmp != NULL) && (i < n))
	{
		tmp = tmp->next;
		i++;
	}
	return tmp;
}

void insert(dList* list, int n, void *node)   //вставка на n-ую позицию (то есть, перед элементом с номером n при нумерации с 0)
{
	Node *tmp = getNth(list, n);
	Node *lnode = (Node*)malloc(sizeof(Node));

	lnode->node = node;

	if (tmp == NULL) {
		printf("List is empty or list overflow!\n");
		return;
	}
	if (tmp->prev == NULL)
	{
		lnode->next = tmp;
		lnode->prev = NULL;
		list->head = lnode;
		tmp->prev = lnode;
	}
	else {
		lnode->next = tmp;
		lnode->prev = tmp->prev;
		tmp->prev->next = lnode;
		tmp->prev = lnode;
	}
	(list->size)++;
}


void deleteNth(dList* list, int n)  //нумерация с 0!
{
	Node *tmp = getNth(list, n);

	if (tmp == NULL) {
		printf("List is empty or list overflow!\n");
		return;
	}
	if (tmp->next != NULL)
	{
		tmp->next->prev = tmp->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = tmp->next;
		else list->head = tmp->next;
	}
	else
	{
		list->tail = tmp->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = NULL;
		else list->head = NULL;
	}
	free(tmp);
	(list->size)--;
}