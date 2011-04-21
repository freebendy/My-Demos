#include "myclass_p.h"
#include <iostream>
using namespace std;

MyClassPrivate::MyClassPrivate()
{
}

void MyClassPrivate::function()
{
    cout << Q_FUNC_INFO << endl;
    Q_Q(MyClass);
    q->function();
}
