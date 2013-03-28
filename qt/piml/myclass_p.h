#ifndef MYCLASS_P_H
#define MYCLASS_P_H

#include <QtGlobal>
#include <private/qobject_p.h>
#include "myclass.h"

class MyClassPrivate : QObjectPrivate
{
    Q_DECLARE_PUBLIC(MyClass)
public:
    MyClassPrivate();
    void function();

    void hello();

private:
//    friend class MyClassPrivate;
};

#endif // MYCLASS_P_H
