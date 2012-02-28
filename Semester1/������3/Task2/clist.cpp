#include <stdafx.h>

struct CList
{
	int value;
	CList *next;
};

int lengh(CList *head)
{
	if (head->next == NULL)
		return 0;
	else
	{
		int k = 1;
		CList *tmp = head;
		while (tmp->next->next != head->next)
		{
			k++;
			tmp = tmp->next;
		}
		return k;
	}
}

void add(CList *head, int value, int num)
{
	if (lengh(head) == 0)
	{
		CList *tmp = new CList;
		tmp->value = value;
		tmp->next = tmp;
		head->next = tmp;
	}
	else if (num == 0)
	{
		CList *tmp = head->next;
		while (tmp->next != head->next)
		{
			tmp = tmp->next;
		}
		CList *tmp2 = new CList;
		tmp2->value = value;
		tmp2->next = head->next;
		head->next = tmp2;
		tmp->next = tmp2;
	}
	else if ((num <= lengh(head)) && (num > 0))
	{
		int k = 1;
		CList *tmp = head;
		while (k < num)
		{
			tmp = tmp->next;
			k++;
		}
		CList *tmp2 = new CList;
		tmp2->value = value;
		tmp2->next = tmp->next->next;
		tmp->next->next = tmp2;
	}
}

void del(CList *head, int num)
{
	if ((lengh(head) == 1) && (num == 1))
	{
		CList *tmp = head->next;
		head->next = NULL;
		delete tmp;
	}
	else if (num == 1)
	{
		CList *tmp2 = head->next;
		CList *tmp = head->next;
		
		while (tmp->next != head->next)
		{
			tmp = tmp->next;
		}
		tmp->next = head->next->next;
		head->next = head->next->next;
		delete tmp2;
	}
	else if ((num <= lengh(head)) && (num > 1))
	{
		int k = 1;
		CList *tmp = head;
		while (k < num)
		{
			tmp = tmp->next;
			k++;
		}
		CList *tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		delete tmp2;
	}

}

void printList(CList *head)
{
	int k = 0;
	CList *tmp = head;
	while(k < lengh(head))
	{
		tmp = tmp->next;
		printf("%i ", tmp->value);
		k++;
	}
}

int returnValue(CList *head, int num)
{
	if ((num <= lengh(head)) && (num > 0))
	{
		int k = 1;
		CList *tmp = head;
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

void swap(CList *head, int i, int j)
{
	
	if ((i <= lengh(head)) && (i > 0) && (j <= lengh(head)) && (j > 0))
	{
		int k = 1;
		CList *tmp = head;
		while (k < i)
		{
			tmp = tmp->next;
			k++;
		}
		k = 1;
		CList *tmp2 = head;
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

void removeList(CList *head)
{
	while (head->next != NULL)
		del(head, 1);
}