#include <stdafx.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char s[100];
	printf("Enter a string, will be tested balance by brackets: \n");
	scanf("%s", &s);
	
	int k = 0;
	int i = 0;
	while ((s[i] != '\0') && (k != - 1))
	{
		if (s[i] == '(')
			k++;
		if (s[i] == ')')
			k--;
		i++;	
	}

	if (k == 0)
		printf("\n Balance by brackets is TRUE \n");
	else 
		printf("\n Balance by brackets is FALSE \n");


	system("PAUSE");
	return 0;
}