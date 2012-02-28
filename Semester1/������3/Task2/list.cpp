#include <stdafx.h>

struct List
{
	int value;
	List *next;
};

int llengh(List *head)
{
	int k = 0;
	List *tmp = head;
	while (tmp->next)
	{
		k++;
		tmp = tmp->next;
	}
	return k;
}

void ladd(List *head, int value, int num)
{
	if (num <= llengh(head))
	{
		int k = 1;
		List *tmp = head;
		while (k < num)
		{
			tmp = tmp->next;
			k++;
		}
		List *tmp2 = new List;
		tmp2->value = value;
		tmp2->next = tmp->next->next;
		tmp->next->next = tmp2;
	}
	else
	{
		List *tmp = head;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		List *tmp2 = new List;
		tmp2->value = value;
		tmp2->next = tmp->next;
		tmp->next = tmp2;
	}
}

void ldel(List *head, int num)
{
	if ((num <= llengh(head)) && (num > 0))
	{
		int k = 1;
		List *tmp = head;
		while (k < num)
		{
			tmp = tmp->next;
			k++;
		}
		List *tmp2 = new List;
		tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		delete tmp2;
	}

}

void lprintList(List *head)
{
	List *tmp = head;
	while(tmp->next)
	{
		tmp = tmp->next;
		printf("%i ", tmp->value);
	}
}

int lreturnValue(List *head, int num)
{
	if ((num <= llengh(head)) && (num > 0))
	{
		int k = 1;
		List *tmp = head;
		while (k < num)
		{
			tmp = tmp->next;
			k++;
		}
		return tmp->next->value;
	}
	else
		return -32000;
}

void lswap(List *head, int i, int j)
{
	
	if ((i <= llengh(head)) && (i > 0) && (j <= llengh(head)) && (j > 0))
	{
		int k = 1;
		List *tmp = head;
		while (k < i)
		{
			tmp = tmp->next;
			k++;
		}
		k = 1;
		List *tmp2 = head;
		while (k < j)
		{
			tmp2 = tmp2->next;
			k++;
		}
		int a = tmp->next->value;
		tmp->next->value = tmp2->next->value;
		tmp2->next->value = a;
	}
}

void lremoveList(List *head)
{
	while (head->next != NULL)
		ldel(head, 1);
}