#include <stdafx.h>
#include <stdlib.h>

int numElem(char s[])
{
	int k = 0;
	while(s[k] != '\0')
	{
		k++;
	}
	return k;
}

int main(void)
{
	char s[100];
	char s1[100];
	printf("Enter strings S and S1, will be found the number of occurrences of S1 in S as a substring. \n String S: ");
	scanf("%s", &s);
	printf("\n String S1: ");
	scanf("%s", &s1);
	
	int num = numElem(s);
	int num1 = numElem(s1);
		
	if (num >= num1)
	{
		int k = 0;
		int occurrences = 0;	
		for (int i = 0; i <= num - num1; i++)
		{
			k = 0;
			for (int j = 0; j < num1; j++)
			{
				if(s[i + j] == s1[j])
					k++;
			}
			if (k == num1)
				occurrences++;
		}

		printf("\n Number of occurrences: %i \n", occurrences);

	}
	else 
	{
		printf("\n Number of occurrences: 0 \n");
	}	
	
	system("PAUSE");
	return 0;
}

