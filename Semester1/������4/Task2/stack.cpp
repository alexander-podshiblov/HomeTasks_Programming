#include <stdafx.h>

struct Stack
{
	int value;
	Stack *next;
};

void add(Stack *head, int value)
{
	Stack *tmp = new Stack;
	tmp->value = value;
	tmp->next = head->next;
	head->next = tmp;
}

int empty(Stack *head)
{
	if (head->next == NULL)
		return 1;
	else
		return 0;
}

void del(Stack *head)
{
	Stack *tmp = head->next;
	head->next = tmp->next;
	delete tmp;
}

int returnLast(Stack *head)
{
	return head->next->value;
}

void removeStack(Stack *head)
{
	while (!empty(head))
		del(head);
}