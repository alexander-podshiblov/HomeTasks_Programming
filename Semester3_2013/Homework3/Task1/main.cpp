#include <stdio.h>
#include "robograph.h"
#include "Test.h"

int main()
{
    Test test;
    QTest::qExec(&test);

    return 0;
}
