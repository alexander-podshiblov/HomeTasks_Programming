#include "stdafx.h"
#include <string.h>

struct Word
{
	char s[250];
	int repeats;
	Word *next;
};

Word *createWord(char *s)
{
	Word *tmp = new Word;
	strcpy(tmp->s, s);
	tmp->repeats = 1;
	tmp->next = NULL;
	return tmp;
}

Word **createArray(const int lengthArray)
{
	Word **m = new Word *[lengthArray];
	for(int i = 0; i < lengthArray; i++)
		m[i] = NULL;
	return m;
}

unsigned int hashFunc(char *s, const int lengthArray)
{
	const int p = 59;
	unsigned long long pPower = 1;
	unsigned long long hash = 0;
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		hash = hash + s[i] * pPower;
		pPower = pPower * p;
	}
	return hash % lengthArray;
}

void delChain(Word *tmp)
{
	if (tmp->next == NULL)
	{
		delete tmp->next;
		tmp->next = NULL;
	}
	else
		delChain(tmp->next);

}

void clear(Word **m, const int lengthArray)
{
	for (int i = 0; i < lengthArray; i++)
	{
		if (m[i] != NULL)
		{
			delChain(m[i]);
		}
		delete m[i];
	}
}