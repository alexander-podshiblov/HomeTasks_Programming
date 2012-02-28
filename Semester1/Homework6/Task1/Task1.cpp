#include "stdafx.h"
#include "bst.h"

void addValue(Tree *head)
{
	printf("\n	Enter the value: ");
	int value = 0;
	scanf("%i", &value);
	add(head, value);
	printf("\n");
}

void existence(Tree *head)
{
	printf("\n	Enter the value: ");
	int value = 0;
	scanf("%i", &value);
	if (exist(head->left, value))
		printf("	This item belong to the tree");
	else
		printf("	This item does not belongs to the tree");
	printf("\n");
}

void delValue(Tree *head)
{
	printf("\n	Enter the value: ");
	int value = 0;
	scanf("%i", &value);
	del(findToDel(head->left, value), value);
	printf("\n");
}

void printEl(Tree *tmp)
{
	printf("\n	In ascending or descending order (a/d)? ");
	char c = 0;
	scanf("%c", &c);
	if (c == '\n')
			scanf("%c", &c);
	printf("\n	");
	if (c == 'a')
		printInc(tmp);
	else if (c == 'd')
		printDec(tmp);
	printf("\n");
}

int main()
{
	Tree *head = new Tree;
	head->value = -32999;
	head->left = NULL;
	head->right = NULL;
	head->prev = NULL;

	char c = 0;

	while (c != '0')
	{
		printf("\n	0 Exit\n	1 Add value to tree\n	2 Delete value from tree\n	3 Exist?\n	4 Print\n	");
		scanf("%c", &c);
		if (c == '\n')
			scanf("%c", &c);
		if (c == '1')
			addValue(head);
		if (c == '2')
			delValue(head);
		if (c == '3')
			existence(head);
		if (c == '4')
			printEl(head->left);
	}
	
	
	delTree(head->left);
	delete head;	
	return 0;
}