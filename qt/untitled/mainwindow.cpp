#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QDebug>
#include <QLabel>
#include "testthread.h"

#include <QFile>
#include <QTextStream>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mNetworkAccessManager.reset( new QNetworkAccessManager() );
    mTestThread.reset( new TestThread() );

    connect( this,
            SIGNAL( addTask(int) ),
            mTestThread.data(),
            SLOT( onTaskAdd(int) ),
            Qt::QueuedConnection );

    connect( ui->pushButton, SIGNAL( clicked() ), this, SLOT( onHttpButtonClicked() ) );
    mTestThread->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onHttpButtonClicked()
{
    qDebug() << __PRETTY_FUNCTION__;

    QStringList list;
    for ( int i = 0; i < 10000; ++i )
    {
        list<< QString::number( i );
    }

    // Solution1: not good.
    qint64 time1 = QDateTime::currentMSecsSinceEpoch();

    int tempCount = 0;
    QList<int> indexList;
    int count = list.count();
    while ( indexList.count() < count )
    {
        ++tempCount;
        int i = qrand() % list.count() ;
        if ( indexList.indexOf( i ) == -1 )
        {
            indexList.append( i );
        }
    }
    qint64 time2 = QDateTime::currentMSecsSinceEpoch();
    qDebug() << "1 -- tempCount: " << tempCount << "\ntime: " << time2 - time1;

    // Solution2: better.
//    qint64 time3 = QDateTime::currentMSecsSinceEpoch();
//    QStringList tempList;
//    while ( list.count() > 0 )
//    {
//        int i = qrand() % list.count() ;
//        tempList.append( list.takeAt( i ) );
//    }
//    qint64 time4 = QDateTime::currentMSecsSinceEpoch();
//    qDebug() << "2 -- time: " << time4 - time3;

    // Solution3: more better.
//    qint64 time5 = QDateTime::currentMSecsSinceEpoch();
//    int count = list.count();
//    int times = count;

//    for ( int i = 0; i < times; ++i )
//    {
//        int randIndex = qrand() % count ;
//        int cIndex = i % count;

//        if ( cIndex != randIndex )
//        {
//            qSwap( list[cIndex], list[randIndex] );
//        }
//    }
//    qint64 time6 = QDateTime::currentMSecsSinceEpoch();
//    qDebug() << "3 -- time: " << time6 - time5;

    QFile outFile( "random.txt");
    outFile.remove();
//    if ( outFile.open( QFile::WriteOnly | QFile::Text ) )
//    {
//        QTextStream textStream( &outFile );
//        textStream << tempList.join( "\n" );
//        textStream.flush();
//        outFile.close();
//    }

//    qDebug() << "Thread id: " << QThread::currentThreadId();
//    emit addTask( 1000 );
//    QNetworkRequest networkRequest;
//    networkRequest.setUrl( QUrl( "http://www.sina.com" ) );
//    mNetworkAccessManager->get( networkRequest );
}
