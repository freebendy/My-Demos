#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <qglobal.h>
class MyClassPrivate;
class MyClass : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(MyClass)
public:
    MyClass(QObject *parent = 0);
    void function();

    void hello();

signals:

public slots:

private:
//    friend class MyClassPrivate;

};

#endif // MYCLASS_H
