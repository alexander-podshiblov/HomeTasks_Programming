#include <stdafx.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	printf("Enter the string will be checked whether it is polindromom. \n Your string: ");
	char s[100];
	scanf("%s", &s);
	
	int n = strlen(s);
	bool foundDifference = false;
	for (int i = 0; i < n / 2 && !foundDifference; i++)
	{
		if (s[i] != s[n - i - 1])
			foundDifference = true;
		
	}

	if (!foundDifference)
		printf("\n Yes \n");
	else
		printf("\n No \n");
	
	system("PAUSE");
	return 0;
}