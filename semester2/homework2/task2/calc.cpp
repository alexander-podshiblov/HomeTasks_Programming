#include <stdio.h>
#include "calc.h"

int Calc::result(char *s)
{
    while (s[0] != '\0')
    {
        if ((s[0] >= '0') && (s[0] <= '9'))
        {
            int a = 0;
            int n = sscanf(s, "%i", &a);
            add(a);
            s = s + n;
        }
        if (s[0] == ' ')
            s++;
        else
        {
            int a = returnLast();
            del();
            if (s[0] == '+')
                add(a + returnLast());
            else if (s[0] == '-')
                add(a - returnLast());
            else if (s[0] == '*')
                add(a * returnLast());
            else if (s[0] == '/')
                add(returnLast() / a);
            s++;
        }
    }
    return returnLast();
}
