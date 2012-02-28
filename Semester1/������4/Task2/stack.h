#pragma once

struct Stack
{
	int value;
	Stack *next;
};

void add(Stack *head, int value);

int empty(Stack *head);

void del(Stack *head);

int returnLast(Stack *head);

void removeStack(Stack *head);