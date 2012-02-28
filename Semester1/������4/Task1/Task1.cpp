#include <stdafx.h>
#include "psort.h"
#include <string.h>

int main()
{
	char str1[100];
	char str2[100];
	
	scanf("%s100", &str1);
	scanf("%s100", &str2);

	int n = strlen(str1);
	
	if (n != strlen(str2))
	{
		printf("\nNO");
	}
	else
	{
		pSort(str1, n);
		pSort(str2, n);
		
		bool identical = true;
		for	(int i = 0; i < n && identical; i++)
			if (str1[i] != str2[i])
				identical = false;
		
		if (identical)
			printf("\nYES");
		else
			printf("\nNO");
	}


	scanf("%*s");
	return 0;
}