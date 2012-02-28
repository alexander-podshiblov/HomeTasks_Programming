#include <stdafx.h>
#include "stack.h"

int main()
{
	FILE *f = fopen("input.txt", "r");
	
	int n = 0;
	fscanf(f, "%i", &n);
	
	int m[100][100];
	for (int i = 0; i < n; i++)
		for (int j = 0; j< n; j++)
			fscanf(f, "%i", &m[i][j]);

	fclose(f);

	Stack *head = new Stack;
	head->value = 0;
	head->next = NULL;

	int *a = new int [n*n];
	int k = 0;
	while (k != n / 2)
	{
		for (int j = k; j < n - k; j++)
		{
			add(head, m[k][j]);
		}
		for (int i = k + 1; i < n - k; i++)
		{
			add(head, m[i][n - 1 - k]);
		}
		for (int j = n - 2 - k; j >= k; j--)
		{
			add(head, m[n - k - 1][j]);
		}
		for (int i = n - 2 - k; i > k; i--)
		{
			add(head, m[i][k]);
		}
		k++;
	}
	add(head, m[k][k]);

	
	f = fopen("output.txt", "w");
	while (!empty(head))
	{
		fprintf(f, "%i ", returnLast(head));
		del(head);
	}
	fclose(f);
	
	
	delete head;
	delete[] a;
	return 0;
}