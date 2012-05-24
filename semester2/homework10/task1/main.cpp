#include <QtGui/QApplication>
#include "game.h"
#include "test.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Game w;
    w.show();

    Test test;
    QTest::qExec(&test);


    return a.exec();
}
