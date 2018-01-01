#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int DATA;

#define FAIL 0
#define SUCCESS 1
#define DATA_NOT_FOUND 2
#define LIST_EMPTY 3

typedef int RESULT;

typedef struct node
{
	DATA value;
	struct  node *next; 
	struct  node *prev;
}NODE;

void createStack(NODE *node);
DATA PUSH_Node(NODE **newNode, int data);
DATA POP_Node(NODE *delet);
void displaySTACK(NODE *temp);
void firstNodeOfSTACK(NODE **delet);