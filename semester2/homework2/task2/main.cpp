#include "stacktests.h"

int main()
{
    ArrayStackTests test1;
    QTest::qExec(&test1);
    PointStackTests test2;
    QTest::qExec(&test2);
}
