#include <stdio.h>

class Error
{
public:
    Error()
    {
        printf("Throwing of exception\n");
    }
};

class A
{
public:
    A()
    {
        printf("Calling of constructor\n");
    }
    ~A()
    {
        printf("Calling of destructor\n");
    }
};

int main()
{
    try
    {
        A a;
        throw Error();
    }
    catch(Error)
    {
        printf("Exception handling\n");
    }
    
    return 0;
}
