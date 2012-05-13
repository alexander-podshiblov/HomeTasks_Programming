#include "plisttest.h"
#include "ulisttest.h"

int main()
{
    PointListTests test1;
    QTest::qExec(&test1);

    UListTests test2;
    QTest::qExec(&test2);
}
