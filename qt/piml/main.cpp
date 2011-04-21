#include <QtCore/QCoreApplication>

#include "myclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClass obj;
    obj.function();

    return a.exec();
}
