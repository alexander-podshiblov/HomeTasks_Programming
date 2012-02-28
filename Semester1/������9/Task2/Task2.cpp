#include "stdafx.h"
#include <string.h>

void copy(char *tmp, char *s, int m)
{
	for(int i = 0; i < m; i++)
		tmp[i] = s[i];
	tmp[m] = '\0';
}

unsigned long long maxP(const int p, int m)
{
	unsigned long long pPower = 1;
	for (int i = 1; i < m; i++)
	{
		pPower = pPower * p;
	}
	return pPower;
}

unsigned long long hashFunc(char *s, unsigned long long maxPower, const int p, int m)
{
	unsigned long long hash = 0;
	for (int i = 0; i < m; i++)
	{
		hash = hash + s[i] * maxPower;
		maxPower = maxPower / p;
	}
	return hash;
}

unsigned long long nextHash(char *s, unsigned long long predHash, const int p, int m, unsigned long long maxPower)
{
	unsigned long long nextHash = (predHash - s[- 1] * maxPower) * p + s[m - 1];
	return nextHash;
}

void printEntries(char *s, char *pattern, unsigned long long *hash, unsigned long long mainHash, int lenPattern, int entries)
{
	printf("Pattern ""%s"" enters into the string:\n", pattern);
	for (int i = 0; i < entries; i++)
	{
		if (hash[i] == mainHash)
			{
				char tmp[100];
				copy(tmp, s + i, lenPattern);
				if (strcmp(tmp, pattern) == 0)
					printf("%i to %i\n", i + 1, i + lenPattern);
			}
	}
}

int main()
{
	char pattern[100];
	char s[1000];
	FILE *f = fopen("input.txt", "r");
	fscanf(f, "%s%s", &pattern, &s);
	fclose(f);

	///////////////
	const int p = 59;
	const int lenPattern = strlen(pattern);
	const int lenS = strlen(s);
	unsigned long long maxPower = maxP(p, lenPattern);
	unsigned long long mainHash = hashFunc(pattern, maxPower, p, lenPattern);
	///////////////

	int entries = lenS - lenPattern + 1;
	unsigned long long *hash = new unsigned long long[entries];
	hash[0] = hashFunc(s, maxPower, p, lenPattern);

	for (int i = 1; i < entries; i++)
	{
		hash[i] = nextHash(s + i, hash[i - 1], p, lenPattern, maxPower);
	}
	
	printEntries(s, pattern, hash, mainHash, lenPattern, entries);

	scanf("%*");
	delete[] hash;
	return 0;
}