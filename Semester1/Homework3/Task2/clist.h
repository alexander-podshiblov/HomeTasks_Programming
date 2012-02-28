#pragma once

struct CList
{
	int value;
	CList *next;
};

int lengh(CList *head);

void add(CList *head, int value, int num);

void del(CList *head, int num);

void printList(CList *head);

int returnValue(CList *head, int num);

void swap(CList *head, int i, int j);

void removeList(CList *head);