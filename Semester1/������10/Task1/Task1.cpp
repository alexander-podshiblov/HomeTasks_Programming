#include "stdafx.h"
#include <string.h>

struct polynom
{
	int factor;
	int power;
	polynom *next;
};

void init(polynom *head)
{
	head->factor = 0;
	head->power = 0;
	head->next = NULL;
}

void addMonomial(polynom *head, int factor, int power)
{
	polynom *tmp = new polynom;
	tmp->factor = factor;
	tmp->power = power;
	polynom *tmp2 = head;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
}

void scanPolynom(polynom *head)
{
	printf("Enter a power of the polynom:");
	int power = 0;
	scanf("%i", &power);
	for (int i = power; i >= 0; i--)
	{
		int factor = 0;
		printf("Factor of X^%i = ", i);
		scanf("%i", &factor);
		if (factor != 0)
			addMonomial(head, factor, i);
	}
}

void print(polynom *head)
{
	printf("\n	");
	polynom *tmp = head->next;
	if (tmp != NULL)
	{
		printf("%iX^%i", tmp->factor, tmp->power);
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		if (tmp->factor > 0)
			printf("+%iX^%i", tmp->factor, tmp->power);
		else
			printf("%iX^%i", tmp->factor, tmp->power);
		tmp = tmp->next;
	}
}

void sum(polynom *head1, polynom *head2, polynom *head3)
{
	polynom *tmp1 = head1->next;
	polynom *tmp2 = head2->next;
	
	while ((tmp1 != NULL) || (tmp2 != NULL))
	{
		if ((tmp1 != NULL) && (tmp2 != NULL))
		{
			if (tmp1->power == tmp2->power)
			{
				addMonomial(head3, tmp1->factor + tmp2->factor, tmp1->power);
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}
			else if (tmp1->power > tmp2->power)
			{
				addMonomial(head3, tmp1->factor, tmp1->power);
				tmp1 = tmp1->next;
			}
			else if (tmp1->power < tmp2->power)
			{
				addMonomial(head3, tmp2->factor, tmp2->power);
				tmp2 = tmp2->next;
			}
		}
		else if ((tmp1 != NULL) && (tmp2 == NULL))
		{
			addMonomial(head3, tmp1->factor, tmp1->power);
			tmp1 = tmp1->next;
		}
		else if ((tmp1 == NULL) && (tmp2 != NULL))
		{
			addMonomial(head3, tmp2->factor, tmp2->power);
			tmp2 = tmp2->next;
		}
	}
}

bool equals(polynom *head1, polynom *head2)
{
	polynom *tmp1 = head1->next;
	polynom *tmp2 = head2->next;
	
	if (((tmp1 != NULL) && (tmp2 == NULL)) || ((tmp1 == NULL) && (tmp2 != NULL)))
		return false;
	
	while ((tmp1 != NULL) && (tmp2 != NULL))
	{
		if ((tmp1->factor != tmp2->factor) || (tmp1->power != tmp2->power))
		{
			return false;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return true;
}

int toPower(int a, int n)
{
	
	int residue = 0;
	int quotientN = n;
	long degreesA = a;
	long result = 1;

	while (quotientN >= 1)
	{
		if (quotientN == 1)
		{
			result = result * degreesA;
			quotientN = 0;
		}
		else
		{
			residue = quotientN % 2;
			quotientN = quotientN / 2;
			if (residue == 1)
				result = result * degreesA;
			degreesA = degreesA * degreesA;
		}
	}
	return result;
}

long long value(polynom *head, int x)
{
	long long value = 0;
	polynom *tmp = head->next;
	while (tmp != NULL)
	{
		value = value + tmp->factor * toPower(x, tmp->power);
		tmp = tmp->next;
	}
	return value;
}

void remove(polynom *head)
{
	if (head->next == NULL)
		delete head;
	else
		remove(head->next);
}

int main()
{
	polynom *head1 = new polynom;
	init(head1);
	polynom *head2 = new polynom;
	init(head2);
	polynom *head3 = new polynom;
	init(head3);
	////////////////////////////////////////
	printf("Polynom1:\n");
	scanPolynom(head1);
	printf("\n\nPolynom2:\n");
	scanPolynom(head2);
	printf("\n\n");


	char choice = 0;
	while (choice != '0')
	{
		printf("\n-----------------------------------------\n");
		printf("	0 - exit\n	1 - print polynom1\n	2 - print polynom2\n	3 - equals\n	4 - value\n	5 - sum polynom1 and polynom2\n	");
		scanf("%c", &choice);
			
		if (choice == '\n')
			scanf("%c", &choice);
		
		if (choice == '1')
		{
			print(head1);
		}
		if (choice == '2')
		{
			print(head2);
		}
		if (choice == '3')
		{
			if	(equals(head1, head2))
				printf("\n	YES\n");
			else
				printf("\n	NO\n");
		}
		if (choice == '4')
		{
			printf("\n	Enter X = ");
			int x = 0;
			scanf("%i", &x);
			print(head1);
			printf(" = %i\n", value(head1, x));
		}
		if (choice == '5')
		{
			sum(head1, head2, head3);
			print(head3);
		}
	}

	
	remove(head1);
	remove(head2);
	remove(head3);
	return 0;
}