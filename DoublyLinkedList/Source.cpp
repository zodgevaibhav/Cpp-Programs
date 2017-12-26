#pragma once
#include<conio.h>
#include<stdlib.h>

#include "Header.h"

bool isListEmpty(List* myList);
List* createList()
{
	List* list = (List*)malloc(sizeof(List));
	if (list == NULL) return FAIL;

	list->prev = NULL;
	list->data = NULL;
	list->next = NULL;
	list = NULL;
	return list;
}

RESULT addNode(List* &temp, DATA data)
{
	List *  tempNode = (List*)malloc(sizeof(List));
	if (tempNode == NULL) return FAIL;

	List * tempNodeOneMore = temp;
	tempNode->prev = NULL;
	tempNode->data = data;
	tempNode->next = NULL;
	if (temp == NULL)
	{
		temp = tempNode;
	}
	else {
		while (tempNodeOneMore->next != NULL)
			tempNodeOneMore = tempNodeOneMore->next;
		tempNodeOneMore->next = tempNode;
		tempNode->prev = tempNodeOneMore;
	}
	return SUCCESS;
}

RESULT displayList(List* myList1) {
	bool isFistNode = true;
	if (isListEmpty(myList1))
		return LIST_EMPTY;
	printf("\nDisplaying list:");
	while (myList1 != NULL)
	{
		isFistNode == true ? printf("%d", myList1->data) : printf("->%d", myList1->data);
		myList1 = myList1->next;
		isFistNode = false;
	}
	return SUCCESS;
}

RESULT getFirst(List *list, DATA *data)
{
	if (isListEmpty(list))
		return LIST_EMPTY;
	*data = (DATA)(list->data);
	return SUCCESS;
}

RESULT getLast(List *myList1, DATA *data)
{
	if (isListEmpty(myList1))
		return LIST_EMPTY;

	while (myList1->next != NULL)
		myList1 = myList1->next;
	*data = (DATA)myList1->data;
	return SUCCESS;
}

void deleteNodePrivate(List *myList1)
{
	List* node = (List*)malloc(sizeof(List));

	node = myList1->next->next;
	delete myList1->next;
	myList1->next = node;
	node->prev = myList1;
}
RESULT deleteNode(List *myList1, DATA data)
{
	if (isListEmpty(myList1))
		return LIST_EMPTY;

	while (myList1->next->data != data)
	{
		myList1 = myList1->next;
		if (myList1 == NULL) return DATA_NOT_FOUND;
	}
	deleteNodePrivate(myList1);
	return SUCCESS;
}

RESULT deleteBefore(List *myList1, DATA data)
{
	if (isListEmpty(myList1))
		return LIST_EMPTY;

	while (myList1->next->next->data != data)
	{
		myList1 = myList1->next;
		if (myList1->next->next == NULL) return DATA_NOT_FOUND;
	}
	deleteNodePrivate(myList1);
	return SUCCESS;
}

RESULT deleteAfter(List *myList1, DATA data)
{
	if (isListEmpty(myList1))
		return LIST_EMPTY;

	while (myList1->data != data)
	{
		myList1 = myList1->next;
		if (myList1 == NULL) return DATA_NOT_FOUND;
	}
	deleteNodePrivate(myList1);
	return SUCCESS;
}

bool isListEmpty(List* myList)
{
	if (myList == NULL)
		return true;
	return false;
}

List* getLastNode(List* list) {
	while (list->next != NULL)
		list = list->next;
	return list;
}

RESULT displayListInReverseOrcer(List *myList)
{
	myList = getLastNode(myList);
	printf("\nDisplying list in reverse order: ");
	while (myList!= NULL)
	{
		myList->next == NULL ? printf("%d", myList->data) : printf("->%d", myList->data);
			myList = myList->prev;
	}
	return 0;
}

RESULT destroyList(List* list)
{
	if (list == NULL)
		return LIST_EMPTY;
	list = getLastNode(list);
	if (list == NULL)
		return FAIL;
	while (list != NULL)
	{
		delete(list->next);
		list = list->prev;
	}

	return SUCCESS;
}

void main()
{
	List* myList = createList();
	DATA data;
	for (int i = 10; i <= 90; i = i + 10)
	{
		addNode(myList, i);
	}
	displayList(myList);
	displayListInReverseOrcer(myList);

	if (getFirst(myList, &data) == SUCCESS)
	{
		printf("\nFirst:%d", data);
	}
	else
	{
		printf("\nFailed to get first:%d", data);
	}

	if (getLast(myList, &data) == SUCCESS)
	{
		printf("\nLast:%d", data);
	}
	else
	{
		printf("\nFailed to get Last:%d", data);
	}
	if (deleteNode(myList, 30) != SUCCESS)
	{
		printf("\nFailed to delete node %d", 30);
	}
	else {
		printf("\nDeleted node %d", 30);
	}
	displayList(myList);
	displayListInReverseOrcer(myList);
	if (deleteBefore(myList, 60) != SUCCESS)
	{
		printf("\nFailed to delete node before %d", 60);
	}
	else {
		printf("\nDeleted node before %d", 60);
		displayList(myList);
		displayListInReverseOrcer(myList);
	}
	if (deleteAfter(myList, 70) != SUCCESS)
	{
		printf("\nFailed to delete node after %d", 70);
	}
	else {
		printf("\nDeleted node after %d", 70);
		displayList(myList);
		displayListInReverseOrcer(myList);
	}
	if (destroyList(myList) == SUCCESS)
		printf("\nList destroyed successfully");
	else
		printf("\nFailed to destroy the list");
	
	_getch();
}
