#pragma once
#include<Windows.h>
#include<stdio.h>
#define FAIL 0
#define SUCCESS 1
#define DATA_NOT_FOUND 2
#define LIST_EMPTY 3

typedef int RESULT;
typedef int DATA;

typedef struct Node {int data;	struct Node* next;} Node;
typedef struct List { int data;	struct List* next; } List;

List* createList();
RESULT addNode(List* &temp, DATA data);
RESULT displayList(List* myList1);
RESULT getFirst(List *list, DATA *data);
RESULT getLast(List *myList1, DATA *data);
RESULT deleteNode(List *myList1, DATA data);
RESULT deleteBefore(List *myList1, DATA data);
RESULT deleteAfter(List *myList1, DATA data);