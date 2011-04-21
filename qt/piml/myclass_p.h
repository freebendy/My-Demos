#ifndef MYCLASS_P_H
#define MYCLASS_P_H

#include <qglobal.h>
#include <private/qobject_p.h>

#include "myclass.h"

class MyClassPrivate : QObjectPrivate
{
    Q_DECLARE_PUBLIC(MyClass)
public:
    MyClassPrivate();
    void function();

private:
    friend class MyClassPrivate;
};

#endif // MYCLASS_P_H
