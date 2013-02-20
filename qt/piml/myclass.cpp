#include "myclass.h"
#include "myclass_p.h"
#include <iostream>
using namespace std;

MyClass::MyClass(QObject *parent) :
    QObject(*new MyClassPrivate, parent)
{
}

void MyClass::function()
{
    cout << Q_FUNC_INFO << endl;
    Q_D(MyClass);
    d->hello();
}

void MyClass::hello()
{
    cout << Q_FUNC_INFO << endl;
}
