#include "Header.h"
#include<conio.h>

RESULT createStack(NODE **node)
{
		NODE *temp = (NODE*)malloc(sizeof(NODE));
		node = &temp;
		printf("Empty stack is created...");
		return SUCCESS;
	
}

RESULT PUSH_Node(NODE **node, DATA data)
{
		//if (*node == NULL) return LIST_EMPTY;
		
		NODE *tempNode = (NODE*)malloc(sizeof(NODE));
		
		if (tempNode == NULL) return FAIL;
		
		tempNode->value = data;
		tempNode->next = NULL;
		tempNode->prev = *node;
		*node = tempNode;
		
		return SUCCESS;
}

void POP_Node(NODE **node)
{
	NODE *tempNode = *node;
	*node = tempNode->prev;
	free(tempNode);
}
RESULT displayList(NODE* myList1) {
	bool isFistNode = true;
	
	if (NULL==myList1)
		return LIST_EMPTY;
	
	printf("\nDisplaying list:");
	while (myList1 != NULL)
	{
		isFistNode == true ? printf("%d", myList1->value) : printf("->%d", myList1->value);
		myList1 = myList1->prev;
		isFistNode = false;
	}
	return SUCCESS;
}

RESULT printNode(NODE *node)
{
	if (node == NULL) return LIST_EMPTY;
	if (node->value == NULL) return FAIL;
	printf("\n\t Value of top node is %d", node->value);
	return SUCCESS;
}

void main()
{
	NODE *top = NULL;
	int option=0, a=0;
	bool isQuit=false;
	while (!isQuit)
	{
		system("cls");
		printf("\n 1) Create empty stack");
		printf("\n 2) PUSH");
		printf("\n 3) POP");
		printf("\n 4) Stack Top");
		printf("\n 5) Stack Details");
		printf("\n 0) Quit\n\n");
		printf("Option: ");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			if(createStack(&top)==SUCCESS)
			printf("\n\t Empty stack created...");
			else
				printf("\n\t Unable to create stack...");
			_getch();
			break;
		case 2:
			printf("\t Enter data to push in stack - ");
			scanf_s("%d", &a);

			switch (PUSH_Node(&top, a)) {
			case SUCCESS:
				printf("\n\t Data %d pushed to stack..", a);
				break;
			case FAIL:
				printf("\n\t Unable to push Data %d to stack..", a);
				break;
			}
				
			_getch();
			break;
		case 3:
			POP_Node(&top);
			break;
		case 4:
			switch (printNode(top))
			{
			case LIST_EMPTY:
				printf("\n\t Unable to print as stack is empty..", a);
				break;
			case FAIL:
				printf("\n\t Unable to print Data %d to stack..", a);
				break;
			}
			_getch();
			break;
		case 5:
			if (displayList(top) == LIST_EMPTY)
				printf("\n\t Unable to print stack as stack is empty...");
			_getch();
			break;
		case 0:
			isQuit = true;
			break;
		default:
			break;
		}
	}
}