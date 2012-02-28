#include "stdafx.h"
#include "double.h"





bool F(char *&s)
{
	if (*s == ' ' || *s == '\n' || *s == NULL)
		return false;
	else
		return doubl(s);
}

bool T(char *&s)
{
	if (!F(s))
		return false;
	while (*s == '*' || *s == '/')
    {
        s++;
		if (*s == '*' || *s == '/' || *s == '+' || *s == '-')
			return false;
        if (!F(s))
            return false;
    }
		return true;
}

bool E(char *&s)
{
	if (!T(s))
		return false;
	while (*s == '+' || *s == '-')
    {
        s++;
		if (*s == '+' || *s == '-')
			return false;
        if (!T(s))
            return false;
    }
	if (*s == NULL)
		return true;
	else
		return false;
}

int main()
{
	char s[100];
	scanf("%s", &s);
	char *z = s;
	if(E(z)) printf("YES");
	else printf("NO");
	scanf("%*");

	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}