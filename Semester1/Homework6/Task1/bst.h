#pragma once

struct Tree
{
	int value;
	Tree *left;
	Tree *right;
	Tree *prev;
};

void add2(Tree *tmp, int value);

void add(Tree *head, int value);

bool exist(Tree *tmp, int value);

Tree *findToDel(Tree *tmp, int value);

int delMinFromRight(Tree *tmp);

void del(Tree *tmp, int value);

void printInc(Tree *tmp);

void printDec(Tree *tmp);

void delTree(Tree *tmp);