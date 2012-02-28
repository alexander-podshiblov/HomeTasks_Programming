#include "stdafx.h"

int findMin(bool* visit, int* distance, int n)
{
	int min = 32001;
	int num = -1;
	for (int i = 0; i < n; i++)
		if ((distance[i] < min) && (!visit[i]))
		{
			min = distance[i];
			num = i;
		}
	if (min == 32001)
		return -1;
	else
		return num;
}

int main()
{
	FILE *f = fopen("input.txt", "r");
	int n = 0;
	int m = 0;
	fscanf(f, "%i", &n);
	fscanf(f, "%i", &m);
	int road[100][100];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			road[i][j] = -1;
	for (int i = 0; i < m; i++)
	{
		int x = 0;
		int y = 0;
		int len = 0;
		fscanf(f, "%i%i%i", &x, &y, &len);
		road[x-1][y-1] = len;
		road[y-1][x-1] = len;
	}
	fclose(f);

	///////////////
	
	bool *visit = new bool [n];
	for (int i = 0; i < n; i++)
		visit[i] = false;

	int *distance = new int [n];
	distance[0] = 0;
	for (int i = 1; i < n; i++)
		distance[i] = 32000;

	///////////////

	while (findMin(visit, distance, n) != -1)
	{
		int w = findMin(visit, distance, n);
		printf("%i ", w + 1);
		visit[w] = true;
		for (int v = 0; v < n; v++)
		{
			if ((!visit[v]) && (road[w][v] != -1))
				if (distance[v] > distance[w] + road[w][v])
				{
					distance[v] = distance[w] + road[w][v];
				}
		}
	}

	
	delete[] visit;
	delete[] distance;
	scanf("%*");
	return 0;
}

