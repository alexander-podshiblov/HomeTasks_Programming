#include "stdafx.h"

struct Node
{
	int value;
	Node *next;
};

int main()
{
	FILE *f = fopen("input.txt", "r");
	int n = 0;
	fscanf(f, "%i", &n);
	
	Node *s = new Node[n];
	for (int i = 0; i < n; i++)
	{
		s[i].value = i + 1;
		s[i].next = NULL;
	}

	while(!feof(f))
	{
		int a = 0;
		int b = 0;
		fscanf(f, "%i%i", &a, &b);
		s[a - 1].next = &s[b - 1];
	}

	fclose(f);

	for (int i = 3; i < n; i++)
	{
		Node *tmp = &s[i];
		while (tmp->next != NULL)
			tmp = tmp->next;
		printf("%i -> %i\n", i + 1, tmp->value);
	}
	
	scanf("%*");
	delete[] s; 
	return 0;
}