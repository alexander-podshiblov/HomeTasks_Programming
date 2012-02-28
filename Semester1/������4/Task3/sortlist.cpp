#include <stdafx.h>

struct SList
{
	int value;
	SList *next;
};

int slengh(SList *head)
{
	int k = 0;
	SList *tmp = head;
	while (tmp->next)
	{
		k++;
		tmp = tmp->next;
	}
	return k;
}

int sreturnValue(SList *head, int num)
{
	if ((num <= slengh(head)) && (num > 0))
	{
		int k = 1;
		SList *tmp = head;
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

void createEl(SList *tmp, int value)
{
	SList *tmp2 = new SList;
	tmp2->value = value;
	tmp2->next = tmp->next;
	tmp->next = tmp2;
}

void sadd(SList *head, int value)
{
	if (head->next == NULL)
	{
		SList *tmp = new SList;
		tmp->value = value;
		tmp->next = NULL;
		head->next = tmp;
	}
	else if (value > sreturnValue(head, slengh(head)))
	{
		SList *tmp = head;
		for (int i = 0; i < slengh(head); i++)
			tmp = tmp->next;
		createEl(tmp, value);
	}
	else
	{
		SList *tmp = head;
		while (true)
		{
			if ((tmp->value <= value) && (tmp->next->value >= value))
				break;
			tmp = tmp->next;
		}
		createEl(tmp, value);
	}
}

void sdel(SList *head, int num)
{
	if (num > 0)
	{
		int k = 1;
		SList *tmp = head;
		while ((k < num) && (tmp->next->next))
		{
			tmp = tmp->next;
			k++;
		}
		SList *tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		delete tmp2;
	}

}

void sdelv(SList *head, int value)
{
	SList *tmp = head;
	while ((value != tmp->next->value) && (tmp->next->next))
		{
			tmp = tmp->next;
		}
	SList *tmp2 = tmp->next;
	tmp->next = tmp->next->next;
	delete tmp2;
}

void sprintList(SList *head)
{
	SList *tmp = head;
	while(tmp->next)
	{
		tmp = tmp->next;
		printf("%i ", tmp->value);
	}
}

void sremoveList(SList *head)
{
	while (head->next != NULL)
	sdel(head, 1);
}