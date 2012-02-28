#pragma once

struct List
{
	int value;
	List *next;
};

int llengh(List *head);

void ladd(List *head, int value, int num);

void ldel(List *head, int num);

void lprintList(List *head);

int lreturnValue(List *head, int num);

void lswap(List *head, int i, int j);

void lremoveList(List *head);