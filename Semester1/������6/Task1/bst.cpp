#include "stdafx.h"

struct Tree
{
	int value;
	Tree *left;
	Tree *right;
	Tree *prev;
};

Tree *createEl(Tree *tmp, int value)
{
	Tree *tmp2 = new Tree;
	tmp2->left = NULL;
	tmp2->right = NULL;
	tmp2->value = value;
	tmp2->prev = tmp;
	return tmp2;
}

void add2(Tree *tmp, int value)
{
	if (value < tmp->value)
	{
		if (tmp->left == NULL)
		{
			tmp->left = createEl(tmp, value);
		}
		else
			add2(tmp->left, value);
	}
	else if (value > tmp->value)
	{
		if (tmp->right == NULL)
		{
			tmp->right = createEl(tmp, value);
		}
		else
			add2(tmp->right, value);
	}
}

void add(Tree *head, int value)
{
	if (head->left == NULL)
	{
		head->left = createEl(head, value);
	}
	else
	{
		add2(head->left, value);	
	}
}

bool exist(Tree *tmp, int value)
{
	if (tmp == NULL)
		return false;
	else if (tmp->value == value)
		return true;
	else if (value < tmp->value)
		return exist(tmp->left, value);
	else
		return exist(tmp->right, value);
}

Tree *findToDel(Tree *tmp, int value)
{
	if (tmp == NULL)
		return NULL;
	else if (tmp->value == value)
		return tmp;
	else if (value < tmp->value)
		return findToDel(tmp->left, value);
	else if (value > tmp->value)
		return findToDel(tmp->right, value);
}

int delMinFromRight(Tree *tmp)
{
	Tree *tmp2 = tmp->right;
	while (tmp2->left != NULL)
	{
		tmp2 = tmp2->left;
	}
	int min = tmp2->value;
	tmp2 = tmp2->prev;
	if (tmp2 == tmp)
	{
		delete tmp2->right;
		tmp2->right == NULL;
	}
	else
	{
		delete tmp2->left;
		tmp2->left = NULL;
	}
	return min;
}

void del(Tree *tmp, int value)
{
	if (tmp != NULL)
	{
		if ((tmp->left == NULL) && (tmp->right == NULL))
		{
			if (tmp == tmp->prev->left)
				tmp->prev->left = NULL;
			else if (tmp == tmp->prev->right)
				tmp->prev->right = NULL;
			delete tmp;
		}
		else if ((tmp->left != NULL) && (tmp->right == NULL))
		{
			if (tmp == tmp->prev->left)
				tmp->prev->left = tmp->left;
			else if (tmp == tmp->prev->right)
				tmp->prev->right = tmp->left;
			delete tmp;
		}
		else if ((tmp->left == NULL) && (tmp->right != NULL))
		{
			if (tmp == tmp->prev->left)
				tmp->prev->left = tmp->right;
			else if (tmp == tmp->prev->right)
				tmp->prev->right = tmp->right;
			delete tmp;
		}
		else if ((tmp->left != NULL) && (tmp->right != NULL))
		{
			tmp->value = delMinFromRight(tmp);
		}
	}
}

void printInc(Tree *tmp)
{
	if (tmp != NULL)
	{
		if ((tmp->left == NULL) && (tmp->right == NULL))
			printf("%i ", tmp->value);
		else 
		{
		if (tmp->left != NULL)
			printInc(tmp->left);
		printf("%i ", tmp->value);
		if (tmp->right != NULL)
			printInc(tmp->right);
		}
	}
}

void printDec(Tree *tmp)
{
	if (tmp != NULL)
	{
		if ((tmp->left == NULL) && (tmp->right == NULL))
			printf("%i ", tmp->value);
		else 
		{
		if (tmp->right != NULL)
			printDec(tmp->right);
		printf("%i ", tmp->value);
		if (tmp->left != NULL)
			printDec(tmp->left);
		}
	}
}

void delTree(Tree *tmp)
{
	if (tmp != NULL)
	{
		if ((tmp->left == NULL) && (tmp->right == NULL))
		{
			if (tmp == tmp->prev->left)
				tmp->prev->left = NULL;
			else if (tmp == tmp->prev->right)
				tmp->prev->right = NULL;
			delete tmp;
		}
		else
		{
			if (tmp->right != NULL)
				delTree(tmp->right);
			if (tmp->left != NULL)
				delTree(tmp->left);
			delTree(tmp);
		}
	}
}