#include "test.h"

int main(void)
{
    Test test;
    QTest::qExec(&test);

    return 0;
}

