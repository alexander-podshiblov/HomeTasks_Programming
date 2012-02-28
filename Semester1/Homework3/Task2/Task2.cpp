#include <stdafx.h>
#include "clist.h"
#include <stdlib.h>
#include "list.h"

void fill(CList *head, int n)
{
	for (int i = 0; i < n; i++)
		add(head, i + 1, i);
}

int returnNum(CList *head, CList *tmp)
{
	if (tmp == head->next)
		return 1;
	else
	{
		CList *tmp2 = head->next;
		int k = 2;
		while (tmp2->next != tmp)
		{
			k++;
			tmp2 = tmp2->next;
		}
		return k;
	}
}

int main()
{
	CList *head = new CList;
	head->value = 0;
	head->next = NULL;
	printf("Counting - for every round of a cyclic list remove the k-th element, while not in the list will be only one. Enter the length of the list and number of the last element. Will be calculated the numbers of k before n!. \n\nn = ");
	int n = 0;
	scanf("%i", &n);
	printf("\nlast = ");
	int last = 0;
	scanf("%i", &last);
	
	long nFact = 1;
	for (int i = 1; i <= n; i++)
			nFact = nFact * i;

	List *lhead = new List;
	lhead->next = NULL;
	
	for (int k = 1; k <= nFact; k++)
	{
		fill(head, n);
		CList *tmp = head;
		while (lengh(head) != 1)
		{
			for (int c = 1; c < k; c++)
			{
				tmp = tmp->next;
			}
			del(head, returnNum(head, tmp->next));
		}
		if (tmp->next->value == last)
			ladd(lhead, k, 1000);
		del(head, 1);
	}

	printf("\n\nk = {");
	lprintList(lhead);
	printf("}\n");
	
	removeList(head);
	lremoveList(lhead);
	
	scanf("%*");

	delete lhead;	
	delete head;
	return 0;
}