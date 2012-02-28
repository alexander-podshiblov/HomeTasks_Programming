#include <stdafx.h>
#include <stdlib.h>
#include "sortlist.h"

void addSortList(SList *head)
{
	printf("\n-----------------------------------------\n");
	printf("	Enter the value of the element to add to the list: ");
	int value = 0;
	scanf("%i", &value);
	sadd(head, value);
	printf("\n	Element was added.");
}

void printSortList(SList *head)
{
	printf("\n-----------------------------------------\n");
	printf("	Your list:\n\n	");
	sprintList(head);
}

void removePositionFromList(SList *head)
{
	printf("\n-----------------------------------------\n");
	printf("Enter the number of element to remove: ");
	int num = 0;
	scanf("%i", &num);
	sdel(head, num);
	printf("\n	Element was removed.");
}

void removeValueFromList(SList *head)
{
	printf("\n-----------------------------------------\n");
	printf("Enter the value of element to remove: ");
	int value = 0;
	scanf("%i", &value);
	sdelv(head, value);
	printf("\n	Element was removed.");
}

int main()
{
	SList *head = new SList;
	head->value = 0;
	head->next = NULL;
	
	char choice = 0;
	while (choice != '0')
	{
		printf("\n-----------------------------------------\n");
		printf("	0 - exit\n	1 - add value to sorted list\n	2 - remove position from list\n	3 - remove value from list\n	4 - print list\n	");
		scanf("%c", &choice);
			
		if (choice == '\n')
			scanf("%c", &choice);
		
		if (choice == '1')
		{
			addSortList(head);
		}
		if (choice == '2')
		{
			removePositionFromList(head);
		}
		if (choice == '3')
		{
			removeValueFromList(head);
		}
		if (choice == '4')
		{
			printSortList(head);
		}
	}

	sremoveList(head);

	delete head;
	return 0;
}