#include "testthread.h"
#include <QDebug>

TestThread::TestThread(QObject *parent) :
    QThread(parent)
{
}

void TestThread::onTaskAdd( int aNum )
{
    qDebug() << __PRETTY_FUNCTION__;
    qDebug() << "Thread id: " << QThread::currentThreadId();
    for ( int i = 0; i < aNum; ++i )
    {
        qDebug() << i;
    }
}

void TestThread::run()
{
    qDebug() << __PRETTY_FUNCTION__;
    qDebug() << "Thread id: " << QThread::currentThreadId();
    exec();
}
