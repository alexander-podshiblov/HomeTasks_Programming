#pragma once


struct Word
{
	char s[250];
	int repeats;
	Word *next;
};

Word *createWord(char *s);

Word **createArray(const int lengthArray);

unsigned int hashFunc(char *s, const int lengthArray);

void delChain(Word *tmp);

void clear(Word **m, const int lengthArray);